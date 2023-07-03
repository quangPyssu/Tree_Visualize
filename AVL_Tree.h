#pragma once

#include <iostream>
#include <string>
#include "Tools/Tree.h"
#include "Animation/AVL_Anime.h"

using namespace std;

struct AVL_Tree : public Tree
{
	//using Tree::Tree;
	AVL_Tree();
	virtual ~AVL_Tree();

	AVL_Anime* anime;

	float BeginPosX=0;

	bool is;

	// Button
	Button* btnBack;
	Button* btnForw;
	Button* btnPlay;

	// Inheritance

	virtual void updateCurrent(Event& event, Vector2f& MousePos) ;

	//function

	void CreateVisual();

	void Push(AVL_node* &Cur,int& cnt,AVL_node* &,bool isLeft);
	void PushLink(AVL_node*& node1, AVL_node*& node2);
	void PushAnime(AVL_Anime* &anime1);

	//actual tree

	int cnt=0;

	vector <AVL_node*> NodeVector;

	AVL_node* root = NULL;

	AVL_node* new_node(int data);

	int count_node(AVL_node* cur);

	AVL_node* insertT(AVL_node*& cur, int data, AVL_node*& parent,bool Isleft);

	void print_console(AVL_node* cur, string prefix, bool isLeft);

	void print_console();

	AVL_node* Del(AVL_node*& cur, int data);

	AVL_node* Search(AVL_node*& cur, int data);

	void DelAll(AVL_node* cur);
};