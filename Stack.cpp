#include "Stack.hpp"


/* 
+ and -
/ and *
^
()
*/

/* 

int top;
char theStack[100];

*/


bool isStackEmptyChar(char_stack stack) {
	return stack.top == -1;
}

char_stack addStackChar(char_stack stack,char op) {
	stack.top++;
	stack.theStack[stack.top] = op;
	return stack;
}

char_stack removeStackChar(char_stack stack) {
	if(!isStackEmptyChar(stack)) {
		char op = stack.theStack[stack.top];
		stack.theStack[stack.top] = ' ';
		stack.top--;
	} else {
		cout << "ERROR removeStack()" << endl;
		system("pause");
	}
	return stack;
}

bool testOperator(char_stack stack, char op) {
	//gambiarra BR from Brazil
	//for doenst call valueOperator(NULL)
	if(isStackEmptyChar(stack)) {
		return true;
	}
	int value = valueOperator(op);
	return value > valueOperator(stack.theStack[stack.top]) || value == 0;
}

int valueOperator(char op) {
	
	switch(op) {
		case ')':
			return -1; //remove the stack until '('
		case '+':
		case '-':
			return 1;

		case '*':
			return 2;
			return 2;

		case '^':
		case '/':
			return 3;

		case '(':
			return 0;

		default:
			cout << "error in valueOperator()  " << op <<endl;
			system("pause");
			return -1;	
	}
}

char_stack newStackChar() {
	char_stack stack;
	stack.top = -1;

	return stack;
}

double_stack newStackDouble() {
	double_stack stack;
	stack.top = -1;

	return stack;
}

double_stack addStackDouble(double_stack stack,double value) {
	stack.top++;
	stack.theStack[stack.top] = value;
	return stack;
}

double_stack removeStackDouble(double_stack stack) {

	if(!isStackEmptyDouble(stack)) {
		stack.theStack[stack.top] = 0;
		stack.top--;
	} else {
		cout << "ERROR removeStack()" << endl;
		system("pause");
	}

	return stack;
}

bool isStackEmptyDouble(double_stack stack) {
	return stack.top == -1;
}
