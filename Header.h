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

class BinaryTree {
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
