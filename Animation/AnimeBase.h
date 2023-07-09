#include "../Tools/SceneNode.h"
#include "../Tools/TreeNode.h"
#include "../Tools/Edge.h"
#include "../Tools/Button.h"

#pragma once

class AnimeBase : public SceneNode
{
public:

	AnimeBase();
	virtual ~AnimeBase();

	// Button
	Button* btnBack;
	Button* btnForw;
	Button* btnPlay;
	Button* btnStart;
	Button* btnEnd;

	//vector<vector<int>> AnimeNodePos;
	vector <int> AnimeNodePos;

	vector <vector<TreeNode*>> AnimeFrameNode;
	vector <vector<vector<Edge*>>> AnimeLinkMatrix;

	vector <TreeNode*> TransitionNode;
	vector <Edge*> TransitionLink;

	int n = 0;
	int curFrame = 0;

	float transProgress = 0;
	bool isPlaying = 0;
	bool isHavingAnime = 0;

	float BeginPosX = 0;

	Time timeCnt = sf::seconds(0.f);

	//inheritance
	virtual void drawCurrent(RenderTarget& target, RenderStates states) const;

	virtual void updateCurrent(Event& event, Vector2f& MousePos);

	virtual void takeTimeCurrent(Time& dt);

	//Functions

	void drawFrame(RenderTarget& target, int id) const;
	void drawTrans(RenderTarget& target) const;

	void MakeNewFrame();
	void CloneLastFrame();

	void ChooseFrame(int i);

	void makeTransition();

	TreeNode* InterpolateNode(TreeNode* a, TreeNode* b, float t);
	Edge* InterpolateEdge(Edge* a, Edge* b, float t);

	virtual void cleanUp() {};
};

