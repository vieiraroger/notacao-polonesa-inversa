#include <cstdlib>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct char_stack{
	char value;
	char_stack *last;
};

struct double_stack{
	double value;
	double_stack *last;
};

char_stack *newStackChar();
//add an operator to stack
char_stack *addStackChar(char_stack *stack,char op);

//remove the last element from the stack
char_stack *removeStackChar(char_stack *stack);

//say if one stack is empty or not
bool isStackEmptyChar(char_stack *stack);

double_stack *newStackDouble();

//say if one stack is empty or not
bool isStackEmptyDouble(double_stack *stack);

//add an double to stack
double_stack *addStackDouble(double_stack *stack,double value);

//remove the last element from the stack
double_stack *removeStackDouble(double_stack *stack);
