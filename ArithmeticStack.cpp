//Nathaniel McDonald
//CSCE A311 Assignment 1
//
//This program allows the user to enter a RPN expression to be evaluated
//then outputs the result
//

#pragma once
#include "ArithmeticStack.h"

ArithmeticStack::ArithmeticStack()
{
	hdPtr = nullptr;
}

//Removes the top value from the stack
void ArithmeticStack::pop()
{
	if (hdPtr->getNext() != nullptr)
	{
		OperationNode* temp = hdPtr;
		hdPtr = hdPtr->getNext();
		delete temp;
	}
	else
	{
		OperationNode* temp = hdPtr;
		hdPtr = nullptr;
		delete temp;
	}
}

//Pushes a new value onto the top of the stack
void ArithmeticStack::push(int operand)
{
	if (hdPtr == nullptr)
	{
		hdPtr = new OperationNode(operand, nullptr);
	}
	else
	{
		OperationNode* temp = new OperationNode(operand, hdPtr);
		hdPtr = temp;
	}
}

//Removes the top value from the stack and returns its value
int ArithmeticStack::topPop()
{
	int temp = hdPtr->getOp();
	pop();
	return temp;
}

OperationNode* ArithmeticStack::getHdPtr()
{
	return hdPtr;
}