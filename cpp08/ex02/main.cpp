#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

int main() {
	std::cout << "=== Subject Tests ===" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << " (Expected: 17)" << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << " (Expected: 1)" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Elements in stack: ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << "\n" << std::endl;

	std::cout << "=== Reverse Iterator Test (Top to Bottom) ===" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite) {
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << "\n" << std::endl;

	std::cout << "=== Const Iterator Test ===" << std::endl;
	const MutantStack<int> const_stack(mstack);
	MutantStack<int>::const_iterator cit = const_stack.begin();
	std::cout << "First element via const: " << *cit << std::endl;
	std::cout << "\n";

	std::cout << "=== std::list Underlying Container Test ===" << std::endl;
	MutantStack<int, std::list<int> > list_stack;
	list_stack.push(10);
	list_stack.push(20);
	list_stack.push(30);

	for (MutantStack<int, std::list<int> >::iterator lit = list_stack.begin(); lit != list_stack.end(); ++lit) {
		std::cout << *lit << " ";
	}
	std::cout << "\n" << std::endl;

	return 0;
}
