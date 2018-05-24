//Nathaniel McDonald
//CSCE A311 Assignment 1
//
//This program allows the user to enter a RPN expression to be evaluated
//then outputs the result
//

#pragma once

class OperationNode
{
public:
	OperationNode();
	OperationNode(int character, OperationNode* next);
	OperationNode* getNext();
	int getOp();
private:
	int operand;
	OperationNode* next;
};