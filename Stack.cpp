#include "Stack.hpp"

char_stack *newStackChar() {
	char_stack *stack = NULL;

	return stack;
}


bool isStackEmptyChar(char_stack *stack) {
	return (stack == NULL);
}

char_stack *addStackChar(char_stack *stack,char op) {
	
	char_stack *new_stack = new char_stack;
	new_stack->last = stack;
	new_stack->value = op;


	return new_stack;
}

char_stack *removeStackChar(char_stack *stack) {
	if(!isStackEmptyChar(stack)) {
		char_stack *aux = stack;
		stack = stack->last;
		delete(aux);
		
	} else {
		cout << "ERROR removeStack()" << endl;
		system("pause");
	}
	return stack;
}

bool testOperator(char_stack *stack, char op) {
	//gambiarra BR from Brazil
	//for doenst call valueOperator(NULL)
	if(isStackEmptyChar(stack)) {
		return false;
	}
	int value = valueOperator(op);
	return value > valueOperator(stack->value) || value == 0;
}

int valueOperator(char op) {
	
	switch(op) {
		case ')':
			return -1; //remove the stack until '('
		case '+':
		case '-':
			return 1;

		case '*':
		case '/':
			return 2;

		case '^':
			return 3;

		case '(':
			return 0;

		default:
			cout << "error in valueOperator()  " << op <<endl;
			system("pause");
			return -1;	
	}
}

double_stack *newStackDouble() {
	double_stack *stack = NULL;

	return stack;
}

double_stack *addStackDouble(double_stack *stack,double value) {
	double_stack *new_stack = new double_stack;
	new_stack->last = stack;
	new_stack->value = value;


	return new_stack;
}

double_stack *removeStackDouble(double_stack *stack) {

	if(!isStackEmptyDouble(stack)) {
		double_stack *aux = stack;
		stack = stack->last;
		delete(aux);
		
	} else {
		cout << "ERROR removeStack()" << endl;
		system("pause");
	}
	return stack;
}

bool isStackEmptyDouble(double_stack *stack) {
	return stack == NULL;
}
