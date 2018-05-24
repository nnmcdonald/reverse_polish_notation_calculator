//Nathaniel McDonald
//CSCE A311 Assignment 1
//
//This program allows the user to enter a RPN expression to be evaluated
//then outputs the result
//

#pragma once
#include "OperationNode.h"

OperationNode::OperationNode()
{
	operand = 0;
	next = nullptr;
}

OperationNode::OperationNode(int character, OperationNode* next) : operand(character), next(next)
{

}

OperationNode* OperationNode::getNext()
{
	return next;
}

int OperationNode::getOp()
{
	return operand;
}