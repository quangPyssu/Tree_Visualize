#include "Graph_Anime.h"

Graph_Anime::Graph_Anime() : AnimeBase()
{
	srand(NULL);
}

Graph_Anime::~Graph_Anime()
{
	cleanUp();
}

Graph_node::Graph_node(Graph_Anime* anime)
{
	this->anime = anime;

	data = 0;

	Nodeid = -1;

	for (int i = 0; i < anime->n; i++) childs.push_back(0),Edgeid.push_back(-1);
}

void Graph_Anime::paintNode(int id,Color color)
{
	if (isAnime)
	{
		CloneLastFrame();

		if (NodeVector[id]->tVisual) NodeVector[id]->tVisual->Cir.setOutlineColor(color);
	}
}

void Graph_Anime::paintLink(int id1,int id2,Color color)
{
	if (isAnime)
	{
		CloneLastFrame(); 

		Graph_node*& a = NodeVector[id1];

		if (a->Edgeid[id2-1]!=-1 && AnimeFrameLink.back()[a->Edgeid[id2-1]])
			AnimeFrameLink.back()[a->Edgeid[id2-1]]->line.setFillColor(color);
	}
}

// Graph

void Graph_Anime::DelAll()
{
	n = 0;
	for (auto a : NodeVector) delete a;
	NodeVector.clear();
	Visited.clear();
}

void Graph_Anime::GenerateGraph(int n)
{
	DelAll();

	this->n = n;

	maxNodeCnt = maxLinkCnt = 0; 

	for (int i = 0; i < n; i++)
	{
		NodeVector.push_back(new Graph_node(this)); 
		Visited.push_back(0);

		NodeVector[i]->data = i+1; 

		if (i)
		{
			int par = (i - 1) / 2;
			if (i % 2 == 0)
			{
				if (par % 2 && par+1<i) par++; else 
				if (par % 2 == 1 && par>=0) par--;
			}

			int data = rand() % 30 + 1;

			NodeVector[i]->childs[par] = data;
			NodeVector[par]->childs[i] = data;
		}
	}

	for (int i = 0; i < n/2-1; i++)
	{
		while (1)
		{
			int a = rand() % n;
			int b = rand() % n;
			if (a == b || NodeVector[a]->childs[b]) continue;
			else
			{
				int data = rand() % 30 + 1;

				NodeVector[a]->childs[b] = data;
				NodeVector[b]->childs[a] = data;

				break;
			}
		}
	}
}

void Graph_Anime::setVis()
{
	for (int i = 0; i < n;i++) Visited[i] = 0;
}

//draw

void Graph_Anime::drawFrame(RenderTarget& target, int id) const 
{
	if (id > -1 && AnimeFrameNode.size() > id)
	{
		for (auto a : AnimeFrameLink[id]) if (a) target.draw(*a);

		for (auto a : AnimeFrameNode[id]) if (a) target.draw(*a);		
	}
}

void Graph_Anime::makeTransition()
{	
	if (!isPlaying || curFrame > AnimeFrameNode.size()) return;

	for (auto a : TransitionNode) delete a;
	for (auto a : TransitionLink) delete a;

	TransitionNode.clear();
	TransitionLink.clear(); 

	int u = curFrame;
	int v = min(curFrame + 1, (int)AnimeFrameNode.size() - 1);

	for (int i = 0; i < n; i++) TransitionNode.push_back(InterpolateNode(AnimeFrameNode[u][i].get(), AnimeFrameNode[v][i].get(), transProgress));

	for (int i = 0; i < m; i++) TransitionLink.push_back(InterpolateEdge(AnimeFrameLink[u][i], AnimeFrameLink[v][i], transProgress));
}

//create a an empty frame
void Graph_Anime::MakeNewFrame()
{
	vector<shared_ptr<TreeNode>> tmp{};
	AnimeFrameNode.push_back(tmp);

	vector<Edge*> pmt{};
	AnimeFrameLink.push_back(pmt);
}

void Graph_Anime::PushCurNode(Graph_node*& Cur, Graph_node*& parent)
{
	
}

void Graph_Anime::PushCurLink(Vector2f pos1, Vector2f pos2,int& id)
{
	Edge* tmp = new Edge(Type::Link, "", nothing);

	tmp->setPositionByNode(pos1, pos2);

	PushEdge(tmp, id);
}

