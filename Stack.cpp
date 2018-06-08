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


bool isStackEmpty(my_stack stack) {
	return stack.top == -1;
}

my_stack addStack(my_stack stack,char op) {
	stack.top++;
	stack.theStack[stack.top] = op;
	return stack;
}

my_stack removeStack(my_stack stack) {
	if(!isStackEmpty(stack)) {
		char op = stack.theStack[stack.top];
		stack.theStack[stack.top] = ' ';
		stack.top--;
	} else {
		cout << "ERROR removeStack()" << endl;
		system("pause");
	}
	return stack;
}

bool testOperator(my_stack stack, char op) {
	//gambiarra BR from Brazil
	//for doenst call valueOperator(NULL)
	if(isStackEmpty(stack)) {
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

my_stack newStack() {
	my_stack stack;
	stack.top = -1;

	return stack;
}
