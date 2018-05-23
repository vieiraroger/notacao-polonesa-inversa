#include <cstdlib>
#include <iostream>
#include <stdlib.h>

#include "Function.hpp"

using namespace std;

void menu(string exp);

int main(int argc, char *argv[]) {
	
	string exp = "(A+B)*C"; //cba+*
	cout << exp;
	int cod=1;
	do {
		system("cls");
		menu(exp);
/*
		switch(cod) {
			case 0:
				break;
			case 1:
				convertToPolonese(exp);
				break;
			case 2:
				//calculatePolonese(exp);
				break;
			default:
				cout << "Numero invalido!";
				system("pause");
				break;
		}

		cin >> cod;*/
		char c;
		cin >> c;
		if(isOperator(c)) {
			cout << "GOOD JOB ROGER";
			system("pause");
		}

	}while(cod != 0);
	
	system("pause");
	return 0;
}

void menu(string exp) {
	cout << "expressao atual = " << exp << endl;
	cout << "1- Converter para notacao polonesa" << endl;
	cout << "2- Calcular Notacao" << endl;
	cout << "0- Sair do programa" << endl;
	cout << "Codigo: ";
}
