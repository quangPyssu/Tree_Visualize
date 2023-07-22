#include "B_Anime.h"

B_Anime::B_Anime() : AnimeBase()
{
	{	//setup code
		/*vector <CodeBox*> a;

		a.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - 380,WINDOW_HEIGHT - 40 * 2 - 35 * 6.f }, { 380,35 }, "insert v", purple, black, Left));
		a.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - a.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35 * 5.f }, a.back()->size, "check balance factor of this and its children", purple, black, Left));
		a.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - a.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35 * 4.f }, a.back()->size, "		case1: this.rotateRight", purple, black, Left));
		a.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - a.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35 * 3.f }, a.back()->size, "		case2: this.left.rotateLeft, this.rotateRight", purple, black, Left));
		a.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - a.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35 * 2.f }, a.back()->size, "		case3: this.rotateLeft", purple, black, Left));
		a.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - a.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35.f }, a.back()->size, "		case4: this.right.rotateRight, this.rotateLeft", purple, black, Left));
		a.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - a.back()->size.x,WINDOW_HEIGHT - 40 * 2.f }, a.back()->size, "		 this is balanced", purple, black, Left));

		FakeCodes.push_back(a);

		vector <CodeBox*> b;

		b.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - 380,WINDOW_HEIGHT - 40 * 2 - 35 * 6.f }, { 380,35 }, "remove v", purple, black, Left));
		b.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - b.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35 * 5.f }, b.back()->size, "check balance factor of this and its children", purple, black, Left));
		b.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - b.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35 * 4.f }, b.back()->size, "		case1: this.rotateRight", purple, black, Left));
		b.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - b.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35 * 3.f }, b.back()->size, "		case2: this.left.rotateLeft, this.rotateRight", purple, black, Left));
		b.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - b.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35 * 2.f }, b.back()->size, "		case3: this.rotateLeft", purple, black, Left));
		b.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - b.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35.f }, b.back()->size, "		case4: this.right.rotateRight, this.rotateLeft", purple, black, Left));
		b.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - b.back()->size.x,WINDOW_HEIGHT - 40 * 2.f }, b.back()->size, "		 this is balanced", purple, black, Left));

		FakeCodes.push_back(b);

		vector <CodeBox*> c;

		c.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - 380,WINDOW_HEIGHT - 40 * 2 - 35 * 6.f }, { 380,35 }, "if this == null", purple, black, Left));
		c.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - c.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35 * 5.f }, c.back()->size, "  return null", purple, black, Left));
		c.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - c.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35 * 4.f }, c.back()->size, "else if this key == search value", purple, black, Left));
		c.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - c.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35 * 3.f }, c.back()->size, " return this", purple, black, Left));
		c.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - c.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35 * 2.f }, c.back()->size, "else if this key < search value", purple, black, Left));
		c.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - c.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35.f }, c.back()->size, "  search rightt", purple, black, Left));
		c.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - c.back()->size.x,WINDOW_HEIGHT - 40 * 2.f }, c.back()->size, "else search left", purple, black, Left));

		FakeCodes.push_back(c);

		vector <CodeBox*> d;

		d.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - 380,WINDOW_HEIGHT - 40 * 2 - 35 * 6.f }, { 380,35 }, "remove v then insert", purple, black, Left));
		d.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - d.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35 * 5.f }, d.back()->size, "check dalance factor of this and its children", purple, black, Left));
		d.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - d.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35 * 4.f }, d.back()->size, "		case1: this.rotateRight", purple, black, Left));
		d.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - d.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35 * 3.f }, d.back()->size, "		case2: this.left.rotateLeft, this.rotateRight", purple, black, Left));
		d.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - d.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35 * 2.f }, d.back()->size, "		case3: this.rotateLeft", purple, black, Left));
		d.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - d.back()->size.x,WINDOW_HEIGHT - 40 * 2 - 35.f }, d.back()->size, "		case4: this.right.rotateRight, this.rotateLeft", purple, black, Left));
		d.push_back(new CodeBox({ WINDOW_WIDTH - 30.f - d.back()->size.x,WINDOW_HEIGHT - 40 * 2.f }, d.back()->size, "		 this is dalanced", purple, black, Left));

		FakeCodes.push_back(d);*/
	}

}

B_Anime::~B_Anime()
{
	cleanUp();
}

