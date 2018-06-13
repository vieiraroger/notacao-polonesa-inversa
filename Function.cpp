#include "Function.hpp"


string convertToPolonese(string exp) {

	char_stack *stack;
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
				while(stack->value != '(') {
					polonese += stack->value;
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
					polonese += stack->value;
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
		polonese += stack->value;
		polonese += ' '; //this will help to calculate the value
		stack = removeStackChar(stack);
	}

	return polonese;
}

double calculatePolonese(string exp,double values[], bool has_values) {
	
	//optional cout and system(cls)
	system("cls");
	cout << exp << endl;

	double_stack *stack;
	stack = newStackDouble();

	double value = 0;
	double actual = 0;

	//char variable value
	// a-> 0
	// z -> 25
	// A -> 26
	// Z -> 51
	double variableValue[52];

	//Get caracter value
	if(!has_values) {
		for(int i=0;i<52;i++) {
			variableValue[i] = NULL;
		}

		bool first = true; //show the header of variables input
		for(int i=0;i<exp.size();i++) {

			if(isCharacter(exp[i]) && variableValue[i] == NULL) {
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

	}
	else {
		for(int i=0;i<52;i++) {
			variableValue[i] = values[i];
		} 
	}
	
	for(int i=0;i<exp.size();i++) {

		if(isOperator(exp[i])) {
			//cout << "I: " << i<< endl;
			double value1 = stack->value;
			//cout << stack.theStack[stack.top] << endl;
			stack = removeStackDouble(stack);
			double value2 = stack->value;
			//cout << stack.theStack[stack.top] << endl;
			stack = removeStackDouble(stack);

			//value2 'operation' value1

			double calculated = calc(exp[i],value2,value1);

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

	saveOutput(exp,stack->value);

	return stack->value;
}

void readInput(string file_name) {
	string line;
	string exp;
	string polonese = "";
	

	// std::string to std::char
	string input = "input/" + file_name;
	char file[40];
	for(int i=0;i<input.size();i++) {
		file[i] = input[i];
	}

	double variableValue[52];

	ifstream myfile (file);
	
  	if (myfile.is_open()) {

    	getline(myfile,line);

      	cout << "Espressao: " << line << endl;
      	exp = line;
      	polonese = convertToPolonese(exp);

		for(int i=0;i<52;i++) {
			variableValue[i] = NULL;
		}

		for(int i=0;i<polonese.size();i++) {

			if(isCharacter(polonese[i])) {

				getline(myfile,line);
				cout << line << endl;

				double decimal=0;
				bool comma = false;
				double multi = 10;
				int j;

				for(j=3;j<line.size();j++) {

					if(line[j] == '.') {
						comma = true;
						j++;
					}

					if(!comma) {
						decimal = decimal*10;
						decimal += (line[j] - '0');
					}
					else {
						double aux = (line[j] - '0');
						decimal += aux/multi;
						multi = multi*10;
					}
					
				}
	
				if(line[0] - 'a' < 26 && line[0] - 'a' >= 0) {

					variableValue[(line[0] - 'a')] = decimal;
					
					
				}
				//high case
				else {
					variableValue[26 + (line[0] - 'A')] = decimal;
				}
				
			}
		}

    	myfile.close();
	}
	else {
		cout << "Erro ao abrir arquivo";
	}

	double retur = calculatePolonese(polonese,variableValue,true);
	
  	return;
}

void saveOutput(string polonese,double value) {

	showResult(polonese,value);
	cout << " " << endl;
	char test;
	cout << "Deseja salvar o resultado em um arquivo?" << endl;
	cout << "Digite 'S' para sim e 'N' para nao" << endl;
	cin >> test;
	if(test == 'S') {
		createOutput(polonese,value);
	}

	return; 
}

void createOutput(string polonese,double value) {

	string file_name;
	cout << "Digite o nome do arquivo que deseja salvar:" << endl;
	cin >> file_name;
	file_name = "output/" + file_name;

	char otherFile[100] = "";
	for(int i=0;i<file_name.size();i++) {

		otherFile[i] = file_name[i];
		//cout << i << output[i] << otherFile[i];
	}
	ofstream outfile(otherFile);
	

	outfile << "Versao Polonesa: " << polonese << endl;
	outfile << "Apos o calculo: "<< value << endl;
	outfile.close();

	return;
}

void showResult(string polonese,double value) {
	system("cls");
	cout << "Versao Polonesa: " << polonese << endl;
	cout << "Apos o calculo: "<< value << endl;
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
