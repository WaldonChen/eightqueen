#include <iostream>
#include <iomanip>
#include <iterator>
#include <cstdlib>
#include <cstring>

#include "queen_stack.hh"

/**
 * Whether Queen(xa, ya) and Queen(xb, yb) reside in right place.
 *
 * @param xa
 * @param ya
 * @param xb
 * @param yb
 *
 * @return true or false
 */
inline bool
isValid(int xa, int ya, int xb, int yb)
{
	if (ya == yb) {
		return false;
	}
	if ((yb - ya) == (xb - xa)) {
		return false;
	}
	if ((xa + ya) == (xb + yb)) {
		return false;
	}
	return true;
}

/**
 * Whether current placement of queens reside in right place.
 *
 * @param stack placement of queens
 *
 * @return 
 */
bool
isChessValid(const QueenStack &stack)
{
	int i = 0, idx = 0, idx_value;

	idx = stack.getCurrentIdx() - 1;
	if (idx < 1) {
		return true;
	}
	idx_value = stack.getValueAt(idx);
	for (i = 0; i < idx; ++i)
	{
		if (!isValid(i, stack.getValueAt(i), idx, idx_value))
		{
			return false;
		}
	}
	return true;
}

/**
 * Print placement of queens.
 *
 * @param stack
 */
void
printStack(const QueenStack &stack)
{
	int i = 0;

	for (i = 0; i < stack.getCurrentIdx(); ++i)
	{
		int data = stack.getValueAt(i);
		std::cout << "(" << std::setw(2) << i
				<< "," << std::setw(2) << data << ") ";
	}

	std::cout << std::endl;
}

inline void printStack(const QueenStack &stack, int nth)
{
	std::cout << std::setw(6) << nth << ": ";
	printStack(stack);
}

int
queens(int queens_num)
{
	int i = 0, j = 1;
	QueenStack *pStack = NULL;

	if (queens_num <= 0)
	{
		return -1;
	}

	pStack = new QueenStack(queens_num);

	pStack->push(0);
	bool force_pop = false;
	while(!pStack->isEmpty())
	{
		if (!force_pop && isChessValid(*pStack)) {
			if (pStack->isFull()) {
				// Find a solution
				printStack(*pStack, j++);
				// Continue to find another solution.
				force_pop = true;
			} else {
				// Puts a new Queen.
				pStack->push(0);
				force_pop = false;
			}
		}
		else {
			int pop_data = -1;
			// Last Queen was invaliable.
			pStack->pop(pop_data);
			pop_data++;
			if (pop_data > queens_num - 1) {
				// Current solution is invaliable, backtrack.
				force_pop = true;
			} else {
				// Put last Queen a new place.
				pStack->push(pop_data);
				force_pop = false;
			}
		}
	}

	if (pStack != NULL)
	{
		delete pStack;
	}
}


int main(int argc, const char *argv[])
{
	int i = 0;
	int num_queens = 0;

	if (argc < 2)
	{
		std::cerr << "Usage:" << std::endl
			<< "\t" << argv[0] << " <queens number>"
			<< std::endl;
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < strlen(argv[1]); ++i)
	{
		if (!isdigit(argv[1][i]))
		{
			std::cerr << "\033[31mWrong queens number!\033[0m" << std::endl;
			exit(EXIT_FAILURE);
		}
	}

	num_queens = atoi(argv[1]);

	if (num_queens > 30)
	{
		std::cout << "It may take a long time!" << std::endl;
		exit(EXIT_FAILURE);
	}

	queens(num_queens);
	exit(EXIT_SUCCESS);
}
