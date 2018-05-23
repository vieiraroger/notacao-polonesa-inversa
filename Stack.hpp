#include <cstdlib>
#include <iostream>
#include <stdlib.h>

using namespace std;

/* 
0 -> + and -
1 -> / and *
2 -> ^
3 -> () //restart to 0
*/

typedef struct stack{
	int top;
	char theStack[100];
}my_stack;

//say if one stack is empty or not
bool isStackEmpty(my_stack stack);

//test if the operator is greater than the stack
//return true if yes
//return false if not
bool testOperator(char op,my_stack stack);

//return the value of priority of an operator
int valueOperator(char op);
