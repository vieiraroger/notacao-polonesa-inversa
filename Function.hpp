#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cmath>	
#include "Stack.hpp"

using namespace std;

string convertToPolonese(string exp);

bool isOperator(char c);

double calculatePolonese(string exp, double values[], bool has_values);

bool isDecimal(char c);

bool isCharacter(char c);

double calc(char op,double n1, double n2);

void readInput(string file_name);
