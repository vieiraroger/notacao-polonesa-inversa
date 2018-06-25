#include "utils.hpp"

bool isDecimal(char c) {
	return (c >= '0' && c <= '9');
}

bool isCharacter(char c) {
	return ((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z'));
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

double calc(char op,double n1, double n2) {
	switch(op) {
		case '+':
			return n1 + n2;
		case '-':
			return n1 - n2;
		case '*':
			return n1*n2;
		case '/':
			return n1/n2;
		case '^':
			return pow(n1,n2);
	}
}