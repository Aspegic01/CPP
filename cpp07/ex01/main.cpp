#include "Iter.hpp"

template<typename T>
void print(T &element) {
    std::cout << element << std::endl;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::string stringArray[] = {"Hello", "World", "!"};

    std::cout << "Iterating over int array:" << std::endl;
    iter(intArray, 5, print<int>);

    std::cout << "Iterating over string array:" << std::endl;
    iter(stringArray, 3, print<std::string>);

    return 0;
}