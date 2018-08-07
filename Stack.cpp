#include "Stack.h"

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
		cout << "ERROR in removeStack()" << endl;
		system("pause");
	}
	return stack;
}

bool isStackEmptyDouble(double_stack *stack) {
	return stack == NULL;
}
