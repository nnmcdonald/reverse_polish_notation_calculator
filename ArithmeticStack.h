//Nathaniel McDonald
//CSCE A311 Assignment 1
//
//This program allows the user to enter a RPN expression to be evaluated
//then outputs the result
//

#pragma once
#include "OperationNode.h"

class ArithmeticStack
{
public:
	ArithmeticStack();
	void pop();
	void push(int operand);
	int topPop();
	OperationNode* getHdPtr();
private:
	OperationNode* hdPtr;
};