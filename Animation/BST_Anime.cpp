#include "BST_Anime.h"

BST_Anime::BST_Anime() {
	
}

BST_Anime::~BST_Anime()
{
	cleanUp();
}

void BST_Anime::drawFrame(RenderTarget& target,int id) const
{
	if (id>-1 && AnimeFrameNode.size()>id)
	{
		for (auto a : AnimeFrameLink[id]) target.draw(*a);

		for (auto a : AnimeFrameNode[id]) target.draw(*a);
	}
}
//create a an empty frame
void BST_Anime::MakeNewFrame()
{
	vector<TreeNode*> tmp{};
	AnimeFrameNode.push_back(tmp);

	n = AnimeFrameNode.size();
	
	vector<Edge*> pmt{};
	AnimeFrameLink.push_back(pmt);
}

//make a vector copy of the tree before the change
void BST_Anime::copyFirstTree(vector <BST_node*> &org,int pos)
{
	FirstPos = pos; 
	
	for (auto a : org)
	{
		BST_node* tmp = new BST_node;
		tmp->data = a->data;
		tmp->vectorPos = a->vectorPos;
		tmp->isLeft = a->isLeft;
		NodeVectorFirst.push_back(tmp);
	}

	for (int i=0;i<org.size();i++)
	{
		//cout << " healp 1 ";
		//cout << NodeVectorFirst[i]->data << " " << NodeVectorFirst.size() << endl;
		//cout << " " << i;

		if (org[i]->left) NodeVectorFirst[i]->left = NodeVectorFirst[org[i]->left->vectorPos];// , cout << " l " << NodeVectorFirst[i]->left->vectorPos << "; ";
		if (org[i]->right) NodeVectorFirst[i]->right = NodeVectorFirst[org[i]->right->vectorPos];// , cout << " r " << NodeVectorFirst[i]->right->vectorPos << "; ";
		if (org[i]->par) NodeVectorFirst[i]->par = NodeVectorFirst[org[i]->par->vectorPos];// , cout << " p " << NodeVectorFirst[i]->par->vectorPos << "; ";
		//cout << endl;
	}

	cout << " con 1 " << endl;	
	print_console(NodeVectorFirst[pos], "", 1);
	cout << endl;

	makeLinkLevel(NodeVectorFirst[pos]);
}

//make a vector copy of the tree after the change
void BST_Anime::copySecondTree(vector <BST_node*>& org,int pos)
{
	SecondPos = pos;

	for (auto a : org)
	{
		BST_node* tmp = new BST_node;
		tmp->data = a->data;
		tmp->vectorPos = a->vectorPos;
		tmp->isLeft = a->isLeft;
		NodeVectorSecond.push_back(tmp);
	}

	for (int i = 0; i < org.size(); i++)
	{
		/*cout << " healp 2 ";
		cout << NodeVectorSecond[i]->data << " " << NodeVectorSecond.size() << endl;
		cout << " " << i ;*/

		if (org[i]->left) NodeVectorSecond[i]->left = NodeVectorSecond[org[i]->left->vectorPos];// , cout << " l " << NodeVectorSecond[i]->left->vectorPos << "; ";
		if (org[i]->right) NodeVectorSecond[i]->right = NodeVectorSecond[org[i]->right->vectorPos];//, cout << " r " << NodeVectorSecond[i]->right->vectorPos << "; ";
		if (org[i]->par) NodeVectorSecond[i]->par = NodeVectorSecond[org[i]->par->vectorPos];// , cout << " p " << NodeVectorSecond[i]->par->vectorPos << "; ";

		//cout << endl;
	}	

	cout << " sqw 2  " << endl;
	print_console(NodeVectorSecond[pos], "", 1);
	cout << endl;
}

//create a display_node copy of the tree before change
void BST_Anime::CloneFromTree(SceneNode* &Nodes)
{
	cleanUp(); 

	MakeNewFrame(); 

	for (auto a : Nodes->Children)
	{
		shared_ptr<TreeNode> treeNode = dynamic_pointer_cast<TreeNode>(a); 

		TreeNode* tmp = new TreeNode(noType,"",0);
		tmp->Cir = treeNode->Cir;
		tmp->text = treeNode->text;

		AnimeFrameNode.back().push_back(tmp); 

		//string s = tmp->text.getString(); 

	}
}

void BST_Anime::drawCurrent(RenderTarget& target, RenderStates states) const 
{
	cout << "Sf " << curFrame << endl;
	if (curFrame >= AnimeFrameNode.size()) return;

	drawFrame(target,curFrame);
}

void BST_Anime::updateCurrent(Event& event, Vector2f& MousePos)
{
	
}

