#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <utility>
#include <stdexcept>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
: _vec(other._vec), _deq(other._deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// Generate Jacobsthal-based insertion order (0-indexed)
std::vector<size_t> PmergeMe::_jacobsthalOrder(size_t n) {
    std::vector<size_t> order;
    if (n == 0) return order;

    order.push_back(0);
    if (n == 1) return order;

    size_t prev2 = 0;
    size_t prev1 = 1;

    while (true) {
        size_t jk = prev1 + 2 * prev2;
        size_t start = (jk < n) ? jk : n;

        for (size_t i = start; i > prev1; i--)
            order.push_back(i - 1);

        if (jk >= n) break;
        prev2 = prev1;
        prev1 = jk;
    }

    return order;
}

// -----------------------------------------------------------------------------
// std::vector Implementation
// -----------------------------------------------------------------------------
void PmergeMe::_sortVector(std::vector<int>& arr) {
    if (arr.size() <= 1) return;

    // STEP 1: Handle odd element (straggler)
    bool isOdd = (arr.size() % 2 != 0);
    int straggler = isOdd ? arr.back() : 0;

    // STEP 2: Pair up elements (larger, smaller)
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] >= arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    // STEP 3: Extract larger elements and recursively sort them
    std::vector<int> largers;
    for (size_t i = 0; i < pairs.size(); i++)
        largers.push_back(pairs[i].first);

    _sortVector(largers);

    // STEP 4: Build Main Chain and Pend
    std::vector<int> mainChain;
    std::vector<int> pend;
    std::vector<bool> used(pairs.size(), false); // Cleaner than erasing elements

    for (size_t i = 0; i < largers.size(); i++) {
        mainChain.push_back(largers[i]);
        
        // Find the matching pair to get the 'smaller' (pend) element
        for (size_t j = 0; j < pairs.size(); j++) {
            if (!used[j] && pairs[j].first == largers[i]) {
                pend.push_back(pairs[j].second);
                used[j] = true;
                break;
            }
        }
    }

    // Insert the first pend element at the beginning (it's strictly smaller than mainChain[0])
    mainChain.insert(mainChain.begin(), pend[0]);

    // Track the position of each winner in mainChain to bound our binary searches
    std::vector<size_t> winnerPos;
    for (size_t i = 0; i < pend.size(); i++)
        winnerPos.push_back(i + 1);

    // STEP 5: Insert remaining pend elements using Jacobsthal order
    std::vector<size_t> order = _jacobsthalOrder(pend.size());
    for (size_t i = 0; i < order.size(); i++) {
        size_t idx = order[i];
        if (idx == 0 || idx >= pend.size()) continue; // Skip the first one, already inserted

        int val = pend[idx];

        // Bounded binary search
        std::vector<int>::iterator bound = mainChain.begin() + winnerPos[idx];
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), bound, val);

        size_t insertPos = pos - mainChain.begin();
        mainChain.insert(pos, val);

        // Shift winner positions to the right if they were affected by the insertion
        for (size_t j = 0; j < winnerPos.size(); j++) {
            if (winnerPos[j] >= insertPos)
                winnerPos[j]++;
        }
    }

    // STEP 6: Insert the straggler if we had one
    if (isOdd) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}

// -----------------------------------------------------------------------------
// std::deque Implementation
// -----------------------------------------------------------------------------
void PmergeMe::_sortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) return;

    // STEP 1: Handle odd element (straggler)
    bool isOdd = (arr.size() % 2 != 0);
    int straggler = isOdd ? arr.back() : 0;

    // STEP 2: Pair up elements (larger, smaller)
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] >= arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    // STEP 3: Extract larger elements and recursively sort them
    std::deque<int> largers;
    for (size_t i = 0; i < pairs.size(); i++)
        largers.push_back(pairs[i].first);

    _sortDeque(largers);

    // STEP 4: Build Main Chain and Pend
    std::deque<int> mainChain;
    std::deque<int> pend;
    std::vector<bool> used(pairs.size(), false);

    for (size_t i = 0; i < largers.size(); i++) {
        mainChain.push_back(largers[i]);
        
        for (size_t j = 0; j < pairs.size(); j++) {
            if (!used[j] && pairs[j].first == largers[i]) {
                pend.push_back(pairs[j].second);
                used[j] = true;
                break;
            }
        }
    }

    mainChain.push_front(pend[0]);

    std::vector<size_t> winnerPos;
    for (size_t i = 0; i < pend.size(); i++)
        winnerPos.push_back(i + 1);

    // STEP 5: Insert remaining pend elements using Jacobsthal order
    std::vector<size_t> order = _jacobsthalOrder(pend.size());
    for (size_t i = 0; i < order.size(); i++) {
        size_t idx = order[i];
        if (idx == 0 || idx >= pend.size()) continue;

        int val = pend[idx];

        std::deque<int>::iterator bound = mainChain.begin() + winnerPos[idx];
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), bound, val);

        size_t insertPos = pos - mainChain.begin();
        mainChain.insert(pos, val);

        for (size_t j = 0; j < winnerPos.size(); j++) {
            if (winnerPos[j] >= insertPos)
                winnerPos[j]++;
        }
    }

    // STEP 6: Insert the straggler
    if (isOdd) {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}

// -----------------------------------------------------------------------------
// Main Execution
// -----------------------------------------------------------------------------
void PmergeMe::sortAndBenchmark(int argc, char **argv) {
    // Parse and validate arguments
    for (int i = 1; i < argc; i++) {
        char *endptr;
        long val = std::strtol(argv[i], &endptr, 10);
        
        if (*endptr != '\0' || endptr == argv[i] || val < 0 || val > INT_MAX) {
            throw std::runtime_error("Error: Invalid argument detected.");
        }
        
        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }
    
    if (_vec.empty())
        throw std::runtime_error("Error: No numbers provided.");

    // Print before
    std::cout << "Before:";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << " " << _vec[i];
    std::cout << "\n";

    // Sort and measure time for Vector
    clock_t t1 = clock();
    _sortVector(_vec);
    clock_t t2 = clock();

    // Sort and measure time for Deque
    clock_t t3 = clock();
    _sortDeque(_deq);
    clock_t t4 = clock();

    // Print after
    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << " " << _vec[i];
    std::cout << "\n";

    // Print times
    double timeVec = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC * 1000000;
    double timeDeq = static_cast<double>(t4 - t3) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << timeVec << " us\n";
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : " << timeDeq << " us\n";
}
