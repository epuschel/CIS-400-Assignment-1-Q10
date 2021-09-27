/*
*Author: Ethan Puschell
*Creation Date: 9-27-21
* Modification Date: 9-27-21
* Purpose:
*/

#include<iostream>
#include<istream>
#include<math.h>
#include<stdlib.h>
#include<string>
//#include "Header.h"
using namespace std;
int i = atoi("321");

void Welcome();
void XChecker(string);
void AddtoUS(string, string&, bool&);
bool CheckCharacter(char);
void BNF(string&);

int main()
{
	Welcome();
	system("pause");
	return 0;
}

// AUTHOR: Ethan Puschell
// CREATION DATE: 9-27-21
// LAST MODIFIED: 9-27-21
// INPUT: 
// OUTPUT: 
// DESCRIPTION: 
void Welcome()
{
	string first_input, user_input;
	bool endInput = false;
	while (first_input != "x")
	{
		cout << "Please enter input for the calculator language (0 1 2 3 4 5 6 7 8 9 + - * /  = )" << endl;
		std::getline(cin, first_input);
		XChecker(first_input);;
		AddtoUS(first_input, user_input, endInput);
		if (endInput == true)
		{
			BNF(user_input);
			endInput = false;
		}
	}
}

// AUTHOR: Ethan Puschell
// CREATION DATE: 9-27-21
// LAST MODIFIED: 9-27-21
// INPUT: 
// OUTPUT: 
// DESCRIPTION: 
void XChecker(string user_input)
{
	for (int i = 0; i < user_input.size(); i++)
		if (user_input.at(i) == 'x' || user_input.at(i) == 'X')
		{
			cout << "Goodbye." << endl;
			exit(0);
		}
}

// AUTHOR: Ethan Puschell
// CREATION DATE: 9-27-21
// LAST MODIFIED: 9-27-21
// INPUT: 
// OUTPUT: 
// DESCRIPTION: 
void AddtoUS(string first_input, string& user_input, bool& endInput)
{
	int whereEquals = first_input.size();
	for (int i = 0; i < first_input.size(); i++)
	{
		if (first_input.at(i) == '=')
		{
			whereEquals = i;
			first_input.erase(i + 1);
			endInput = true;
		}
		if (CheckCharacter(first_input.at(i)) == false)
		{
			cerr << "Error : Character " << first_input.at(i) << " is invalid input." << endl;
			first_input.erase(i, 1);
			--i;
		}
	}
	user_input.append(first_input);
	cout << "User input: " << user_input << endl;
}

// AUTHOR: Ethan Puschell
// CREATION DATE: 9-27-21
// LAST MODIFIED: 9-27-21
// INPUT: 
// OUTPUT: 
// DESCRIPTION: 
bool CheckCharacter(char x)
{
	bool isChar = false;
	switch (x) {
	case '0':
		isChar = true;
		break;
	case '1':
		isChar = true;
		break;
	case '2':
		isChar = true;
		break;
	case '3':
		isChar = true;
		break;
	case '4':
		isChar = true;
		break;
	case '5':
		isChar = true;
		break;
	case '6':
		isChar = true;
		break;
	case '7':
		isChar = true;
		break;
	case '8':
		isChar = true;
		break;
	case '9':
		isChar = true;
		break;
	case '+':
		isChar = true;
		break;
	case '-':
		isChar = true;
		break;
	case '*':
		isChar = true;
		break;
	case '/':
		isChar = true;
		break;
	case '=':
		isChar = true;
		break;
	}
	return isChar;
}

// AUTHOR: Ethan Puschell
// CREATION DATE: 9-27-21
// LAST MODIFIED: 9-27-21
// INPUT: 
// OUTPUT: 
// DESCRIPTION: 
void BNF(string& user_input)
{
	cout << "BNF time baby!" << endl;
	user_input.clear();
	cout << "New user input: " << user_input << endl;
}
