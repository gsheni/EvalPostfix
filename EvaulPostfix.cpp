/*
Gaurav Sheni
 */
#include <iostream>
#include "List.h"
#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <math.h>

using namespace std;

int evaulate(int, int, string); //to evaulate an operator, given two numbers 

int main (int argc, char **argv){	if (argc <= 1){
		cout << "\n";
		exit(1);//no command line arguments
	}
	//go through all command line arguments and make sure operators are legal.
	for (int i = 1; i < argc; i++){
	string checkcharacter = argv[i];
	int number = atoi(checkcharacter.c_str()); //Convert the string to a number.
	int alphacheck = -1; //check for alphabetic illegal characters, it starts at -1, which will be changed if their is an alphabetic letter
	alphacheck = checkcharacter.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"); // Look in the string for any of these characters, and return the location.
		if (checkcharacter == "("){
		goto leave;
		}
		else if (checkcharacter == ")"){
		goto leave;
		}
		else if (checkcharacter == "+"){
		goto leave;
		}
		else if (checkcharacter == "-"){
		goto leave;
		}
		else if (checkcharacter == "*"){
		goto leave;
		}
		else if (checkcharacter == "/"){
		goto leave;
		}
		else if (checkcharacter == "\\"){
		goto leave;
		}
		else if (alphacheck >= 0){ //if the alphacheck number got changed to 0 or to anything higher, indicating the location of an alphabetic character, then exit the program.
		cout << "\n";
		exit(1);//illegal character
		}
		else if (number > 0) {
		goto leave;
		}
		else {
		cout << "\n";
		exit(1);//non atomic operator
		}
	leave:; //come here if legal character.
	}
	List<int> stack; //create a list, called stack, for integers
	for (int i = 1; i < argc; i++){
		string currentcharacter = argv[i];
		int number = atoi(currentcharacter.c_str()); //Convert the string to a number.
		if (number > 0){
			stack.push_front(number); //if number, put on stack
			goto end; //skip rest of check and go below
		}

		else if (currentcharacter == "*" || currentcharacter == "+" || currentcharacter == "-" || currentcharacter == "/"){
		//operator, use two top numbers from stack to evaluate, and put back on stack.
			int operand1;
			operand1 = stack.front();
			stack.pop_front(); //remove top of stack

			int operand2;
			operand2  = stack.front();
			stack.pop_front(); //remove top of stack

			int result;
			result = evaulate(operand1, operand2, currentcharacter);
			stack.push_front(result);
		}
	end:;  //skip rest of check and go below
	}
		int stacksize;
		stacksize = stack.size(); //find stack size to see if has one value
		if (stacksize == 1){ //print this result, which will be the one int on the stack
			cout << stack.front() << " " << endl;
			//stack.pop_front(); //not necessary to pop last front, caused segmentation error.
		}
}

int evaulate(int operand1, int operand2, string currentcharacter){
	if (currentcharacter == "*"){ //Multiplication
		int answer1;
		answer1 = (operand2 * operand1);
		return answer1;
	}
	else if (currentcharacter == "/"){ //Division
		int answer2;
		answer2 = (operand2 / operand1);
		return answer2;
	}
	else if (currentcharacter == "+"){ //addition
		int answer3;
		answer3 = (operand2 + operand1);
		return answer3;
	}
	else if (currentcharacter == "-"){ //subtraction
		int answer4;
		answer4 = (operand2 - operand1);
		return answer4;
	}
}

