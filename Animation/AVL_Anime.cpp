#include "AVL_Anime.h"

AVL_Anime::AVL_Anime() {
	
}

AVL_Anime::~AVL_Anime()
{
	cleanUp();
}

void AVL_Anime::ChooseFrame(int i)
{
	curFrame += i;
	curFrame = min((int) AnimeFrameNode.size(), max(0, curFrame));
	isPlaying = 0;
}

void AVL_Anime::drawFrame(RenderTarget& target,int id) const
{
	if (id>-1 && AnimeFrameNode.size()>id)
	{
		for (auto a : AnimeFrameLink[id]) target.draw(*a);

		for (auto a : AnimeFrameNode[id]) target.draw(*a);
	}
}
//create a an empty frame
void AVL_Anime::MakeNewFrame()
{
	vector<TreeNode*> tmp{};
	AnimeFrameNode.push_back(tmp);

	n = AnimeFrameNode.size();
	
	vector<Edge*> pmt{};
	AnimeFrameLink.push_back(pmt);

	
}

//make a vector copy of the tree before the change
void AVL_Anime::copyFirstTree(vector <AVL_node*> &org,int pos)
{
	FirstPos = pos; 
	
	for (auto a : org)
	{
		AVL_node* tmp = new AVL_node;
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
void AVL_Anime::copySecondTree(vector <AVL_node*>& org,int pos)
{
	SecondPos = pos;

	for (auto a : org)
	{
		AVL_node* tmp = new AVL_node;
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
void AVL_Anime::CloneFromTree(SceneNode* &Nodes)
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
	}
}

void AVL_Anime::drawCurrent(RenderTarget& target, RenderStates states) const 
{
	if (curFrame >= AnimeFrameNode.size()) return;

	drawFrame(target,curFrame);
}

void AVL_Anime::updateCurrent(Event& event, Vector2f& MousePos)
{
}

void AVL_Anime::takeTimeCurrent(Time& dt)
{
	
	if (!isHavingAnime) isPlaying = 0;

	if (!isPlaying) return;	

	timeCnt += dt;

	if (timeCnt >= TIME_PER_ANIME_FRAME) curFrame = min((int) AnimeFrameNode.size(), curFrame + 1), timeCnt -= TIME_PER_ANIME_FRAME;
}

// make Link between node for the last frame
void AVL_Anime::makeLinkLevel(AVL_node*& Cur)
{
	if (!Cur) return;

	if (Cur->left)
	{
		makeLink(Cur, Cur->left, black);
		makeLinkLevel(Cur->left);
	}

	if (Cur->right)
	{
		makeLink(Cur, Cur->right, black);
		makeLinkLevel(Cur->right);
	}
}

void AVL_Anime::makeLink(AVL_node*& node1, AVL_node*& node2,Color color)
{
	if (!node1 || !node2) return;

	if (node1 == node2) return;
	Edge* tmp = new Edge(noType, "", nothing);
	tmp->setPositionByNode(AnimeFrameNode.back()[node1->vectorPos]->getPosition(), AnimeFrameNode.back()[node2->vectorPos]->getPosition());
	tmp->line.setFillColor(color);

	AnimeFrameLink.back().push_back(tmp);
}

// Anime Making 

void AVL_Anime::MakeInsertAnime(int data)
{

}

void AVL_Anime::MakeDeleteAnime(int data, SceneNode*& Nodes, vector <AVL_node*>& org, int pos)
{
	isPlaying = 1;
	isHavingAnime = 1;

	cout << "anime delete " << endl;

	CloneFromTree(Nodes); 
	copyFirstTree(org, pos); 

	AVL_node* cur = NodeVectorFirst[FirstPos];
	AVL_node* par = NodeVectorFirst[FirstPos];

	curFrame = 0;

	while (1) // find node
	{
		if (!cur || cur->data == data) break;

		if (par != cur)
		{
			CloneLastFrame();
			makeLink(par, cur,Chosen_Color);
		}

		CloneLastFrame();
		AnimeFrameNode.back()[cur->vectorPos]->Cir.setOutlineColor(Chosen_Color);		

		par = cur;
		 
		if (cur->data > data) cur = cur->left; else
			if (cur->data < data) cur = cur->right; 			
	}

	if (!cur) // no node matches data
	{
		cout << " dit me m xoa cc" << endl;
	}
	else  // choose and delete
	{
		if (par != cur)
		{
			CloneLastFrame();
			makeLink(par, cur, Chosen_Color);
		}

		CloneLastFrame();
		AnimeFrameNode.back()[cur->vectorPos]->Cir.setOutlineColor(Chosen_Color);

		CloneLastFrame();
		AnimeFrameNode.back()[cur->vectorPos]->Cir.setOutlineColor(Delete_Color);

		

		if (!cur->left && !cur->right) // delete leave node
		{
			CloneLastFrame();
			AnimeFrameNode.back()[cur->vectorPos]->Disable();
			makeLink(par, cur, Back_Ground_Color);
		} else

		if (cur->left && cur->right) // delete node that have 2 children
		{
			AVL_node* parTmp = cur;
			AVL_node* tmp = cur->left;

			CloneLastFrame();
			makeLink(parTmp, tmp,Chosen_Color);

			CloneLastFrame();
			AnimeFrameNode.back()[tmp->vectorPos]->Cir.setOutlineColor(Chosen_Color);

			while (tmp->right)// go down
			{
				parTmp = tmp;
				tmp = tmp->right;

				CloneLastFrame();
				makeLink(parTmp, tmp,Chosen_Color);
				
				CloneLastFrame();
				AnimeFrameNode.back()[tmp->vectorPos]->Cir.setOutlineColor(Chosen_Color);
			}

			CloneLastFrame(); // link to the rightest left
			
			if (parTmp == cur) // thang the cur la con trai (cur->left==tmp)
			{
				makeLink(par, cur, Back_Ground_Color);
				makeLink(cur, cur->right, Back_Ground_Color);
				makeLink(cur, cur->left, Back_Ground_Color);

				makeLink(par, tmp, Chosen_Color);
				makeLink(tmp, cur->right,Chosen_Color);
			}
			else  // binh thuong
			{
				makeLink(par, cur, Back_Ground_Color);
				makeLink(cur, cur->right, Back_Ground_Color);
				makeLink(cur, cur->left, Back_Ground_Color);
				makeLink(parTmp, tmp, Back_Ground_Color);
				makeLink(tmp, tmp->left, Back_Ground_Color);

				makeLink(parTmp, tmp->left, Chosen_Color);
				makeLink(par, tmp, Chosen_Color);
				makeLink(cur->right, tmp, Chosen_Color);
				makeLink(cur->left, tmp, Chosen_Color);
			}

			CloneLastFrame(); // move it

			if (parTmp == cur)
			{
				for (int i = 0; i < 2; i++) AnimeFrameLink.back().pop_back();

				makeLink(tmp, tmp->left, Back_Ground_Color);
			}
			else
			{
				for (int i = 0; i < 3; i++) AnimeFrameLink.back().pop_back();

			}
			
			Vector2f tmpOldPos = AnimeFrameNode.back()[tmp->vectorPos]->getPosition();
			AnimeFrameNode.back()[cur->vectorPos]->Disable(); // xoa cai node
			AnimeFrameNode.back()[tmp->vectorPos]->setPosition(AnimeFrameNode.back()[cur->vectorPos]->getPosition()); //flip node duoi len

			makeLink(par, tmp, Chosen_Color);
			makeLink(tmp, cur->right, Chosen_Color);

			if (parTmp == cur) makeLink(tmp, tmp->left, Chosen_Color);
			else makeLink(tmp, cur->left, Chosen_Color);
			

		}
		else
			if (cur->left)   // have left child
			{
				AVL_node* tmp = cur->left;

				CloneLastFrame();
				makeLink(cur, tmp,Chosen_Color);

				CloneLastFrame();
				AnimeFrameNode.back()[tmp->vectorPos]->Cir.setOutlineColor(Chosen_Color);

				CloneLastFrame();
				AnimeFrameNode.back()[cur->vectorPos]->Disable();
				makeLink(par, cur,Back_Ground_Color);
				makeLink(cur, tmp,Back_Ground_Color);

				makeLink(par, tmp,Chosen_Color);
			}
			else			// have right child
			{
				AVL_node* tmp = cur->right;
				
				CloneLastFrame();
				makeLink(cur, tmp,Chosen_Color);

				CloneLastFrame();
				AnimeFrameNode.back()[tmp->vectorPos]->Cir.setOutlineColor(Chosen_Color);

				CloneLastFrame();
				AnimeFrameNode.back()[cur->vectorPos]->Disable();
				makeLink(par, cur,Back_Ground_Color);
				makeLink(cur, tmp,Back_Ground_Color);

				makeLink(par, tmp,Chosen_Color);
			}
	}
}


void AVL_Anime::RecreateVisual(int id,AVL_node*& Cur, int& cnt, AVL_node*& parent, bool isLeft,float BeginPosX)
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

void AVL_Anime::CloneLastFrame()
{
	MakeNewFrame();

	/*for (auto a : AnimeFrameNode[n-2])
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
	}*/

	
}

void AVL_Anime::print_console(AVL_node* cur, string prefix, bool isLeft)
{
	if (!cur) return;

	if (isLeft) cout << "|--"; else cout << "`--";

	cout << cur->data << endl;

	if (cur->left) cout << "   " + prefix;
	print_console(cur->left, cur->right ? prefix + "|  " : prefix + "   ", 1);

	if (cur->right) cout << "   " + prefix;
	print_console(cur->right, prefix + "   ", 0);
}

void AVL_Anime::DelAll(AVL_node*& Root)
{
	if (!Root) return;

	AVL_node* tmp = Root;

	DelAll(tmp->left);
	DelAll(tmp->right);

	delete tmp;
}

void AVL_Anime::cleanUp()
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
