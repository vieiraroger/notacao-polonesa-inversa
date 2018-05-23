#include "Stack.hpp"


/* 
+ and -
/ and *
^
()
*/

bool isStackEmpty(my_stack stack) {

	if(stack.top == -1) {
		return true;
	}
	else {
		return false;
	}

}

bool testOperator(char op,my_stack stack) {
	int value = valueOperator(op);
	if(value > valueOperator(stack.theStack[stack.top]) || value == 0) {
		return true;
	}
	else {
		return false;
	}
}

int valueOperator(char op) {
	
	switch(op) {
		
		case '+':
		case '-':
			return 1;

		case '*':
			return 2;
			return 2;

		case '^':
			return 3;

		case '(':
			return 0;

		default:
			cout << "error in valueOperator()" << endl;
			system("pause");
			return -1;	
	}

}
