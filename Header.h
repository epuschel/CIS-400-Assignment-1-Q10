#pragma once
/*
*Author: Ethan Puschell
*Creation Date: 9-27-21
* Modification Date: 9-27-21
* Purpose:
*/

#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<cstdlib>
#include<sstream>
#include<algorithm>
#include<stack>
using namespace std;

struct ParseTree
{
	string value;
	ParseTree* left, *right, *parent, *root;
	ParseTree() :
		value(""), left(NULL), right(NULL), parent(NULL), root(NULL) { }
	ParseTree(string v) :
		value(v), left(NULL), right(NULL), parent(NULL), root(NULL) { }
	ParseTree(string v, ParseTree* l, ParseTree* r, ParseTree* p, ParseTree* t) :
		value(v), left(l), right(r), parent(p), root(t) { }
};

// AUTHOR: Ethan Puschell
// CREATION DATE: 9-29-21
// LAST MODIFIED: 9-29-21
// INPUT: 
// OUTPUT: 
// DESCRIPTION: A utility function to check if 'c' is an operator.
bool IsOperator(string c)
{
	if (c == "+" || c == "-" || c == "*" || c == "/")
		return true;
	else
		return false;
}

// AUTHOR: Ethan Puschell
// CREATION DATE: 9-29-21
// LAST MODIFIED: 9-29-21
// INPUT: 
// OUTPUT: 
// DESCRIPTION: Utility function to do inorder traversal (right derivative).
void InOrder(ParseTree* pt)
{
	if (pt)
	{
		InOrder(pt->left);
		cout << pt->value;
		InOrder(pt->right);
	}
}

// AUTHOR: Ethan Puschell
// CREATION DATE: 9-29-21
// LAST MODIFIED: 9-29-21
// INPUT: 
// OUTPUT: 
// DESCRIPTION: A utility function to create a new node.
ParseTree* NewNode(string c)
{
	ParseTree *temp = new ParseTree;
	//temp->left = temp->right = NULL;
	temp->value = c;
	return temp;
}

// AUTHOR: Ethan Puschell
// CREATION DATE: 9-29-21
// LAST MODIFIED: 9-30-21
// INPUT: 
// OUTPUT: 
// DESCRIPTION: Returns root of contructed tree for given postfix expression.
ParseTree* BuildTree(vector<string> user_vec)
{
	ParseTree* pt = new ParseTree;
	for (int i = 0; i < user_vec.size(); i++)
	{
		if (!IsOperator(user_vec.at(i)) && !pt->left)
		{
			ParseTree* temp = NewNode(user_vec.at(i));
			pt->left = temp;
			temp->parent = pt;
			pt = pt->left;
			cout << "Added " << pt->value << " as a left node of the tree." << endl;
		}
		else if (!IsOperator(user_vec.at(i)) && !pt->right)
		{
			ParseTree* temp = NewNode(user_vec.at(i));
			pt->right = temp;
			temp->parent = pt;
			pt = pt->right;
			cout << "Added " << pt->value << " as a right node of the tree." << endl;
		}
		else if (IsOperator(user_vec.at(i)) && pt->parent->value.length() == 0)
		{
			ParseTree* temp = NewNode(user_vec.at(i));
			pt->parent = temp;
			temp->left = pt;
			pt = pt->parent;
			pt->root = pt;
			cout << "Added " << pt->value << " as a parent to the tree." << endl;
		}
		else if (IsOperator(user_vec.at(i)) && pt->parent->value.length() != 0)
		{
			ParseTree* opTemp = NewNode(user_vec.at(i));
			ParseTree* oldParent = pt->parent;
			opTemp->left = pt;
			oldParent->right = opTemp;
			cout << "Setting " << pt->value << " as the left child of " << opTemp->value << " and " << opTemp->value << " as the right child of " << oldParent->value << endl;
			pt->parent = opTemp;
			pt = pt->parent;
		}
	}
	return pt->root;
}

// AUTHOR: Ethan Puschell
// CREATION DATE: 9-30-21
// LAST MODIFIED: 9-30-21
// INPUT: 
// OUTPUT: 
// DESCRIPTION: Returns root of contructed tree for given postfix expression.
int EvaluateTree(ParseTree* root)
{
	if (!root)
		return 0;
	if (!root->left && root->right)
	{
		//FIXME: Find out how to convert a vector string into an integer.
		string num = root->value;
		return atoi(num.c_str);
	}

	int valL = EvaluateTree(root->left);
	int valR = EvaluateTree(root->right);

	if (root->value == "+")
		return valL + valR;
	else if (root->value == "-")
		return valL - valR;
	else if (root->value == "*")
		return valL * valR;
	else if (root->value == "/")
		return valL / valR;
}
