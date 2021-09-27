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
	/*string user_input;
	char delim = '=';
	cout << "Please enter input for the calculator language (0 1 2 3 4 5 6 7 8 9 + - * /  = )" << endl;
	std::getline(cin, user_input, delim);
	cout << user_input << endl;*/
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
		//cin >> user_input;
		XChecker(first_input);
		//user_input.push_back('=');
		//cout << user_input << endl;
		AddtoUS(first_input, user_input, endInput);
		if (endInput == true)

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
			exit(0);
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
			first_input.erase(i, 1);
			--i;
		}
	}
	user_input.append(first_input);
	cout << user_input << endl;
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

void BNF(string user_input)
{

}
