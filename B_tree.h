#pragma once

#include <iostream>
#include <string>
#include "Tools/Tree.h"
#include "Animation/B_Anime.h"

using namespace std;

struct B_Tree : public Tree
{
	B_Tree();
	virtual ~B_Tree();

	B_Anime* anime;

	bool is;
	float BeginPosX = 0;

	// update btn cmmmdume
	TextBox* txtUpdate;

	// Inheritance

	virtual void updateCurrent(Event& event, Vector2f& MousePos);
	virtual void takeTimeCurrent(Time& dt);

	void Disable() override;
	void Able() override;

	//function

	void CreateVisual(int Forced);
	void DestroyVisual();

	void Push(B_node*& Cur, B_node*& parent);
	void PushLink(Vector2f pos1, Vector2f pos2);
	void PushAnime(B_Anime*& anime1);

	void Obliterate();
	void Forge(int n);

	//actual tree

	int cnt = 0;

	vector <vector <B_node*>> NodeVector;

	B_node* root = NULL;

	int count_node(B_node* cur);
	
	void insertT(int data);

	B_node* Del(B_node*& cur, int data);

	B_node* Search(B_node*& cur, int data);

	void DelAll(B_node* cur);
};
