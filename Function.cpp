#include "Function.hpp"

string convertToPolonese(string exp) {

	//my_stack stack = new my_stack();

	/*
	//entrar no parenteses cetral
	int indexStart=-1, indexEnd=-1;
	for(int i=0;i<exp.size;i++) {

		if(exp[i] == "(") {
			indexStart = i;
		}

		if(exp[i] == ')') {
			indexEnd = i;
			string sub = exp.substr(indexStart,indexEnd);

		}

	}
	*/

	char_stack stack;
	stack = newStackChar();

	string polonese = "";
	for(int i=0;i<exp.size();i++) {
 		

		if(isOperator(exp[i])) {
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
		//is a caracter or a number
		else {
			polonese += exp[i];
			polonese += ' '; //this will help to calculate the value
		}
	}

	while(!isStackEmptyChar(stack)) {
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
			if(exp[i] - 'a' < 26 && exp[i] - 'a' >=0 ) {
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
			return 0;
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
