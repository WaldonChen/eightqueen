#include <iostream>
#include <cassert>
#include <stdexcept>

#include "queen_stack.hh"

QueenStack::QueenStack(const int num_queens)
	: queens_num(num_queens),
	  currentIdx(0),
	  stack(NULL)
{
	assert(num_queens > 0);
	stack = new std::vector<int>(num_queens);
	stack->resize(num_queens);
}

QueenStack::~QueenStack()
{
	if (stack != NULL)
	{
		delete stack;
	}
}

bool
QueenStack::push(const int value)
{
	if (isFull()) {
		return false;
	}
#ifndef NDEBUG
	std::cout << "push (" << currentIdx << ", "
				<< value << ")" << std::endl;
#endif
	(*stack)[currentIdx++] = value;

	return true;
}

bool
QueenStack::pop(int &data)
{
	if (isEmpty()) {
		return false;
	}
	currentIdx--;
	data = (*stack)[currentIdx];
#ifndef NDEBUG
	std::cout << "pop (" << currentIdx << ", "
			<< data << ")" << std::endl;
#endif
	return true;
}



const int
QueenStack::getValueAt(const int idx) const
{
	if (idx < 0 || idx >= queens_num) {
		throw std::out_of_range("QueenStack::getValueAt(): index out of range");
	}

	return (*stack)[idx];
}
