/*
*Author: Ethan Puschell
*Creation Date: 9-27-21
* Modification Date: 9-27-21
* Purpose: EBNF calculator that parses user input (as a string) to calculate using leftmost derivation.
*/

#include<iostream>
#include<istream>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include "Header.h"
using namespace std;

void Welcome();
void XChecker(string);
void DupOpCheck(string&);
bool BeginningOp(char);
void DupOpFinder(string, string);
void AddtoUS(string, string&, bool&);
bool CheckCharacter(char);
bool ParenthesesCheck(string&);
void BNF(string&);
void ParseUI(string&, vector<string>);

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
		XChecker(first_input);
		DupOpCheck(first_input);
		AddtoUS(first_input, user_input, endInput);
		DupOpCheck(user_input);
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
// CREATION DATE: 9-28-21
// LAST MODIFIED: 9-28-21
// INPUT: 
// OUTPUT: 
// DESCRIPTION: 
void DupOpCheck(string& user_input)
{
	/*if (BeginningOp(user_input.begin() == true))
	{
		cerr << "ERROR : Operator found at the beginning of input. Deleting input." << endl;
		user_input.erase();
	}*/
	vector<string> dubOps = { "+*", "+/", "-*", "-/", "**", "*/", "/*", "//","+=", "-=", "*=", "/="};
	for (int i = 0; i < dubOps.size(); i++)
	{
		size_t found = user_input.find(dubOps.at(i));
		if (found != std::string::npos)
		{
			cerr << "ERROR : Illegal operator function " << dubOps.at(i) << " found. Deleting input." << endl;
			user_input.erase();
		}
	}
}

// AUTHOR: Ethan Puschell
// CREATION DATE: 9-28-21
// LAST MODIFIED: 9-28-21
// INPUT: 
// OUTPUT: 
// DESCRIPTION: 
bool BeginningOp(char x)
{
	bool bOp = false;
	switch (x) {
	case '+':
		bOp = true;
		break;
	case '-':
		bOp = true;
		break;
	case '*':
		bOp = true;
		break;
	case '/':
		bOp = true;
		break;
	}
	return bOp;
}

// AUTHOR: Ethan Puschell
// CREATION DATE: 9-27-21
// LAST MODIFIED: 10-1-21
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
	if (ParenthesesCheck(user_input) == false)
	{
		cerr << "Error : Parentheses not properly opened/closed. Erasing invalid input." << endl;
		user_input.erase();
		cout << "New user input (post parentheses erasing): " << user_input << endl;
		endInput = false;
	}
}

// AUTHOR: Ethan Puschell
// CREATION DATE: 9-27-21
// LAST MODIFIED: 9-29-21
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
	/*case '(':
		isChar = true;
		break;
	case ')':
		isChar = true;
		break;*/
	}
	return isChar;
}

// AUTHOR: Ethan Puschell
// CREATION DATE: 9-29-21
// LAST MODIFIED: 9-30-21
// INPUT: 
// OUTPUT: 
// DESCRIPTION: 
bool ParenthesesCheck(string& user_input)
{
	int count = 0;
	for (int i = 0; i < user_input.size(); i++)
	{
		if (user_input.at(i) == '(')
			count++;
		else if (user_input.at(i) == ')')
			count--;
	}
	if (count == 0)
		return true;
	else
		return false;
}

// AUTHOR: Ethan Puschell
// CREATION DATE: 9-27-21
// LAST MODIFIED: 9-30-21
// INPUT: 
// OUTPUT: 
// DESCRIPTION: 
void BNF(string& user_input)
{
	vector<string> u_vec;
	cout << "BNF time baby!" << endl;
	if (ParenthesesCheck(user_input) == false)
	if (user_input.find("+") == 0
		|| user_input.find("-") == 0
		|| user_input.find("*") == 0
		|| user_input.find("/") == 0)
	{
		cerr << "Error : Cannot have an operator at the beginning of the input. Deleting operand." << endl;
		user_input.erase(0, 1);
		cout << "New user input: " << user_input << endl;
	}
	cout << "User input without equals sign before parsing: " << user_input << endl;
	ParseUI(user_input, u_vec);
	user_input.clear();
	cout << "New user input: " << user_input << endl;
}

// AUTHOR: Ethan Puschell
// CREATION DATE: 9-28-21
// LAST MODIFIED: 10-1-21
// INPUT: 
// OUTPUT: 
// DESCRIPTION: 
void ParseUI(string& user_input, vector<string> user_vec)
{
	int uiSize = user_input.size();
	//user_input.erase(uiSize, 1);
	//cout << "User input without the equals sign: " << user_input << endl;
	for (int i = 0; i < uiSize; i++)
	{
		if (user_input.at(i) == '+' || user_input.at(i) == '-' || user_input.at(i) == '*' || user_input.at(i) == '/')
		{
			user_input.insert(i + 1, " ");
			user_input.insert(i, " ");
			i++;
			uiSize += 2;
		}
	}
	user_input.insert(uiSize - 1, " ");
	cout << "User input with spacing: " << user_input << endl;
	cout << "Now getting rid of the equals sign." << endl;
	user_input.erase(uiSize, 1);
	string buf;
	stringstream ss(user_input);
	while (ss >> buf)
		user_vec.push_back(buf);
	cout << "User vector: ";
	for (int j = 0; j < user_vec.size(); j++)
		cout << user_vec.at(j) << " ";
	cout << endl;
	ParseTree* pt = BuildTree(user_vec);
	cout << "User expression is in Parse Tree." << endl;
	cout << "Solution = " << EvaluateTree(pt) << endl;
}
