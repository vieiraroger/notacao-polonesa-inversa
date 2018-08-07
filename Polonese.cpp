#include "Polonese.h"

Polonese::Polonese() {
	this->polonese = Polonese::convertToPolonese("A+B*C");
	this->has_values = false;
}

Polonese::Polonese(string s) {
	this->polonese = Polonese::convertToPolonese(s);
	this->has_values = false;
}

Polonese::~Polonese() {
}

string Polonese::getPolonese() {
	return this->polonese;
}

string Polonese::convertToPolonese(string exp) {

	char_stack *stack;
	stack = newStackChar();

	for(int i=0;i<52;i++) {
		this->values[i] = NULL;
	}
	this->has_values = false;

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
				while(stack != NULL && !testOperator(stack,exp[i]) ) {
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

	this->polonese = polonese;
	return polonese;
}

bool Polonese::verifyInput(string s) {
	int p1=0,p2=0; //number of ( )

	//false -> last was a operator
	//true -> last was a element
	bool eo = false;

	bool comma = false;
	int i;
	for(i=0;i<s.length();i++) {

		if(isOperator(s[i])||isCharacter(s[i])) {
			comma = false;
		}
		if(s[i] == '.' && comma) {
			return false;
		}
		if(s[i] == '.') {
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
			i = j - 1;
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

double Polonese::calculatePolonese() {
	
	//optional cout and system(cls)
	system("cls");
	cout << this->polonese << endl;

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
	if(!this->has_values) {
		for(int i=0;i<52;i++) {
			variableValue[i] = NULL;
		}

		bool first = true; //show the header of variables input
		for(int i=0;i<this->polonese.size();i++) {

			if(isCharacter(this->polonese[i]) && variableValue[i] == NULL) {
				if(!this->has_values) {
					cout << "Escreva os valores para as respequitivas variaveis: " << endl <<"(utilizar '- para negativos')" << endl;					this->has_values = true;
				}

				cout << this->polonese[i] << ": ";

				//lower case
				if(this->polonese[i] - 'a' < 26 && this->polonese[i] - 'a' >= 0) {
					cin >> variableValue[(this->polonese[i] - 'a')];
					this->values[26 + (this->polonese[i] - 'a')] = variableValue[26 + (this->polonese[i] - 'a')];
				}
				//high case
				else {
					cin >> variableValue[26 + (this->polonese[i] - 'A')];
					this->values[26 + (this->polonese[i] - 'A')] = variableValue[26 + (this->polonese[i] - 'A')];
				}
				
			}
		}

	}
	else {
		for(int i=0;i<52;i++) {
			variableValue[i] = this->values[i];
		} 
	}
	
	for(int i=0;i<this->polonese.size();i++) {

		if(isOperator(this->polonese[i])) {

			double value1 = stack->value;
			stack = removeStackDouble(stack);
			double value2 = stack->value;
			stack = removeStackDouble(stack);

			double calculated = calc(this->polonese[i],value2,value1);

			stack = addStackDouble(stack,calculated);
		}
		//checks if this is a variable
		else if(isCharacter(this->polonese[i])) {
			//lower case
			if(this->polonese[i] - 'a' < 26 && this->polonese[i] - 'a' >= 0) {
				stack = addStackDouble(stack,variableValue[(this->polonese[i] - 'a')]);
			}
			//high case
			else {
				//cout << variableValue[26 + (exp[i] - 'A')];
				stack = addStackDouble(stack,variableValue[26 + (this->polonese[i] - 'A')]);
			}
		}
		//cheks if this is a decimal
		else if(isDecimal(this->polonese[i]) || this->polonese[i] == '!') {
			double decimal = 0;
			bool comma = false;
			bool negative = false;
			double multi = 10;
			int j;

			for(j=i;this->polonese[j] != ' ' && this->polonese[j] != NULL;j++) {
				if(this->polonese[j] == '!') {
					negative = true;
					j++;
				}
				if(this->polonese[j] == '.') {
					comma = true;
					j++;
				}

				if(!comma) {
					decimal = decimal*10;
					decimal += (this->polonese[j] - '0');
				}
				else {
					double aux = (this->polonese[j] - '0');
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
		else if(this->polonese[i] == ' ') {

		}
		else {
			cout << "error: exp[i] = " << this->polonese[i] << endl;
			system("pause");
		}

	}

	saveOutput(stack->value);

	return stack->value;
}

bool Polonese::testOperator(char_stack *stack, char op) {
	if(isStackEmptyChar(stack)) {
		return false;
	}
	int value = valueOperator(op);
	return (value > valueOperator(stack->value)) || (value == 0);
}

int Polonese::valueOperator(char op) {
	
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
			cout << "ERROR in valueOperator()  " << op <<endl;
			system("pause");
			return -1;	
	}
}

void Polonese::readInput(string file_name) {
	string line;
	string exp;
	string polonese = "";

	// std::string to char[]
	string input = "input/" + file_name;
	char file[40];
	for(int i=0;i<input.size();i++) {
		file[i] = input[i];
	}
	
	ifstream myfile (file);
	
	
  	if (myfile.is_open()) {
		
    	getline(myfile,line);

      	cout << "Espressao: " << line << endl;
      	exp = line;
      	polonese = convertToPolonese(exp);

		for(int i=0;i<52;i++) {
			this->values[i] = NULL;
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

					this->values[(line[0] - 'a')] = decimal;
					
					
				}
				//high case
				else {
					this->values[26 + (line[0] - 'A')] = decimal;
				}
				
			}
		}

    	myfile.close();
	}
	else {
		cout << "Erro ao abrir arquivo";
		return;
	}
	this->polonese = polonese;
	this->has_values = true;
	double retur = calculatePolonese();
	
  	return;
}

void Polonese::saveOutput(double value) {

	showResult(value);
	cout << " " << endl;
	char test;
	cout << "Deseja salvar o resultado em um arquivo?" << endl;
	cout << "Digite 'S' para sim e 'N' para nao" << endl;
	cin >> test;
	if(test == 'S') {
		createOutput(value);
	}

	return; 
}

void Polonese::createOutput(double value) {

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
	

	outfile << "Versao Polonesa: " << this->polonese << endl;
	for(int i=0;i<52;i++) {
		if(this->values[i] != NULL) {
			if(i<26) {
				outfile << (char)(i + 'a') << ": " << this->values[i] << endl;
			}
			else {
				outfile << (char)((i - 26) + 'A') << ": " << this->values[i] << endl;
			}
		}
	}
	outfile << "Apos o calculo: "<< value << endl;
	outfile.close();

	return;
}

void Polonese::showResult(double value) {
	system("cls");
	cout << "Versao Polonesa: " << this->polonese << endl;
	for(int i=0;i<52;i++) {
		if(this->values[i] != NULL) {
			if(i<26) {
				cout <<(char)(i + 'a') << ": " << this->values[i] << endl;
			}
			else {
				cout << (char)((i - 26) + 'A') << ": " << this->values[i] << endl;
			}
		}
	}
	cout << "Apos o calculo: "<< value << endl;
}