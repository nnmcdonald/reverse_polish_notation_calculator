//Nathaniel McDonald
//CSCE A311 Assignment 1
//
//This program allows the user to enter a RPN expression to be evaluated
//then outputs the result
//

#pragma once
#include "ArithmeticStack.h"
#include "OperationNode.h"
#include <iostream>
#include <string>
//#include <math.h>
using namespace std;

//Checks user input for valid input
bool validOperand(char character)
{
	switch (character)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return true;
		break;
	default:
		return false;
		break;
	}
}

//checks user input for valid operators
bool validOperator(char character)
{
	switch (character)
	{
	case '/':
	case '-':
	case '*':
	case '+':
		return true;
		break;
	default:
		return false;
		break;
	}
}

int main()
{
	ArithmeticStack RPNCalc;
	string expression;
	bool quit = false;
	bool syntaxError = false;
	bool stackUnderflow = false;
	bool divideByZero = false;

	//Will run until the user chooses to quit
	while (!quit)
	{
		int num = 0;
		cout << "Please enter a RPN expression with operands seperated by a space." << endl;
		getline(cin, expression);
		
		//Loops through the expression
		for (int i = 0; i < expression.length(); i++)
		{
			//Pushes operators from the user input onto a stack and evaluates them when an operator is encountered
			if (expression[i] != ' ' && validOperand(expression[i]))
			{
				string operand = "";
				int j = 0;
				while (expression[i] != ' ' && validOperand(expression[i]))
				{
					operand = operand + expression[i];
					i++;
					j++;
				}
				i--;
				int k = 0;
				//Converts the operand to an int value
				for (j; j > 0; j--)
				{
					num = num + ((operand[j-1]-48) * (pow(10, k)));	
					k++;
				}
				RPNCalc.push(num);
				num = 0;
			}
			//Evaluates top two values on the stack if an operator is encountered
			else if (expression[i] != ' ' && validOperator(expression[i]))
			{
				int operandB = 0;
				int operandA = 0;
				if (RPNCalc.getHdPtr()->getNext() != nullptr)
				{
					operandB = RPNCalc.topPop();
					operandA = RPNCalc.topPop();
					switch (expression[i])
					{
					case '/':
						if (operandB != 0)
							num = operandA / operandB;
						else
							divideByZero = true;
						break;
					case '-':
						num = operandA - operandB;
						break;
					case '*':
						num = operandA*operandB;
						break;
					case '+':
						num = operandA + operandB;
						break;
					}
					RPNCalc.push(num);
					num = 0;
				}
				else
				{
					//stackUnderflow is true if there are not enough operands
					stackUnderflow = true;
					i = expression.length();
				}
			}
			//Evaluates top value on the stack if "sqrt" is entered
			else
			{
				if (expression[i] == 's')
				{
					if (expression[i + 1] == 'q' && expression[i + 2] == 'r' && expression[i + 3] == 't')
					{
						int operand = RPNCalc.topPop();
						num = (int)sqrt(operand);
						RPNCalc.push(num);
						num = 0;
						i += 3;
					}
					else
					{
						syntaxError = true;
						i = expression.length();
					}
				}
				else if (expression[i] != ' ')
				{
					syntaxError = true;
					i = expression.length();
				}
			}
		}

		if (syntaxError)
		{
			cout << "Syntax error, please only enter numbers and the operators : / + - * " << endl;
			while (RPNCalc.getHdPtr() != nullptr)
				RPNCalc.pop();
			syntaxError = false;
		}
		else if (stackUnderflow)
		{
			cout << "Error operators must be preceded by two operands." << endl;
			while (RPNCalc.getHdPtr() != nullptr)
				RPNCalc.pop();
			stackUnderflow = false;
		}
		else if (RPNCalc.getHdPtr()->getNext() != nullptr)
		{
			cout << "Error, too many operands." << endl;
			while (RPNCalc.getHdPtr() != nullptr)
				RPNCalc.pop();
		}
		else if (divideByZero)
		{
			cout << "Error, cannot divide by zero." << endl;
			while (RPNCalc.getHdPtr() != nullptr)
				RPNCalc.pop();
			divideByZero = false;
		}
		else if (RPNCalc.getHdPtr()->getNext() == nullptr)
		{
			bool done = false;
			string answer;
			cout << "The result is " << RPNCalc.getHdPtr()->getOp() << endl;
			RPNCalc.pop();
			
			//Prompts the user to enter another expression or quit
			while (!done)
			{
				cout << "Would you like to evaluate another expression? y/n" << endl;
				getline(cin, answer);

				if (answer == "n" || answer == "N")
				{
					quit = true;
					done = true;
				}
				else if (answer == "y" || answer == "Y")
					done = true;
				else
				{
					cout << "Please enter y for yes or n for no." << endl;
					done = false;
				}
			}
		}
	}

	system("pause");
}

