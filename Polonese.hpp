#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cmath>	
#include "Stack.hpp"

using namespace std;

//take a string and make a inverse polonese notation
string convertToPolonese(string exp);

//calculate using a inverse polonese exp and return the value
double calculatePolonese(string exp, double values[], bool has_values);

//do calc like a calculator
double calc(char op,double n1, double n2);

//reada file input
void readInput(string file_name);

//ask if want to save the output
void saveOutput(string polonese,double value);

//create a file with the output
void createOutput(string polonese,double value);

//show in the console the polonese and the value
void showResult(string polonese,double value);

//test if is an operator
bool isOperator(char c);

//test if is a number
bool isDecimal(char c);

//test if a caracter
bool isCharacter(char c);

//verify if the string can be converted to polonese
bool verifyInput(string s);