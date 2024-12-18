
#include "MutantStack.hpp"
#include <stack>
#include <iostream>
#include <string>
#include <list>
#include <cassert>
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define RESET   "\033[0m"


void test_empty_stack() {
	//instance MutantStack
	MutantStack<int> mstack;
	std::cerr << RED;
	assert(mstack.empty() && "test_empty_stack: FAILED: Stack should be empty initially.");
	assert(mstack.size() == 0 && "test_empty_stack: FAILED: Size should be 0 initially.");
    std::cout << GREEN << "test_empty_stack: PASSED" << RESET<< std::endl;
}

void test_add_elements() {
	MutantStack<int> mstack;
	//Init mutant stack
	mstack.push(10);
	mstack.push(15);
	
	std::cerr << RED;
	assert(!mstack.empty() && "test_add_elements: FAILED: Stack should not be empty after adding an element.");
	std::cout <<GREEN<< "test_add_elements: PASSED" <<RESET<< std::endl;
}

void test_add_elements_size() {
	MutantStack<int> mstack;
	std::stack<int> stack;
	//Init mutant stack
	mstack.push(10);
	mstack.push(20);
	mstack.push(10);
	//Init stack
	stack.push(10);
	stack.push(20);
	stack.push(10);
	
	std::cerr << RED;
	assert(!mstack.empty() && "test_add_elements_size: FAILED: Stack should not be empty after adding an element.");
	assert(mstack.size()== stack.size() && "test_add_elements_size: FAILED: Size should be 3.");
	assert(mstack.top() == stack.top() && "test_add_elements_size: FAILED: Last element should be 10.");
    std::cout << GREEN << "test_add_elements_size: PASSED" << RESET<< std::endl;
}

void test_pop_element() {
	MutantStack<int> mstack;
	//Init mutant stack
	mstack.push(15);
	mstack.pop();
	assert(mstack.empty() && "test_pop_element: FAILED: Stack should be empty after delete the element.");
	assert(mstack.size() == 0 && "test_pop_element: FAILED: Size should be 0 after delete the element.");

	mstack.push(15);
	mstack.push(10);
	mstack.pop();
	std::cerr << RED;
	assert(!mstack.empty() && "test_pop_element: FAILED: Stack should not be empty after adding an elements.");
	assert(mstack.top() == 15 && "test_pop_element: FAILED: The top value of the stack should be 15.");
	assert(mstack.size() == 1 && "test_pop_element: FAILED: Size should be 0 after removing 1 of 2 elements.");
    std::cout << GREEN << "test_pop_element: PASSED" << RESET<< std::endl;
}


void test_top_stack() {
	MutantStack<int> mstack;

	mstack.push(15);
	assert(!mstack.empty() && "test_top_stack: FAILED: Stack should not be empty after adding an elements.");
	assert(mstack.top() == 15 && "test_top_stack: FAILED: The top value of the stack should be 15.");
	mstack.push(17);
	assert(mstack.top() == 17 && "test_top_stack: FAILED: The top value of the stack should be 17.");
	std::cout << GREEN << "test_top_stack: PASSED" << RESET<< std::endl;
}


void test_iterator_stack() {
	MutantStack<int> mstack;
	std::list<int> lst;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	lst.push_back(5);
	lst.push_back(17);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::list<int>::iterator lstit = lst.begin();
	std::list<int>::iterator lstite = lst.end();
	++it;
	--it;

	while (it != ite && lstit != lstite) {
		assert(*it ==  *lstit && "test_top_stack: FAILED: The values ​​contained in the stack are different from those in the list.");
		++it;
		++lstit;
	}
	std::cout << GREEN << "test_iterator_stack: PASSED" << RESET<< std::endl;

}

void test_copy_stack() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::stack<int> stack(mstack);
	assert(!stack.empty() && "test_copy_stack: FAILED: Stack should not be empty after adding an element.");
	assert(mstack.size() == stack.size() && "test_copy_stack: FAILED: The size of the stack and the mutant should be equal.");
	assert(mstack.top() == 17 && "test_copy_stack: FAILED: The top value of the stack should be 17.");
	std::cout << GREEN << "test_copy_stack: PASSED" << RESET<< std::endl;
}

void test_build_within_type() {
	MutantStack<int> mstack(15);
	assert(mstack.size() == 15);
	mstack.push(5);
	assert(mstack.top() == 5);
}

void test_copy_constructor() {
	MutantStack<int> mstack;
	mstack.push(5);
	MutantStack<int> copystack(mstack);
	assert(copystack.size() == mstack.size());
	assert(copystack.top() == mstack.top());

}

void test_assignment_op() {
	MutantStack<int> mstack;
	MutantStack<int> copystack;
	mstack.push(5);
	copystack = mstack;
	assert(copystack.size() == mstack.size());
	assert(copystack.top() == mstack.top());

}

int main() {

	test_empty_stack();
	test_add_elements();
	test_add_elements_size();
	test_pop_element();
	test_top_stack();
	test_iterator_stack();
	test_copy_stack();
	test_build_within_type();
	test_copy_constructor();
	test_assignment_op();
	return 0;
}
