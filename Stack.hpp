#include <cstdlib>
#include <iostream>
#include <stdlib.h>

using namespace std;

/* 
1 -> + and -
2 -> / and *
3 -> ^
4 -> () //restart to 0

*/

typedef struct stack{
	int top;
	char theStack[100];
}char_stack;

typedef struct stack2{
	int top;
	double theStack[100];
}double_stack;

//add an operator to stack
char_stack addStackChar(char_stack stack,char op);

//remove the last element from the stack
char_stack removeStackChar(char_stack stack);

//say if one stack is empty or not
bool isStackEmptyChar(char_stack stack);

//test if the operator is greater than the stack
//return true if yes
//return false if not
bool testOperator(char_stack stack, char op);

//return the value of priority of an operator
int valueOperator(char op);

char_stack newStackChar();
double_stack newStackDouble();


//say if one stack is empty or not
bool isStackEmptyDouble(double_stack stack);

//add an double to stack
double_stack addStackDouble(double_stack stack,double value);

//remove the last element from the stack
double_stack removeStackDouble(double_stack stack);