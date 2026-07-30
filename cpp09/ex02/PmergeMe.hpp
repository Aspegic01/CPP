#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <stdexcept>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int>  _deq;

public:
    // Orthodox Canonical Form
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    // Sorting functions for specific containers
    void sortVec(std::vector<int>& arr);
    void sortDeq(std::deque<int>& arr);

    // Parse arguments and run the complete benchmark
    void parseAndSort(int ac, char** av);
};

#endif // PMERGEME_HPP