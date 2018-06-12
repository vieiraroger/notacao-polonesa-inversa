#include "Function.hpp"
#include <cmath>

string convertToPolonese(string exp) {

	char_stack stack;
	stack = newStackChar();

	bool myDouble = false;

	string polonese = "";


	for(int i=0;i<exp.size();i++) {
		if(isOperator(exp[i])) {
			
			if(myDouble) {
				myDouble = false;
				polonese += ' '; //this will help to calculate the value
			}	
			if(isStackEmptyChar(stack)) {
				stack = addStackChar(stack, exp[i]);
			}
			else if(valueOperator(exp[i]) == -1) {
				while(stack.theStack[stack.top] != '(') {
					polonese += stack.theStack[stack.top];
					polonese += ' '; //this will help to calculate the value
					stack = removeStackChar(stack);
				}
				stack = removeStackChar(stack);
			}
			else if(testOperator(stack,exp[i])) {
				stack = addStackChar(stack, exp[i]);

			}
			else {
				while(!testOperator(stack,exp[i])) {
					polonese += stack.theStack[stack.top];
					polonese += ' '; //this will help to calculate the value
					stack = removeStackChar(stack);
				}
				stack = addStackChar(stack,exp[i]);
			}
		}
		//is a caracter
		else if(isCharacter(exp[i])) {		
			if(myDouble) {
				myDouble = false;
				polonese += ' '; //this will help to calculate the value
			}
			polonese += exp[i];
			polonese += ' '; //this will help to calculate the value
			
		}
		//is a number
		else {
			myDouble = true;
			polonese += exp[i];
		}
	}

	while(!isStackEmptyChar(stack)) {
		polonese += ' '; //this will help to calculate the value
		polonese += stack.theStack[stack.top];
		polonese += ' '; //this will help to calculate the value
		stack = removeStackChar(stack);
	}

	return polonese;
}

double calculatePolonese(string exp) {
	
	double_stack stack;
	stack = newStackDouble();

	double value = 0;
	double actual = 0;

	//char variable value
	// a-> 0
	// z -> 25
	// A -> 26
	// Z -> 51
	double variableValue[52];

	for(int i=0;i<52;i++) {
		variableValue[i] = 0;
	}

	bool first = true; //show the header of variables input
	for(int i=0;i<exp.size();i++) {

		if(isCharacter(exp[i])) {
			if(first) {
				cout << "Escreva os valores para as respequitivas variaveis:" << endl;
				first = false;
			}

			cout << exp[i] << ": ";

			//lower case
			if(exp[i] - 'a' < 26 && exp[i] - 'a' >= 0) {
				cin >> variableValue[(exp[i] - 'a')];
			}
			//high case
			else {
				cin >> variableValue[26 + (exp[i] - 'A')];
			}
			
		}
	}

	for(int i=0;i<exp.size();i++) {

		if(isOperator(exp[i])) {
			//cout << "I: " << i<< endl;
			double value1 = stack.theStack[stack.top];
			//cout << stack.theStack[stack.top] << endl;
			stack = removeStackDouble(stack);
			double value2 = stack.theStack[stack.top];
			//cout << stack.theStack[stack.top] << endl;
			stack = removeStackDouble(stack);
			double calculated = calc(exp[i],value1,value2);

			stack = addStackDouble(stack,calculated);
		}
		//checks if this is a variable
		else if(isCharacter(exp[i])) {
			//lower case
			if(exp[i] - 'a' < 26 && exp[i] - 'a' >= 0) {
				stack = addStackDouble(stack,variableValue[(exp[i] - 'a')]);
			}
			//high case
			else {
				//cout << variableValue[26 + (exp[i] - 'A')];
				stack = addStackDouble(stack,variableValue[26 + (exp[i] - 'A')]);
			}
		}
		//cheks if this is a decimal
		else if(isDecimal(exp[i])) {
			double decimal = (exp[i] - '0');
			bool comma = false;
			double multi = 10;
			int j;

			for(j=i + 1;exp[j] != ' ' && exp[j] != NULL;j++) {

				if(exp[j] == '.') {
					comma = true;
					j++;
				}

				if(!comma) {
					decimal = decimal*10;
					decimal += (exp[j] - '0');
				}
				else {
					double aux = (exp[j] - '0');
					decimal += aux/multi;
					multi = multi*10;
				}
				
			}

			i = j - 1;

			stack = addStackDouble(stack,decimal);
			
		}
		else if(exp[i] == ' ') {

		}
		else {
			cout << "error: exp[i] = " << exp[i] << endl;
			system("pause");
		}

	}

	return stack.theStack[stack.top];
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
