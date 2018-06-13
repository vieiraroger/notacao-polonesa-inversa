#include <cstdlib>
#include <iostream>
#include <stdlib.h>

#include "Function.hpp"

using namespace std;

void menu(string exp);
void commands();

int main(int argc, char *argv[]) {
	
	string exp = "A+B*C"; //cba+*
	cout << exp;
	double value;
	string polonese ="";
	string input;
	int cod=0;
	do {
		system("cls");
		menu(exp);
		cout << "Codigo: " ;
		cin >> cod;

		switch(cod) {
			case 0:
				break;
			//get the new exp
			case 1:
				cin >> exp;
				system("pause");
				break;
			//convert and calculate polonese
			case 2:
				polonese = convertToPolonese(exp);
				cout << "Versao polonesa inversa: " << polonese << endl;
				value = calculatePolonese(polonese,NULL,false);
				cout << "Apos o calculo: " << value << endl;
				system("pause");
				break;
			//open a input file and create a output file
			case 3:
				cout << "Digite o nome do arquivo: " << endl;
				cout << "Ex: input1.txt" << endl;
				cin >> input;
				readInput(input);

				system("pause");
				break;
			//commands help
			case 4:
				commands();
				system("pause");
				break;
			default:
				cout << "Numero invalido!";
				system("pause");
				break;
		}

		

	}while(cod != 0);
	
	system("pause");
	return 0;
}

void menu(string exp) {
	cout << "expressao atual = " << exp << endl;
	cout << "1- Digitar expressao" << endl;
	cout << "2- Calcular Notacao" << endl;
	cout << "3- Importar arquivo de Input" << endl;
	cout << "4- Ajuda" << endl;
	cout << "0- Sair do programa" << endl;
}

void commands() {
	cout << "+ -> Soma" << endl;
	cout << "- -> Subtracao" << endl;
	cout << "* -> Multiplicacao" << endl;
	cout << "/ -> Divisao" << endl;
	cout << "^ -> Potenciacao" << endl;
	cout << "( ) -> Parenteses" << endl;
}
