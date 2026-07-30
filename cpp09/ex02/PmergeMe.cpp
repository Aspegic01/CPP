#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& o) : _vec(o._vec), _deq(o._deq) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& o) {
    if (this != &o) { _vec = o._vec; _deq = o._deq; }
    return *this;
}
PmergeMe::~PmergeMe() {}

// --- Generic Ford-Johnson Sort ---
template <typename Container>
static void fordJohnsonSort(Container& arr) {
    if (arr.size() <= 1) return;

    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = hasStraggler ? arr.back() : 0;
    if (hasStraggler) arr.pop_back();

    // 1. Pair adjacent elements
    typedef std::pair<int, int> Pair;
    std::vector<Pair> pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1]) pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    // 2. Extract winners & sort recursively
    Container winners;
    for (size_t i = 0; i < pairs.size(); ++i)
    winners.push_back(pairs[i].first);
    fordJohnsonSort(winners);

    // 3. Reorder pairs to match sorted winners
    std::vector<Pair> sortedPairs;
    std::vector<bool> used(pairs.size(), false);
    for (size_t i = 0; i < winners.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (!used[j] && pairs[j].first == winners[i]) {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }

    // 4. Build main chain (b1, a1, a2, ..., an) and pend (b2, b3, ...)
    Container chain, pend;
    chain.push_back(sortedPairs[0].second);
    for (size_t i = 0; i < sortedPairs.size(); ++i) chain.push_back(sortedPairs[i].first);
    for (size_t i = 1; i < sortedPairs.size(); ++i) pend.push_back(sortedPairs[i].second);

    // 5. Generate Jacobsthal insertion indices
    std::vector<int> order;
    if (!pend.empty()) {
        order.push_back(0);
        std::vector<int> jn; jn.push_back(0); jn.push_back(1);
        while (jn.back() < static_cast<int>(pend.size()))
            jn.push_back(jn.back() + 2 * jn[jn.size() - 2]);
        
        for (size_t k = 3; k < jn.size(); ++k) {
            int high = std::min(jn[k], static_cast<int>(pend.size()));
            for (int i = high - 1; i >= jn[k - 1]; --i) order.push_back(i);
            if (high >= static_cast<int>(pend.size())) break;
        }
    }

    // 6. Binary insert pend elements into chain
    for (size_t i = 0; i < order.size(); ++i) {
        int val = pend[order[i]];
        int winner = sortedPairs[order[i] + 1].first;
        typename Container::iterator limit = std::find(chain.begin(), chain.end(), winner);
        typename Container::iterator pos = std::lower_bound(chain.begin(), limit, val);
        chain.insert(pos, val);
    }

    if (hasStraggler)
        chain.insert(std::lower_bound(chain.begin(), chain.end(), straggler), straggler);

    arr = chain;
}

void PmergeMe::sortVec(std::vector<int>& arr) { fordJohnsonSort(arr); }
void PmergeMe::sortDeq(std::deque<int>& arr)  { fordJohnsonSort(arr); }

// --- Parsing & Execution ---
void PmergeMe::parseAndSort(int ac, char **av) {
    for (int i = 1; i < ac; ++i) {
        std::string arg = av[i];
        if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
            throw std::runtime_error("Error");
        long val = std::atol(arg.c_str());
        if (val <= 0 || val > 2147483647) throw std::runtime_error("Error");
        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }

    std::cout << "Before:";
    for (size_t i = 0; i < _vec.size(); ++i) std::cout << " " << _vec[i];
    std::cout << "\n";

    clock_t start = clock();
    sortVec(_vec);
    double vTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1e6;

    start = clock();
    sortDeq(_deq);
    double dTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1e6;

    std::cout << "After:";
    for (size_t i = 0; i < _vec.size(); ++i) std::cout << " " << _vec[i];
    std::cout << "\n" << std::fixed << std::setprecision(5)
              << "Time to process a range of " << _vec.size() << " elements with std::vector : " << vTime << " us\n"
              << "Time to process a range of " << _deq.size() << " elements with std::deque  : " << dTime << " us\n";
}