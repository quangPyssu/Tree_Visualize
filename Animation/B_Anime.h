#include "AnimeBase.h"
#include "../Tools/SceneNode.h"
#include "../Tools/TreeNode.h"
#include "../Tools/Edge.h"

#pragma once

struct B_node
{
	B_node(bool isLeaf);

	int level = 0;
	int nKey = 0;

	vector <int> data;
	vector <B_node*> childs;
	
	bool isLeaf = 0;

	int vectorPos = -1;
	
	vector <shared_ptr <TreeNode>> tVisual;

	void splitChild(int i, B_node* y);

	void insertNonFull(int data);

	void printConsole(B_node* cur);

	Vector2f middlePos();
};

class B_Anime : public AnimeBase
{
public:

	B_Anime();
	virtual ~B_Anime();

	vector<B_node*> NodeVectorFirst;

	int FirstPos = 0;
	

	//vector <[N][N]>

	//Functions

	void copyFirstTree(vector <B_node*>& org, int pos);
	void MakeNewFrame();

	void CloneFromTree(SceneNode*& Nodes);

	void makeLinkLevel(B_node*& Cur);
	void breakLinkLevel();
	Edge* makeLink(B_node*& node1, B_node*& node2, Color color);
	void changeLink(B_node*& node1, B_node*& node2, Color color);

	// Anime maker

	void MakeInsertAnime(int data, SceneNode*& Nodes, vector <B_node*>& org, int pos, int n);
	void MakeDeleteAnime(int data, SceneNode*& Nodes, vector <B_node*>& org, int pos, int n);
	void MakeUpdateAnime(int dataDel,int dataAdd, SceneNode*& Nodes, vector <B_node*>& org, int pos, int n);
	void MakeUpdateAddin(int data);
	void MakeSearchAnime(int data, SceneNode*& Nodes, vector <B_node*>& org, int pos, int n);

	void ReposAfter(B_node* cur,int& cnt,int level,bool isLeft);

	void cleanUp();
};