B_node::B_node(bool isLeaf)
{
	this->isLeaf = isLeaf;

	for (int i = 0; i < T ; i++) data.push_back(0), childs.push_back(NULL);

	childs.push_back(NULL);

	for (int i = 0; i < T; i++) tVisual.push_back(NULL);

	nKey = 0;
}

void B_node::splitChild(int i, B_node* y)
{
	// Create a new node which sibling

	B_node* z = new B_node(y->isLeaf);
	z->nKey = 1;

	// Copy the last keys of y to z
	z->data[0] = y->data[2];

	// Copy the last t children of y to z
	if (!y->isLeaf)
	{
		z->childs[0] = y->childs[2];
		z->childs[1] = y->childs[3];
	}

	// Reduce the number of keys in y
	y->nKey = 1;

	// create space of new child for this and move one slot ahead
	for (int j = nKey; j >= i + 1; j--)	childs[j+1] = childs[j];

	// Link the new child to this node
	childs[i + 1] = z;

	// new data and move all greater keys one slot ahead
	for (int j = nKey-1; j >= i; j--) data[j+1] = data[j];

	// Copy the middle key of y to this node
	data[i] = y->data[1];

	// Increment count of keys in this node
	nKey++;
}

void B_node::insertNonFull(int data)
{
	// Initialize index as index of rightmost element
	int i = nKey - 1;

	if (isLeaf)
	{
		// The following loop does two things
		// Finds the location of new key to be inserted & Moves all greater keys to one place ahead
		while (i >= 0 && this->data[i] > data)
		{
			this->data[i + 1] =this->data[i];
			i--;
		}

		// Insert the new key at found location
		this->data[i + 1] = data;
		nKey = nKey ++;
	}
	else // If this node is not leaf
	{
		// Find the child which is going to have the new key
		while (i >= 0 && this->data[i] > data)
			i--;

		if (childs[i + 1]->nKey == T) // If the child is full, then split it
		{			
			splitChild(i + 1, childs[i + 1]);

			if (this->data[i + 1] < data) i++;
		}

		childs[i + 1]->insertNonFull(data);
	}
}

void B_node::printConsole(B_node* cur)
{
	int i;
	for (i = 0; i < nKey; i++)
	{
		if (!isLeaf) childs[i]->printConsole(childs[i]);
		cout << " " << data[i];
	}

	// Print the subtree rooted with last child
	if (!isLeaf) childs[i]->printConsole(childs[i]);
}

Vector2f B_node::middlePos()
{
	if (!nKey) return { 0,0 };
	float a = (tVisual[0]->Cir.getPosition().x+ tVisual[nKey-1]->Cir.getPosition().x)/2.f;

	return {a,NODE_POS_HEAD + ((NODE_DISTANCE * 2) * level)-NODE_RADIUS/2.f };
}

//create a an empty frame
void B_Anime::MakeNewFrame()
{
	vector<TreeNode*> tmp{};
	AnimeFrameNode.push_back(tmp);

	vector<vector<Edge*>> pmt{};
	AnimeLinkMatrix.push_back(pmt);

	for (int i = 0; i < n; i++)
	{
		vector<Edge*> vvv;
		AnimeLinkMatrix.back().push_back(vvv);

		for (int j = 0; j < n; j++)
			AnimeLinkMatrix.back().back().push_back(NULL);
	}
}

//make a vector copy of the tree before the change
void B_Anime::copyFirstTree(vector <B_node*>& org, int pos)
{
	FirstPos = pos;

	for (auto a : org)
	{
		/*B_node* tmp = new B_node(;
		tmp->data = a->data;
		tmp->vectorPos = a->vectorPos;
		NodeVectorFirst.push_back(tmp);*/
	}

	for (int i = 0; i < org.size(); i++)
	{
		//cout << " healp 1 ";
		//cout << NodeVectorFirst[i]->data << " " << NodeVectorFirst.size() << endl;
		//cout << " " << i;

		
		//if (org[i]->par) NodeVectorFirst[i]->par = NodeVectorFirst[org[i]->par->vectorPos];// , cout << " p " << NodeVectorFirst[i]->par->vectorPos << "; ";
		//cout << endl;
	}

	n = org.size();

	cout << " con 1 " << endl;
	cout << endl;

	makeLinkLevel(NodeVectorFirst[pos]);
}

