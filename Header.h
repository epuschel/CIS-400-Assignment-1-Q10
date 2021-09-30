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
//int i = atoi("321");

struct ParseTree
{
	string value;
	ParseTree* left, *right, *parent;
	ParseTree() :
		value(""), left(NULL), right(NULL), parent(NULL) { }
	ParseTree(string v) :
		value(v), left(NULL), right(NULL), parent(NULL) { }
	ParseTree(string v, ParseTree* l, ParseTree* r, ParseTree* p) :
		value(v), left(l), right(r), parent(p) { }
};

/*struct Node {
	string value;
	Node* left;
	Node* right;
	Node* parent;
	Node(string) :
		value(""), left(NULL), right(NULL), parent(NULL) { }
	Node(string v, Node* l, Node* r, Node* p) :
		value(v), left(l), right(r), parent(p) { }
};

class*/

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
	//string initializer = NULL;
	//ParseTree* pt = NewNode(user_vec.at(0));
	ParseTree* pt = new ParseTree;
	for (int i = 0; i < user_vec.size(); i++)
	{
		if (!IsOperator(user_vec.at(i)) && !pt->left)
		{
			ParseTree* temp = NewNode(user_vec.at(i));
			pt->left = temp;
			temp->parent = pt;
			pt = pt->left;
		}
		else if (!IsOperator(user_vec.at(i)) && !pt->right)
		{
			ParseTree* temp = NewNode(user_vec.at(i));
			pt->right = temp;
			temp->parent = pt;
			pt = pt->right;
		}
		else if (IsOperator(user_vec.at(i)) && pt->parent->value.length() == 0)
		{
			ParseTree* temp = NewNode(user_vec.at(i));
			pt->parent = temp;
			if (pt == pt->parent->left)
				temp->left = pt;
			else if (pt == pt->parent->right)
				temp->right = pt;
			pt = pt->parent;
		}
		else if (IsOperator(user_vec.at(i)) && pt->parent->value.length() != 0)
		{
			ParseTree* temp = NewNode(user_vec.at(i));
			if (pt == pt->parent->left)
				temp->left = pt;
			else if (pt == pt->parent->right)
				temp->right = pt;
			pt->parent = temp;
		}
	}
	/*stack<ParseTree*> ptStack;
	ParseTree *t, *t1/*, *t2;
	int operand;
	//char index;

	/* Traverse through every character of input expression */
	/*for (int i = 0; i < user_vec.size(); i++)
	{
		//index = user_vec.at(i).c_str;
		/* If operand, simply push into stack */
		/*if (!IsOperator(user_vec.at(i)))
		{
			t = NewNode(user_vec.at(i));
			ptStack.push(t);
		}
		else //operator
		{
			t = NewNode(user_vec.at(i));

			/* Pop 2 nodes */
			/*t1 = ptStack.top();	//Store top
			ptStack.pop();		//Remove top
			t2 = ptStack.top();
			ptStack.pop();

			/* Make them children */
			/*t->right = t1;
			t->left = t2;

			/* Add this subexpression to the stack */
			/*ptStack.push(t);
		}
	}

	/* Only element will be root of the Parse Tree*/
	/*t = ptStack.top();
	ptStack.pop();
	return t;*/
	return pt;
}

void PrintTree(ParseTree* pt, int space)
{
	int addSpace = 8;
	if (!pt)
		return;
	space += addSpace;
	PrintTree(pt->right, space);
	cout << endl;
	for (int i = addSpace; i < space; i++)
		cout << " ";
	cout << pt->value << endl;
	PrintTree(pt->left, space);
}

/*struct Node {
	string key;
	Node * left;
	Node * right;
	Node * parent;
	Node(string k) :
		key(k), left(NULL), right(NULL), parent(NULL) { }
	Node(string k, Node* l, Node* r, Node* p) :
		key(k), left(l), right(r), parent(p) { }
};

class ParseTree {
public:
	Node* root;
private:
	void deleteAll();
	Node * successor(Node* w) const;
	int n;
public:
	ParseTree() : root(NULL) { };
	~ParseTree();
};

void ParseTree::deleteAll()
{
	Node * w = root;
	while (w)
	{
		if (!(w->left || w->right))
		{
			Node * x = w;
			w = w->parent;
			if (w)
			{
				if (w->left == x)
					w->left = NULL;
				else
					w->right = NULL;
			}
			delete x;
			continue;
		}
		w = (w->left) ? w->left : w->right;
	}
}

ParseTree::~ParseTree()
{
	deleteAll();
}*/

/*class BinaryTree {
private:
	string key;
	BinaryTree* left;
	BinaryTree* right;
public:
	BinaryTree(string rootObj)
	{
		this->key = rootObj;
		this->left = NULL;
		this->right = NULL;
	}

	void insertLeft(string newNode)
	{
		if (this->left == NULL)
			this->left = new BinaryTree(newNode);
		else
		{
			BinaryTree* t = new BinaryTree(newNode);
			t->left = this->left;
			this->left = t;
		}
	}

	void insertRight(string newNode)
	{
		if (this->right == NULL)
			this->right = new BinaryTree(newNode);
		else
		{
			BinaryTree* t = new BinaryTree(newNode);
			t->right = this->right;
			this->right = t;
		}
	}

	BinaryTree* getRight()
	{
		return this->right;
	}

	BinaryTree* getLeft()
	{
		return this->left;
	}

	void createRoot(string obj)
	{
		this->key = obj;
	}

	string getRoot()
	{
		return this->key;
	}
};

/*BinaryTree *buildParseTree(string fpexp) {
	string buf;
	stringstream ss(fpexp);
	vector<string> fplist;
	while (ss >> buf)
		fplist.push_back(buf);
	BinaryTree * pT = new BinaryTree("");
	BinaryTree * currentTree = pT;

	string arr[] = { "+", "-", "*", "/" };
}*/
