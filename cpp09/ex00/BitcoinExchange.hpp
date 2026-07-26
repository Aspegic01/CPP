#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
class BitcoinExchange {
private:
	std::map<std::string, float> _db;

	bool isValidDate(const std::string& date) const;
	bool isValidValue(const std::string& value) const;
	bool isValidLine(const std::string& line) const;
	bool isValidInputLine(const std::string& line) const;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange(const std::string& dbFilename);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();
	void loadDatabase(const std::string& filename);
	void processInput(const std::string& inputFilename) const;
};
