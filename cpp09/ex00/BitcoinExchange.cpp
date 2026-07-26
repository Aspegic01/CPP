#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &file)
{
    loadDatabase(file);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _db = other._db;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }

    int y = atoi(date.substr(0,4).c_str());
    int m = atoi(date.substr(5,2).c_str());
    int d = atoi(date.substr(8,2).c_str());

    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if ((y%4==0 && y%100!=0) || y%400==0)
        days[1]=29;

    return (y>=2009 && m>=1 && m<=12 && d>=1 && d<=days[m-1]);
}

bool BitcoinExchange::isValidValue(const std::string &value) const
{
    char *end;
    strtod(value.c_str(), &end);
    return (*end == '\0');
}

bool BitcoinExchange::isValidLine(const std::string &line) const
{
    size_t pos = line.find(',');
    if (pos == std::string::npos)
        return false;
    return isValidDate(line.substr(0,pos)) &&
           isValidValue(line.substr(pos+1));
}

bool BitcoinExchange::isValidInputLine(const std::string &line) const
{
    size_t pos = line.find(" | ");
    if (pos == std::string::npos)
        return false;
    return isValidDate(line.substr(0,pos)) &&
           isValidValue(line.substr(pos+3));
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());

    if (!file)
        throw std::runtime_error("Error: could not open database.");

    std::string line;
    std::getline(file,line);

    while (std::getline(file,line))
    {
        if (!isValidLine(line))
            continue;

        size_t pos = line.find(',');
        _db[line.substr(0,pos)] = atof(line.substr(pos+1).c_str());
    }
}

void BitcoinExchange::processInput(const std::string &filename) const
{
    std::ifstream file(filename.c_str());

    if (!file)
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file,line);

    while (std::getline(file,line))
    {
        if (!isValidInputLine(line))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        size_t pos = line.find(" | ");

        std::string date = line.substr(0,pos);
        float value = atof(line.substr(pos+3).c_str());

        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string,float>::const_iterator it = _db.lower_bound(date);

        if (it == _db.end() || it->first != date)
        {
            if (it == _db.begin())
            {
                std::cerr << "Error: no rate found." << std::endl;
                continue;
            }
            --it;
        }

        std::cout << date << " => "
                  << value
                  << " = "
                  << value * it->second
                  << std::endl;
    }
}