/* Copyright (C)
 *
 * 2013 - Chen Junshi
 * This program belongs to ACSA of USTC.
 */

#ifndef _QUEEN_STACK_HH_
#define _QUEEN_STaCK_HH_

#include <vector>


/**
 * A Static Stack used to restore the placement of Queens.
 *
 * The nth element in stack indicates the placement of
 * the nthqueen in the nth line.
 */
class QueenStack
{
public:
	QueenStack(const int num_queens);
	~QueenStack();

	/**
	 * Push data into stack
	 *
	 * @param value data
	 *
	 * @return	true	push success
	 *			flase	stack is full
	 */
	bool push(const int value);

	/**
	 * Pop data from stack
	 *
	 * @param data the poped data
	 * @return the poped data
	 */
	bool pop(int &data);

	/**
	 * Clean the stack
	 */
	void clean();

	/**
	 * Is stack full?
	 *
	 * @return stack is full or not
	 */
	bool isFull();

	bool isEmpty();

	const int getCurrentIdx() const { return currentIdx; }

	const int getValueAt(const int idx) const;

private:
	const int queens_num;

private:
	/**
	 * First empty place of stack.
	 */
	int currentIdx;

	/**
	 * Pointer to the stack.
	 */
	std::vector<int> *stack;
};

inline bool
QueenStack::isFull()
{
	return currentIdx == queens_num;
}

inline bool
QueenStack::isEmpty()
{
	return currentIdx == 0;
}

inline void
QueenStack::clean()
{
	currentIdx = 0;
}

#endif	// _QUEEN_STACK_HH_
