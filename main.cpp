#include <iostream>
#include "input.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	std::string sName = "NoName";	
	input_control fieldName;
	
	fieldName.input(&sName, "What is your name:", 5);
	
	std::cout << std::endl << "Nice to meet you " << sName << "!";
	
	
	return 0;
}
