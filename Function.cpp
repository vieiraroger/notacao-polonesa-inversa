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

	}*/

	return exp;
}


bool isOperator(char c) {
	switch(c) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '(':
			return true;
			
		default: return false;
	}
}