//create a display_node copy of the tree before change
void B_Anime::CloneFromTree(SceneNode*& Nodes)
{
	if (n >= 20) isBig = true; else isBig = false;

	cleanUp();

	MakeNewFrame();

	for (auto a : Nodes->Children)
	{
		shared_ptr<TreeNode> treeNode = dynamic_pointer_cast<TreeNode>(a);

		TreeNode* tmp = new TreeNode(noType, "", 0);
		tmp->Cir = treeNode->Cir;
		tmp->text = treeNode->text;
		tmp->data = treeNode->data;

		AnimeFrameNode.back().push_back(tmp);
	}
}

// make Link between node for the last frame
void B_Anime::makeLinkLevel(B_node*& Cur)
{
	if (!Cur) return;
}

Edge* B_Anime::makeLink(B_node*& node1, B_node*& node2, Color color)
{
	if (!node1 || !node2) return NULL;

	if (node1 == node2) return NULL;
	Edge* tmp = new Edge(noType, "", nothing);
	tmp->setPositionByNode(AnimeFrameNode.back()[node1->vectorPos]->getPosition(), AnimeFrameNode.back()[node2->vectorPos]->getPosition());
	tmp->line.setFillColor(color);

	return tmp;
}

void B_Anime::changeLink(B_node*& node1, B_node*& node2, Color color)
{
	if (!node1 || !node2 || node1 == node2) return;

	Edge* tmp = AnimeLinkMatrix.back()[node1->vectorPos][node2->vectorPos];
	Edge* pmt = AnimeLinkMatrix.back()[node2->vectorPos][node1->vectorPos];

	if (tmp == NULL)
	{
		if (color == trans)
		{
			AnimeLinkMatrix.back()[node2->vectorPos][node1->vectorPos] = NULL;
			delete pmt;
		}
		else
		{
			tmp = makeLink(node1, node2, color);
			AnimeLinkMatrix.back()[node1->vectorPos][node2->vectorPos] = tmp;

			AnimeLinkMatrix.back()[node2->vectorPos][node1->vectorPos] = NULL;
			delete pmt;
		}
	}
	else
	{
		if (color == trans)
		{
			AnimeLinkMatrix.back()[node1->vectorPos][node2->vectorPos] = NULL;
			delete tmp;

			AnimeLinkMatrix.back()[node2->vectorPos][node1->vectorPos] = NULL;
			delete pmt;
		}
		else
		{
			tmp->setPositionByNode(AnimeFrameNode.back()[node1->vectorPos]->getPosition(), AnimeFrameNode.back()[node2->vectorPos]->getPosition());
			tmp->line.setFillColor(color);

			AnimeLinkMatrix.back()[node1->vectorPos][node2->vectorPos] = tmp;
		}
	}
}

void B_Anime::breakLinkLevel()
{
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
	{
		if (AnimeLinkMatrix.back()[i][j]) delete AnimeLinkMatrix.back()[i][j];
		AnimeLinkMatrix.back()[i][j] = NULL;
	}
}

// Anime Making 

void B_Anime::MakeInsertAnime(int data, SceneNode*& Nodes, vector <B_node*>& org, int pos, int n)
{
	
}

void B_Anime::MakeDeleteAnime(int data, SceneNode*& Nodes, vector <B_node*>& org, int pos, int n)
{
	
}

void B_Anime::MakeUpdateAnime(int dataDel,int dataAdd,SceneNode*& Nodes, vector <B_node*>& org, int pos, int n)
{
	
}

void B_Anime::MakeUpdateAddin(int dataAdd)
{
	
}

void B_Anime::MakeSearchAnime(int data, SceneNode*& Nodes, vector <B_node*>& org, int pos, int n)
{
	
}

void B_Anime::ReposAfter(B_node* cur, int& cnt, int level, bool isLeft)
{
	if (!cur) return;
}

// misc

void B_Anime::cleanUp()
{
	CurAnime = none;
	for (auto a : TransitionNode) delete a;
	for (auto a : TransitionLink) delete a;

	TransitionNode.clear();
	TransitionLink.clear();

	for (auto a : NodeVectorFirst) delete a;

	NodeVectorFirst.clear();

	for (auto a : AnimeFrameNode) for (auto b : a)	delete b;
	for (auto a : AnimeLinkMatrix) for (auto b : a) for (auto c : b) delete c;

	AnimeFrameNode.clear();
	AnimeLinkMatrix.clear();
	AnimeNodePos.clear();

	int n = 0;
	int FirstPos = 0;
	int SecondPos = 0;

	curFrame = 0;
	transProgress = 0;

	BeginPosX = 0;
}
