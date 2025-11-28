/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:57:00 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/11/28 15:20:21 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int openfiles(const std::string& inputfile, const std::string& outputfile, std::ifstream& infile, std::ofstream& outfile)
{
    infile.open(inputfile.c_str());
    if (!infile.is_open())
    {
        std::cerr << "Error: Could not open input file " << inputfile << std::endl;
        return 1;
    }
    outfile.open(outputfile.c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error: Could not open output file " << outputfile << std::endl;
        infile.close();
        return 1;
    }
    return 0;
}

void read_and_replace(char * av[], std::ifstream& infile, std::ofstream& outfile)
{
    std::string to_find;
    std::string to_replace;
    to_find = av[2];
    to_replace = av[3];
    std::string line;
    while (std::getline(infile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(to_find, pos)) != std::string::npos)
        {
            line.erase(pos, to_find.length());
            line.insert(pos, to_replace);
            pos += to_replace.length();
        }
        outfile << line << std::endl;
    }
}

int main(int ac, char **av)
{
    std::string inputfile;
    std::string outputfile;
    std::ifstream infile;
    std::ofstream outfile;
    (void)ac;
    if(ac != 4)
    {
        std::cout << "Usage: " << av[0] << " <inputfile> <outputfile>" << std::endl;
        return 1;
    }
    inputfile = av[1];
    outputfile = outputfile + av[1] + ".replace";
    if (openfiles(inputfile, outputfile, infile, outfile))
        return 1;
    read_and_replace(av, infile, outfile);
    infile.close();
    outfile.close();
    return 0;
}
