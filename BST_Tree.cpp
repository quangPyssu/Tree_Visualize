#pragma once

#include <iostream>
#include <string>

using namespace std;

struct BST_node
{
	int data = 0;
	BST_node* left = NULL;
	BST_node* right = NULL;
	BST_node* par = NULL;
};

struct BST_Tree
{
	BST_node* root=NULL;

	BST_node* new_node(int data)
	{
		BST_node* tmp = new BST_node;
		tmp->data = data;
		return tmp;
	}

	BST_node* insertT(BST_node*& cur, int data)
	{
		if (cur == NULL)
		{
			cur = new_node(data);

			return cur;
		}

		if (cur->data > data) return insertT(cur->left, data); else
			if (cur->data < data) return insertT(cur->right, data); else
				return NULL;
	}

	void print_console(BST_node* cur, string prefix,bool isLeft)
	{
		if (!cur) return;

		if (isLeft) cout << "|--"; else cout << "`--";

		cout << cur->data << endl;

		if (cur->left) cout << "   " + prefix;
		print_console(cur->left, cur->right ? prefix + "|  " : prefix + "   ", 1);

		if (cur->right) cout << "   " + prefix;
		print_console(cur->right, prefix + "   ", 0);
	}

	void print_console()
	{
		print_console(root, "", 1);
	}

	BST_node* Del(BST_node* &cur,int data)
	{
		if (!cur) return NULL;

		if (cur->data > data)
		{
			cur->left = Del(cur->left, data);

			return cur;
		} else
			if (cur->data < data)
			{
				cur->right = Del(cur->right, data);

				return cur;
			}

		if (!cur->left && !cur->right) // delete leave node
		{
			delete cur;
			return NULL;
		} 

		if (cur->left && cur->right) // delete node that have 2 children
		{
			BST_node* par = cur;
			BST_node* tmp = cur->left;

			while (tmp->right)
			{
				par = tmp;
				tmp = tmp->right;
			}

			if (par == cur) par->left = tmp->left;
			else par->right = tmp->left;

			tmp->left = cur->left;
			tmp->right = cur->right;

			delete cur;

			return tmp;
		} else
			if (cur->left)   // have left child
			{
				BST_node* tmp = cur->left;
				delete cur;

				return tmp;
			}
			else			// have right child
			{
				BST_node* tmp = cur->right;
				delete cur;

				return tmp;
			}


		return cur;
	}

	BST_node* Search(BST_node* &cur,int data)
	{
		if (!cur) return NULL;

		if (cur->data > data) return Search(cur->left, data);
		if (cur->data < data) return Search(cur->right, data);
		
		return cur;
	}

	void DelAll(BST_node* cur)
	{
		if (!cur) return;

		BST_node* tmp = cur;

		DelAll(cur->left);
		DelAll(cur->right);

		delete tmp;
		root = NULL;
	}
};