#include "../Tools/SceneNode.h"
#include "../Tools/TreeNode.h"
#include "../Tools/Edge.h"

#pragma once

struct AVL_node
{
	int data = nothing;
	int level = 1;

	int height = 0;
	int BalanceFactor = 0;

	AVL_node* left = NULL;
	AVL_node* right = NULL;
	AVL_node* par = NULL;

	bool isLeft = true;

	int vectorPos = -1;

	shared_ptr <TreeNode> tVisual = NULL;
};

class AVL_Anime : public SceneNode
{
public:

	AVL_Anime();
	virtual ~AVL_Anime();

	vector<AVL_node*> NodeVectorFirst;

	int FirstPos = 0;

	//vector<vector<int>> AnimeNodePos;
	vector <int> AnimeNodePos;

	vector <vector<TreeNode*>> AnimeFrameNode;
	vector <vector<vector<Edge*>>> AnimeLinkMatrix;

	vector <TreeNode*> TransitionNode;
	vector <Edge*> TransitionLink;

	bool isAdditionial = 0;

	//vector <[N][N]>

	int n = 0;
	int curFrame = 0;

	float transProgress = 0;
	bool isPlaying = 0;
	bool isHavingAnime = 0;

	Time timeCnt = sf::seconds(0.f);

	//inheritance
	virtual void drawCurrent(RenderTarget& target, RenderStates states) const;

	virtual void updateCurrent(Event& event, Vector2f& MousePos);

	virtual void takeTimeCurrent(Time& dt);

	//Functions

	void drawFrame(RenderTarget& target, int id) const;
	void drawTrans(RenderTarget& target) const;

	void copyFirstTree(vector <AVL_node*>& org, int pos);

	void MakeNewFrame();

	void CloneFromTree(SceneNode*& Nodes);
	void CloneLastFrame();

	void makeLinkLevel(AVL_node*& Cur);
	Edge* makeLink(AVL_node*& node1, AVL_node*& node2, Color color);
	void changeLink(AVL_node*& node1, AVL_node*& node2, Color color);

	void ChooseFrame(int i);

	// Anime maker

	void MakeInsertAnime(int data, SceneNode*& Nodes, vector <AVL_node*>& org, int pos, int n);
	void MakeDeleteAnime(int data, SceneNode*& Nodes, vector <AVL_node*>& org, int pos, int n);
	void MakeSearchAnime(int data, SceneNode*& Nodes, vector <AVL_node*>& org, int pos, int n);

	void makeTransition();

	TreeNode* InterpolateNode(TreeNode* a, TreeNode* b, float t);
	Edge* InterpolateEdge(Edge* a, Edge* b, float t);

	void print_console(AVL_node* cur, string prefix, bool isLeft);

	void RecreateVisual(int id, AVL_node*& Cur, int& cnt, AVL_node*& parent, bool isLeft, float BeginPosX);

	void DelAll(AVL_node*& Root);

	void cleanUp();
};

