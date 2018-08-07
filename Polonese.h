#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cmath>	
#include "Stack.h"
#include "utils.h"

using namespace std;

class Polonese
{
	public:
		Polonese();
		Polonese(string s);
		~Polonese();

		string getPolonese();

		//take a string and make a inverse polonese notation
		string convertToPolonese(string exp);

		//calculate using a inverse polonese exp and return the value
		double calculatePolonese();

		//show in the console the polonese and the value
		void showResult();

		//verify if the string can be converted to polonese
		bool verifyInput(string s);

		//reada file input
		void readInput(string file_name);

		//ask if want to save the output
		void saveOutput(double value);

		//create a file with the output
		void createOutput(double value);

		//show in the console the polonese and the value
		void showResult(double value);

	private:
		string polonese;
		bool has_values;
		double values[52];
		
		//test if the operator is greater than the stack
		bool testOperator(char_stack *stack, char op);

		//return the value of priority of an operator
		int valueOperator(char op);
	
};