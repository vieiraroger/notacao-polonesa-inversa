#include "Function.hpp"

string convertToPolonese(string exp) {

	//my_stack stack = new my_stack();

	/*
	//entrar no parenteses cetral
	int indexStart=-1, indexEnd=-1;
	for(int i=0;i<exp.size;i++) {

		if(exp[i] == "(") {
			indexStart = i;
		}

		if(exp[i] == ')') {
			indexEnd = i;
			string sub = exp.substr(indexStart,indexEnd);

		}

	}
	*/

	my_stack stack;
	stack = newStack();

	string polonese = "";
	for(int i=0;i<exp.size();i++) {
 		

		if(isOperator(exp[i])) {
			if(isStackEmpty(stack)) {
				stack = addStack(stack, exp[i]);
			}
			else if(testOperator(stack,exp[i])) {
				stack = addStack(stack, exp[i]);
			}
			else if(valueOperator(exp[i]) == -1) {
				while(stack.theStack[stack.top] != '(') {
					polonese += stack.theStack[stack.top];
					stack = removeStack(stack);
				}
				stack = removeStack(stack);
			}
			else {
				polonese += exp[i];
			}
		}
		//is a caracter or a number
		else {
			polonese += exp[i];
		}
	}

	while(!isStackEmpty(stack)) {
		polonese += stack.theStack[stack.top];
		stack = removeStack(stack);
	}

	return polonese;
}


bool isOperator(char c) {
	switch(c) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '(':
		case ')':
			return true;
			
		default: return false;
	}
}
