# TuiTextBox
The goal of this code is implement a "text box"  for Win32 console application  in C/C++ 

Example:

#include <iostream>
#include "input.h"

int main(int argc, char** argv) 
{
	std::string sName = "NoName";	
	input_control fieldName;
	
	fieldName.input(&sName, "What is your name:", 5);
	
	std::cout << std::endl << "Nice to meet you " << sName << "!";
	
	
	return 0;
}
