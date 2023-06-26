#pragma once

#include <iostream>
#include <string>
#include "Tools/TreeNode.h"
#include "Tools/Edge.h"
#include "Tools/SceneNode.h"
#include "Tools/Button.h"
#include "Tools/TextBox.h"

using namespace std;

struct BST_node
{
	int data = nothing;
	int level = 1;

	BST_node* left = NULL;
	BST_node* right = NULL;
	BST_node* par = NULL;

	bool isLeft = true;

	shared_ptr <TreeNode> tVisual;
};

struct BST_Tree : public SceneNode
{
	BST_Tree();

	SceneNode* Buttones;
	SceneNode* TextBoxes;
	SceneNode* Linkes;
	SceneNode* Nodes;

	Button* butt1;
	Button* butt2;

	TextBox* tet1;

	float BeginPosX=0;

	virtual void drawCurrent(RenderTarget& target, RenderStates states) const;
	virtual void updateCurrent(Event& event, Vector2f& MousePos) ;

	void CreateVisual();

	void Push(BST_node* &Cur,int& cnt);
	void PushLink(BST_node*& node1, BST_node*& node2);
	void PushBtn(Button* &btn);
	void PushTxtBox(TextBox*& TxtBox);

	int cnt=0;

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
