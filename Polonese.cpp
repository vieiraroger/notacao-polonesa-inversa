#include "Polonese.hpp"

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
					cout << "Escreva os valores para as respequitivas variaveis: " << endl <<"(utilizar '- para negativos')" << endl;
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
		else if(isDecimal(exp[i]) || exp[i] == '!') {
			double decimal = 0;
			bool comma = false;
			bool negative = false;
			double multi = 10;
			int j;

			for(j=i;exp[j] != ' ' && exp[j] != NULL;j++) {
				if(exp[j] == '!') {
					negative = true;
					j++;
				}
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

			if(negative) {
				decimal = (-1) * decimal;
			}

			stack = addStackDouble(stack,decimal);
			
		}
		else if(exp[i] == ' ') {

		}
		else {
			cout << "error: exp[i] = " << exp[i] << endl;
			system("pause");
		}

	}

	saveOutput(exp,stack->value,variableValue);

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
				bool negative = false;
				bool comma = false;
				double multi = 10;
				int j;

				for(j=3;j<line.size();j++) {
					if(line[j] == '!') {
						negative = true;
						j++;
					}
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
				if(negative) {
					decimal = (-1) * decimal; 
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
		return;
	}

	double retur = calculatePolonese(polonese,variableValue,true);
	
  	return;
}

void saveOutput(string polonese,double value,double variableValue[]) {

	showResult(polonese,value,variableValue);
	cout << " " << endl;
	char test;
	cout << "Deseja salvar o resultado em um arquivo?" << endl;
	cout << "Digite 'S' para sim e 'N' para nao" << endl;
	cin >> test;
	if(test == 'S') {
		createOutput(polonese,value,variableValue);
	}

	return; 
}

void createOutput(string polonese,double value,double variableValue[]) {

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
	for(int i=0;i<52;i++) {
		if(variableValue[i] != NULL) {
			if(i<26) {
				outfile << (char)(i + 'a') << ": " << variableValue[i] << endl;
			}
			else {
				outfile << (char)((i - 26) + 'A') << ": " << variableValue[i] << endl;
			}
		}
	}
	outfile << "Apos o calculo: "<< value << endl;
	outfile.close();

	return;
}

void showResult(string polonese,double value,double variableValue[]) {
	system("cls");
	cout << "Versao Polonesa: " << polonese << endl;
	for(int i=0;i<52;i++) {
		if(variableValue[i] != NULL) {
			if(i<26) {
				cout <<(char)(i + 'a') << ": " << variableValue[i] << endl;
			}
			else {
				cout << (char)((i - 26) + 'A') << ": " << variableValue[i] << endl;
			}
		}
	}
	cout << "Apos o calculo: "<< value << endl;
}

bool verifyInput(string s) {
	int p1=0,p2=0; //number of ( )

	//false -> last was a operator
	//true -> last was a element
	bool eo = false;
	bool comma = false;
	int i;
	for(i=0;i<s.length();i++) {
		//cout << s[i] << endl;
		//system("pause");
		if(isOperator(s[i])||isCharacter(s[i])) {
			comma = false;
		}
		if(s[i] == '.' && comma) {
			return false;
		}
		if(s[i] == '.') {
			cout << "teste";
			system("pause");
			comma = true;
		}
				
		//Case ()
		if(s[i] == '(' ) {
            p1++;
        }
        else if(s[i] == ')') {
            p2++;
        }
        if(p2 > p1) {
            return false;
        }
	}

	for(int i=0;i<s.size();i++) {
		//Case EOE
        if(s[i] == '(' || s[i] == ')') {
        	//ignore
        }
        else if(!eo && (isCharacter(s[i]))) {
        	eo = true;
        }
        else if(isDecimal(s[i]) || s[i] == '!') {
			int j;
			for(j=i;isDecimal(s[j]) || (s[j] == '.'||  s[j] == '!');j++) {
				
			}
			i = j;
			eo = true;
        }
        else if(eo && isOperator(s[i])) {
        	eo = false;
		}
		else {
			return false;
		}
	}

	//if the last isnt a caracter or a number
	if(!eo) {
		return false;
	}
	
	if(p1 != p2) {
        return false;    
    }
    
	return true;
}