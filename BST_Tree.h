#pragma once

#include <iostream>
#include <string>
#include "Tools/Tree.h"
#include "Animation/BST_Anime.h"

using namespace std;

struct BST_Tree : public Tree
{
	//using Tree::Tree;
	BST_Tree();
	virtual ~BST_Tree();

	BST_Anime* anime;

	float BeginPosX=0;

	bool is;

	// Button
	Button* btnBack;
	Button* btnForw;
	Button* btnPlay;
	Button* btnStart;
	Button* btnEnd;

	// Inheritance

	virtual void updateCurrent(Event& event, Vector2f& MousePos) ;
	virtual void takeTimeCurrent(Time& dt) ;

	void Disable() override;
	void Able() override;

	//function

	void CreateVisual();
	void DestroyVisual();

	void Push(BST_node* &Cur,int& cnt,BST_node* &,bool isLeft);
	void PushLink(BST_node*& node1, BST_node*& node2);
	void PushAnime(BST_Anime* &anime1);

	void Obliterate();
	void Forge(int n);

	//actual tree

	int cnt=0;

	vector <BST_node*> NodeVector;

	BST_node* root = NULL;

	BST_node* new_node(int data);

	int count_node(BST_node* cur);

	BST_node* insertT(BST_node*& cur, int data, BST_node*& parent,bool Isleft);

	void print_console(BST_node* cur, string prefix, bool isLeft);

	void print_console();

	BST_node* Del(BST_node*& cur, int data);

	BST_node* Search(BST_node*& cur, int data);

	void DelAll(BST_node* cur);
};
