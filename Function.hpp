#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Stack.hpp"

using namespace std;

string convertToPolonese(string exp);

bool isOperator(char c);

double calculatePolonese(string exp);

bool isDecimal(char c);

bool isCharacter(char c);


double calc(char op,double n1, double n2);