void Graph_Anime::fillAllFrame()
{
	for (auto& a : AnimeFrameNode)
	{
		while (a.size() <= maxNodeCnt) a.push_back(NULL);

		for (int i = 0; i < maxNodeCnt; i++) if (!a[i])
			{
				TreeNode* tmp= new TreeNode(AVL, "", -1);
				tmp->Disable();
				shared_ptr <TreeNode> ttt(tmp);
				a[i] = ttt;
			}
	}
	n = maxNodeCnt;

	for (auto& a : AnimeFrameLink)
	{
		while (a.size() <= maxLinkCnt) a.push_back(NULL);

		for (int i = 0; i < maxLinkCnt; i++) if (!a[i])
		{
			Edge* tmp = new Edge(AVL,"",0);
			tmp->Disable();
			a[i] = tmp;
		}
	}
	m = maxLinkCnt;
}

void Graph_Anime::MakeCurState()
{
	MakeNewFrame(); //cout << "help but anime" << endl;

	cnt = 0;
	//PushCurNode(root, root);
	if (!cnt) return;

	int BottomX = 0;
}

//create a display_node copy of the tree and setup
void Graph_Anime::CloneFromTree()
{
	if (n >= 40) isBig = true; else isBig = false; 

	cleanUp();

	MakeCurState();
}

void Graph_Anime::CloneLastFrame()
{
	MakeNewFrame(); 
	for (auto& a : AnimeFrameNode[AnimeFrameNode.size() - 2])
	{
		TreeNode* tmp = new TreeNode(noType, "", 0);
		
		if (a)
		{
			tmp->Cir = a->Cir;
			tmp->text = a->text;
			tmp->AdditionalText = a->AdditionalText;
			tmp->isDisable = a->isDisable;
			tmp->data = a->data;
		}

		shared_ptr<TreeNode> ttt(tmp);
		AnimeFrameNode.back().push_back(ttt);
	}

	for (auto &a : AnimeFrameLink[AnimeFrameLink.size() - 2])
	{
		Edge* tmp = new Edge(noType, "", 0);

		if (a)
		{
			tmp->line = a->line;
			tmp->text = a->text;
			tmp->isDisable = a->isDisable;
			tmp->data = a->data;

			tmp->pos1 = a->pos1;
			tmp->pos2 = a->pos2;
		}

		AnimeFrameLink.back().push_back(tmp);
	}
}

// Anime Making 

void Graph_Anime::MakeDijsktraAnime(int id1, int id2)
{
	isPlaying = 1;
	isHavingAnime = 1;
	isAnime = 1;
	curFrame = 0;

	//CloneFromTree(Nodes);

	MakeCurState();

	fillAllFrame();
}

void Graph_Anime::MakeMinSpanAnime()
{
	isPlaying = 1;
	isHavingAnime = 1;
	isAnime = 1;
	curFrame = 0;

	//CloneFromTree(Nodes);

	//Del(data,1);
	MakeCurState();

	fillAllFrame();
}

void Graph_Anime::PushTreeNode(shared_ptr <TreeNode> &tmp, int& id)
{
	if (id == -1) id = maxNodeCnt++;

	while (AnimeFrameNode.back().size() <= id) AnimeFrameNode.back().push_back(NULL);

	AnimeFrameNode.back()[id] = tmp;
}

void Graph_Anime::PushEdge(Edge* tmp, int& id)
{
	if (id == -1) id = maxLinkCnt++;

	while (AnimeFrameLink.back().size() <= id) AnimeFrameLink.back().push_back(NULL);	

	AnimeFrameLink.back()[id] = tmp;
}

// misc

void Graph_Anime::cleanUp()
{
	CurAnime = none;
	for (auto& a : TransitionNode) delete a;
	for (auto& a : TransitionLink) delete a;

	TransitionNode.clear();
	TransitionLink.clear();

	for (auto& a : AnimeFrameNode) a.clear();
	for (auto& a : AnimeFrameLink) for (auto& b : a) delete b;

	AnimeFrameNode.clear();
	AnimeFrameLink.clear();

	n = 0;
	m = 0;

	curFrame = 0;
	transProgress = 0;

	BeginPosX = 0;

	isAnime = 0;
}
