#include "PmergeMe.hpp"
#include <iostream>
#include <exception>

int main(int argc, char **argv) {
    // Check if the user passed at least one number
    if (argc < 2) {
        std::cerr << "Error: No numbers provided. Usage: ./PmergeMe <positive integer sequence>" << std::endl;
        return 1;
    }

    try {
        PmergeMe sorter;
        sorter.sortAndBenchmark(argc, argv);
    } 
    catch (const std::exception& e) {
        // This will catch the invalid argument errors thrown from our class
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
