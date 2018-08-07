#include <cstdlib>
#include <iostream>
#include <stdlib.h>

#include "Polonese.h"

using namespace std;

void menu(string exp);
void commands();
void configs();

int main(int argc, char *argv[]) {
	//variable declaration
	string exp = "A+B*C"; //cba+*
	cout << exp;
	double value;
	string polonese ="";
	string input;
	string save;
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
				save = exp;
				cin >> exp;

				if(!verifyInput(exp)) {
					cout << "Expressao invalida" << endl;
					exp = save;
					system("pause");
				}
				break;
			//convert and calculate polonese
			case 2:
				polonese = convertToPolonese(exp);
				value = calculatePolonese(polonese,NULL,false);
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
			//system configs
			case 5:
				configs();
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
	cout << "5- Configuracoes do sistema" << endl;
	cout << "0- Sair do programa" << endl;
}

void commands() {
	system("cls");
	cout << "+ -> Soma" << endl;
	cout << "- -> Subtracao" << endl;
	cout << "* -> Multiplicacao" << endl;
	cout << "/ -> Divisao" << endl;
	cout << "^ -> Potenciacao" << endl;
	cout << "( ) -> Parenteses" << endl;
	cout << "! -> Numero negativo direto na expressao (ex: !12 == -12)" << endl;
	cout << ". -> virgula (para numeros decimais)" << endl;
}

void configs() {
	system("cls");
	cout << "Configuracoes do Sistema)" << endl;
	cout << "Limites:" << endl;
	cout << "-> 0 < expressao.size() 2^32" << endl;
	cout << "-> -1.7x10^308 < variaveis < 1.7x10^308" << endl;
	cout << "-> !1.7x10^308 <= numero < 1.7x10^308" << endl;
	
}
