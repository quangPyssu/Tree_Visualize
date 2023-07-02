#include "../Tools/SceneNode.h"
#include "../Tools/TreeNode.h"
#include "../Tools/Edge.h"

#pragma once

struct BST_node
{
	int data = nothing;
	int level = 1;

	BST_node* left = NULL;
	BST_node* right = NULL;
	BST_node* par = NULL;

	bool isLeft = true;

	int vectorPos = -1;

	shared_ptr <TreeNode> tVisual;
};

class BST_Anime : public SceneNode
{
public:

	BST_Anime();
	virtual ~BST_Anime();

	vector<BST_node*> NodeVectorFirst;
	vector<BST_node*> NodeVectorSecond;

	int FirstPos = 0;
	int SecondPos = 0;

	//vector<vector<int>> AnimeNodePos;
	vector <int> AnimeNodePos;

	vector <vector<TreeNode*>> AnimeFrameNode;
	vector <vector<Edge*>> AnimeFrameLink;

	int n=0;
	int curFrame = 0;
	bool isHavingAnime = 0;

	Time timeCnt = sf::seconds(0.f);

	//inheritance
	virtual void drawCurrent(RenderTarget& target, RenderStates states) const  ;

	virtual void updateCurrent(Event& event, Vector2f& MousePos) ;

	virtual void takeTimeCurrent(Time& dt) ;

	//Functions

	void drawFrame(RenderTarget& target,int id) const;

	void copyFirstTree(vector <BST_node*>& org,int pos);
	void copySecondTree(vector <BST_node*>& org,int pos);

	void MakeNewFrame();
	
	void CloneFromTree(SceneNode* &Nodes);
	void CloneLastFrame();

	void makeLinkLevel(BST_node* &Cur);
	Edge* makeLink(BST_node* &node1, BST_node*& node2);

	// Anime maker

	void MakeInsertAnime(int data);
	void MakeDeleteAnime(int data, SceneNode*& Nodes, vector <BST_node*>& org, int pos);

	void print_console(BST_node* cur, string prefix, bool isLeft);

	void RecreateVisual(int id,BST_node*& Cur, int& cnt, BST_node*& parent, bool isLeft,float BeginPosX);

	void DelAll(BST_node*& Root);

	void cleanUp();
};