void BST_Anime::takeTimeCurrent(Time& dt)
{
	timeCnt += dt;

	if (timeCnt >= TIME_PER_ANIME_FRAME) curFrame=min(n-1, curFrame+1);
}

// make Link between node for the last frame
void BST_Anime::makeLinkLevel(BST_node*& Cur)
{
	if (!Cur) return;

	if (Cur->left)
	{
		AnimeFrameLink.back().push_back(makeLink(Cur,Cur->left));
		makeLinkLevel(Cur->left);
	}

	if (Cur->right)
	{
		AnimeFrameLink.back().push_back(makeLink(Cur, Cur->right));
		makeLinkLevel(Cur->right);
	}
}

Edge* BST_Anime::makeLink(BST_node*& node1, BST_node*& node2)
{
	Edge* tmp = new Edge(noType, "", nothing);
	tmp->setPositionByNode(AnimeFrameNode.back()[node1->vectorPos]->getPosition(), AnimeFrameNode.back()[node2->vectorPos]->getPosition());

	return tmp;
}

// Anime Making 

void BST_Anime::MakeInsertAnime(int data)
{

}

void BST_Anime::MakeDeleteAnime(int data, SceneNode*& Nodes, vector <BST_node*>& org, int pos)
{
	CloneFromTree(Nodes); 
	copyFirstTree(org, pos); 

	BST_node* cur = NodeVectorFirst[FirstPos];
	BST_node* par = NodeVectorFirst[FirstPos];

	curFrame = 0;

	while (1)
	{
		if (!cur || cur->data == data) return;

		CloneLastFrame();
		AnimeFrameNode.back()[cur->vectorPos]->Cir.setOutlineColor(cyan);

		CloneLastFrame();
		if (par!=cur) AnimeFrameLink.back().push_back(makeLink(par, cur));
		AnimeFrameLink.back().back()->line.setFillColor(cyan);

		par = cur;
		 
		if (cur->data > data) cur = cur->left; else
			if (cur->data < data) cur = cur->right; 			
	}


}


void BST_Anime::RecreateVisual(int id,BST_node*& Cur, int& cnt, BST_node*& parent, bool isLeft,float BeginPosX)
{
	if (!Cur) return;

	if (parent != Cur)
	{
		Cur->par = parent;
		Cur->level = parent->level + 1;
	}
	else Cur->level = 1;

	Cur->isLeft = isLeft;

	if (Cur->left)
	{
		RecreateVisual(id,Cur->left, cnt, Cur, true, BeginPosX);
	}


	if (Cur->right)
	{
		RecreateVisual(id,Cur->right, cnt, Cur, false, BeginPosX);

	}

	return;
}

void BST_Anime::CloneLastFrame()
{
	MakeNewFrame();

	for (auto a : AnimeFrameNode[n-2])
	{
		TreeNode* tmp = new TreeNode(noType, "", 0);
		tmp->Cir = a->Cir;
		tmp->text = a->text;

		AnimeFrameNode.back().push_back(tmp);
	}

	for (auto a : AnimeFrameLink[n - 2])
	{
		Edge* tmp = new Edge(noType, "", 0);
		tmp->line = a->line;
		tmp->text = a->text;

		AnimeFrameLink.back().push_back(tmp);
	}
}

void BST_Anime::print_console(BST_node* cur, string prefix, bool isLeft)
{
	if (!cur) return;

	if (isLeft) cout << "|--"; else cout << "`--";

	cout << cur->data << endl;

	if (cur->left) cout << "   " + prefix;
	print_console(cur->left, cur->right ? prefix + "|  " : prefix + "   ", 1);

	if (cur->right) cout << "   " + prefix;
	print_console(cur->right, prefix + "   ", 0);
}

void BST_Anime::DelAll(BST_node*& Root)
{
	if (!Root) return;

	BST_node* tmp = Root;

	DelAll(tmp->left);
	DelAll(tmp->right);

	delete tmp;
}

void BST_Anime::cleanUp()
{
	if (!NodeVectorFirst.empty()) DelAll(NodeVectorFirst[FirstPos]);
	if (!NodeVectorSecond.empty()) DelAll(NodeVectorSecond[SecondPos]);

	for (auto a : AnimeFrameNode) for (auto b : a)	delete b;
	for (auto a : AnimeFrameLink) for (auto b : a)	delete b;

	AnimeFrameNode.clear();
	AnimeFrameLink.clear();
	AnimeNodePos.clear();

	NodeVectorFirst.clear();
	NodeVectorSecond.clear();

	int n = 0;
	int FirstPos = 0;
	int SecondPos = 0;
}
