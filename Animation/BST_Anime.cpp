#include "BST_Anime.h"

BST_Anime::BST_Anime() {

}

BST_Anime::~BST_Anime()
{
	cleanUp();
}

void BST_Anime::ChooseFrame(int i)
{
	curFrame += i;
	curFrame = min((int)AnimeFrameNode.size(), max(0, curFrame));
	isPlaying = 0;
	transProgress = 0;
	timeCnt = sf::seconds(0.f);
	isHavingAnime = (curFrame < (int)AnimeFrameNode.size()) ? 1 : 0;

	/*cout << "cur " << curFrame << endl;
	cout << "play " << isPlaying << endl;
	cout << "anime " << isHavingAnime << endl;*/
}

//drawin'
void BST_Anime::drawFrame(RenderTarget& target, int id) const
{
	if (id > -1 && AnimeFrameNode.size() > id)
	{
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
			if (AnimeLinkMatrix[id][i][j] != nullptr)
				target.draw(*AnimeLinkMatrix[id][i][j]);

		for (auto a : AnimeFrameNode[id]) target.draw(*a);
	}
}

void BST_Anime::drawTrans(RenderTarget& target) const
{
	for (auto a : TransitionLink) target.draw(*a);

	for (auto a : TransitionNode) target.draw(*a);
}

//create a an empty frame
void BST_Anime::MakeNewFrame()
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
void BST_Anime::copyFirstTree(vector <BST_node*>& org, int pos)
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

	for (int i = 0; i < org.size(); i++)
	{
		//cout << " healp 1 ";
		//cout << NodeVectorFirst[i]->data << " " << NodeVectorFirst.size() << endl;
		//cout << " " << i;

		if (org[i]->left) NodeVectorFirst[i]->left = NodeVectorFirst[org[i]->left->vectorPos];// , cout << " l " << NodeVectorFirst[i]->left->vectorPos << "; ";
		if (org[i]->right) NodeVectorFirst[i]->right = NodeVectorFirst[org[i]->right->vectorPos];// , cout << " r " << NodeVectorFirst[i]->right->vectorPos << "; ";
		if (org[i]->par) NodeVectorFirst[i]->par = NodeVectorFirst[org[i]->par->vectorPos];// , cout << " p " << NodeVectorFirst[i]->par->vectorPos << "; ";
		//cout << endl;
	}

	n = org.size();

	cout << " con 1 " << endl;
	print_console(NodeVectorFirst[pos], "", 1);
	cout << endl;

	makeLinkLevel(NodeVectorFirst[pos]);
}

//create a display_node copy of the tree before change
void BST_Anime::CloneFromTree(SceneNode*& Nodes)
{
	cleanUp();

	MakeNewFrame();

	for (auto a : Nodes->Children)
	{
		shared_ptr<TreeNode> treeNode = dynamic_pointer_cast<TreeNode>(a);

		TreeNode* tmp = new TreeNode(noType, "", 0);
		tmp->Cir = treeNode->Cir;
		tmp->text = treeNode->text;

		AnimeFrameNode.back().push_back(tmp);
	}
}

void BST_Anime::drawCurrent(RenderTarget& target, RenderStates states) const
{
	if (curFrame >= AnimeFrameNode.size()) return;

	if (!isPlaying) drawFrame(target, curFrame);
	else drawTrans(target);
}

void BST_Anime::updateCurrent(Event& event, Vector2f& MousePos)
{
}

void BST_Anime::takeTimeCurrent(Time& dt)
{
	isHavingAnime = (curFrame < (int)AnimeFrameNode.size()) ? 1 : 0;

	if (!isHavingAnime) isPlaying = 0;

	if (!isPlaying) return;

	makeTransition();

	timeCnt += dt;

	if (timeCnt >= TIME_PER_ANIME_FRAME) curFrame = min((int)AnimeFrameNode.size(), curFrame + 1), timeCnt -= TIME_PER_ANIME_FRAME;

	transProgress = timeCnt / TIME_PER_ANIME_FRAME;
}

// make Link between node for the last frame
void BST_Anime::makeLinkLevel(BST_node*& Cur)
{
	if (!Cur) return;

	if (Cur->left)
	{
		auto tmp = makeLink(Cur, Cur->left, black);

		AnimeLinkMatrix.back()[Cur->vectorPos][Cur->left->vectorPos] = tmp;
		//AnimeLinkMatrix.back()[Cur->left->vectorPos][Cur->vectorPos] = tmp;
		makeLinkLevel(Cur->left);
	}

	if (Cur->right)
	{
		auto tmp = makeLink(Cur, Cur->right, black);

		AnimeLinkMatrix.back()[Cur->vectorPos][Cur->right->vectorPos] = tmp;
		//AnimeLinkMatrix.back()[Cur->right->vectorPos][Cur->vectorPos] = tmp;
		makeLinkLevel(Cur->right);
	}
}

Edge* BST_Anime::makeLink(BST_node*& node1, BST_node*& node2, Color color)
{
	if (!node1 || !node2) return NULL;

	if (node1 == node2) return NULL;
	Edge* tmp = new Edge(noType, "", nothing);
	tmp->setPositionByNode(AnimeFrameNode.back()[node1->vectorPos]->getPosition(), AnimeFrameNode.back()[node2->vectorPos]->getPosition());
	tmp->line.setFillColor(color);

	return tmp;
}

void BST_Anime::changeLink(BST_node*& node1, BST_node*& node2, Color color)
{
	if (!node1 || !node2 || node1 == node2) return;

	Edge* tmp = AnimeLinkMatrix.back()[node1->vectorPos][node2->vectorPos];
	Edge* pmt = AnimeLinkMatrix.back()[node2->vectorPos][node1->vectorPos];

	if (tmp == NULL)
	{
		if (color == trans) return; else
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

// Anime Making 

void BST_Anime::MakeInsertAnime(int data, SceneNode*& Nodes, vector <BST_node*>& org, int pos, int n)
{
	isPlaying = 1;
	isHavingAnime = 1;
	isAdditionial = 1;

	this->n = n+1;
	n++;

	cout << "anime insert " << endl;

	CloneFromTree(Nodes);

	TreeNode* tmp = new TreeNode(noType, "", data);
	tmp->Disable();
	AnimeFrameNode.back().push_back(tmp);

	copyFirstTree(org, pos);
	this->n++;

	BST_node* ttt = new BST_node;
	ttt->vectorPos = this->n - 1;
	ttt->data = data;

	NodeVectorFirst.push_back(ttt);

	BST_node* cur = NodeVectorFirst[FirstPos];
	BST_node* par = NodeVectorFirst[FirstPos];

	curFrame = 0;

	while (1) // find node
	{
		if (!cur || cur->data == data) break;

		if (par != cur)
		{
			CloneLastFrame();

			changeLink(par, cur, Chosen_Color);
		}

		CloneLastFrame();
		AnimeFrameNode.back()[cur->vectorPos]->Cir.setOutlineColor(Chosen_Color);

		par = cur;

		if (cur->data > data) cur = cur->left; else
			if (cur->data < data) cur = cur->right;
	}

	if (!cur) // find empty slot
	{
		CloneLastFrame();

		AnimeFrameNode.back().back()->Able();
	
		AnimeFrameNode.back().back()->Cir.setOutlineColor(Insert_Color);

		AnimeFrameNode.back().back()->setPosition(AnimeFrameNode.back()[par->vectorPos]->getPosition()+Vector2f(NODE_DISTANCE*2*((par->data > data) ? -1 : 1), NODE_DISTANCE));

		CloneLastFrame();

		AnimeFrameNode.back().back()->Cir.setOutlineColor(Chosen_Color);

		changeLink(par, NodeVectorFirst[n-1], Chosen_Color);
	}
	else  // already have the node
	{
		CloneLastFrame();

		if (par != cur)
		{
			CloneLastFrame();
			changeLink(par, cur, Chosen_Color);
		}

		CloneLastFrame();
		AnimeFrameNode.back()[cur->vectorPos]->Cir.setOutlineColor(Chosen_Color);

		CloneLastFrame();
		AnimeFrameNode.back()[cur->vectorPos]->Cir.setOutlineColor(Insert_Color);

		cout << " dit me m them cc" << endl;
	}
}

void BST_Anime::MakeDeleteAnime(int data, SceneNode*& Nodes, vector <BST_node*>& org, int pos, int n)
{
	isPlaying = 1;
	isHavingAnime = 1;
	isAdditionial = 0;

	this->n = n;

	cout << "anime delete " << endl;

	CloneFromTree(Nodes);
	copyFirstTree(org, pos);

	BST_node* cur = NodeVectorFirst[FirstPos];
	BST_node* par = NodeVectorFirst[FirstPos];

	curFrame = 0;

	while (1) // find node
	{
		if (!cur || cur->data == data) break;

		if (par != cur)
		{
			CloneLastFrame();

			changeLink(par, cur, Chosen_Color);
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
			changeLink(par, cur, Chosen_Color);
		}

		CloneLastFrame();
		AnimeFrameNode.back()[cur->vectorPos]->Cir.setOutlineColor(Chosen_Color);

		CloneLastFrame();
		AnimeFrameNode.back()[cur->vectorPos]->Cir.setOutlineColor(Delete_Color);

		if (!cur->left && !cur->right) // delete leave node
		{
			CloneLastFrame();
			AnimeFrameNode.back()[cur->vectorPos]->Disable();
			changeLink(par, cur, trans);
		}
		else

			if (cur->left && cur->right) // delete node that have 2 children
			{
				BST_node* parTmp = cur;
				BST_node* tmp = cur->left;

				CloneLastFrame();
				changeLink(parTmp, tmp, Chosen_Color);

				CloneLastFrame();
				AnimeFrameNode.back()[tmp->vectorPos]->Cir.setOutlineColor(Chosen_Color);

				while (tmp->right)// go down
				{
					parTmp = tmp;
					tmp = tmp->right;

					CloneLastFrame();
					changeLink(parTmp, tmp, Chosen_Color);

					CloneLastFrame();
					AnimeFrameNode.back()[tmp->vectorPos]->Cir.setOutlineColor(Chosen_Color);
				}

				CloneLastFrame(); // link to the rightest left

				changeLink(par, cur, trans);
				changeLink(cur, cur->right, trans);
				changeLink(cur, cur->left, trans);

				changeLink(par, tmp, Chosen_Color);

				if (parTmp == cur) changeLink(tmp, cur->right, Chosen_Color);// thang the cur la con trai (cur->left==tmp)
				else  // binh thuong
				{
					changeLink(parTmp, tmp, trans);
					changeLink(tmp, tmp->left, trans);

					changeLink(parTmp, tmp->left, Chosen_Color);
					changeLink(cur->right, tmp, Chosen_Color);
					changeLink(cur->left, tmp, Chosen_Color);
				}

				CloneLastFrame(); // move it

				if (parTmp == cur) changeLink(tmp, tmp->left, trans);

				changeLink(cur->right, tmp, trans);
				changeLink(cur->left, tmp, trans);

				AnimeFrameNode.back()[cur->vectorPos]->Disable(); // xoa cai node
				AnimeFrameNode.back()[tmp->vectorPos]->setPosition(AnimeFrameNode.back()[cur->vectorPos]->getPosition()); //flip node duoi len

				changeLink(par, tmp, Chosen_Color);
				changeLink(tmp, cur->right, Chosen_Color);

				if (parTmp == cur) changeLink(tmp, tmp->left, Chosen_Color);
				else changeLink(tmp, cur->left, Chosen_Color);
			}
			else
				if (cur->left)   // have left child
				{
					BST_node* tmp = cur->left;

					CloneLastFrame();
					changeLink(cur, tmp, Chosen_Color);

					CloneLastFrame();
					AnimeFrameNode.back()[tmp->vectorPos]->Cir.setOutlineColor(Chosen_Color);

					CloneLastFrame();
					AnimeFrameNode.back()[cur->vectorPos]->Disable();
					changeLink(par, cur, trans);
					changeLink(cur, tmp, trans);

					if (par!=cur) changeLink(par, tmp, Chosen_Color);
				}
				else			// have right child
				{
					BST_node* tmp = cur->right;

					CloneLastFrame();
					changeLink(cur, tmp, Chosen_Color);

					CloneLastFrame();
					AnimeFrameNode.back()[tmp->vectorPos]->Cir.setOutlineColor(Chosen_Color);

					CloneLastFrame();
					AnimeFrameNode.back()[cur->vectorPos]->Disable();
					changeLink(par, cur, trans);
					changeLink(cur, tmp, trans);

					if (par != cur) changeLink(par, tmp, Chosen_Color);
				}
	}
}

void BST_Anime::MakeSearchAnime(int data, SceneNode*& Nodes, vector <BST_node*>& org, int pos, int n)
{
	isPlaying = 1;
	isHavingAnime = 1;
	isAdditionial = 0;

	this->n = n;

	cout << "anime Search " << endl;

	CloneFromTree(Nodes);
	copyFirstTree(org, pos);

	BST_node* cur = NodeVectorFirst[FirstPos];
	BST_node* par = NodeVectorFirst[FirstPos];

	curFrame = 0;

	while (1) // find node
	{
		if (!cur || cur->data == data) break;

		if (par != cur)
		{
			CloneLastFrame();

			changeLink(par, cur, Chosen_Color);
		}

		CloneLastFrame();
		AnimeFrameNode.back()[cur->vectorPos]->Cir.setOutlineColor(Chosen_Color);

		par = cur;

		if (cur->data > data) cur = cur->left; else
			if (cur->data < data) cur = cur->right;
	}

	if (!cur) // no node matches data
	{
		cout << " dit me m tim cc" << endl;
	}
	else  // higlight the data
	{
		if (par != cur)
		{
			CloneLastFrame();
			changeLink(par, cur, Chosen_Color);
		}

		CloneLastFrame();
		AnimeFrameNode.back()[cur->vectorPos]->Cir.setOutlineColor(Chosen_Color);

		CloneLastFrame();
		AnimeFrameNode.back()[cur->vectorPos]->Cir.setOutlineColor(Search_Color);
	}
}

void BST_Anime::RecreateVisual(int id, BST_node*& Cur, int& cnt, BST_node*& parent, bool isLeft, float BeginPosX)
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
		RecreateVisual(id, Cur->left, cnt, Cur, true, BeginPosX);
	}


	if (Cur->right)
	{
		RecreateVisual(id, Cur->right, cnt, Cur, false, BeginPosX);

	}

	return;
}

// the Transition

void BST_Anime::makeTransition()
{
	if (!isPlaying || curFrame > AnimeFrameNode.size()) return;

	for (auto a : TransitionNode) delete a;
	for (auto a : TransitionLink) delete a;

	TransitionNode.clear();
	TransitionLink.clear();

	int u = curFrame;
	int v = min(curFrame+1, (int) AnimeFrameNode.size()-1);
	
	for (int i = 0; i < n; i++)	TransitionNode.push_back(InterpolateNode(AnimeFrameNode[u][i], AnimeFrameNode[v][i],transProgress));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			Edge* a = AnimeLinkMatrix[u][i][j] ? AnimeLinkMatrix[u][i][j] : AnimeLinkMatrix[u][j][i];
			Edge* b = AnimeLinkMatrix[v][i][j] ? AnimeLinkMatrix[v][i][j] : AnimeLinkMatrix[v][j][i];

			TransitionLink.push_back(InterpolateEdge(a,b,transProgress));
		}
	}
}

TreeNode* BST_Anime::InterpolateNode(TreeNode* a, TreeNode* b, float t) 
{
	TreeNode* res=new TreeNode(noType,"",0);

	res->Cir = a->Cir;
	res->text = a->text;

	int r_diff = b->Cir.getOutlineColor().r - a->Cir.getOutlineColor().r;
	int g_diff = b->Cir.getOutlineColor().g - a->Cir.getOutlineColor().g;
	int b_diff = b->Cir.getOutlineColor().b - a->Cir.getOutlineColor().b;

	int red = a->Cir.getOutlineColor().r + t * r_diff;
	int green = a->Cir.getOutlineColor().g + t * g_diff;
	int blue = a->Cir.getOutlineColor().b + t * b_diff;
	int alpha = 255;


	if (b->isDisable)
	{
		if (a->isDisable) res->Disable();
		else alpha = 255 - (255 * t);
	}	else if (a->isDisable) alpha = 0 + 255 * t;

	res->Cir.setOutlineColor(Color(red, green, blue,alpha));

	res->Cir.setPosition((1 - t) * a->Cir.getPosition() + t * b->Cir.getPosition());
	res->text.setPosition(res->Cir.getPosition().x - res->text.getGlobalBounds().width / 2.f, res->Cir.getPosition().y - res->text.getGlobalBounds().height / 2.f);
	
	return res;
}

Edge* BST_Anime::InterpolateEdge(Edge* a, Edge* b, float t)
{
	Edge* res = new Edge(noType, "", 0);

	int alpha = 255;

	if (!b)
	{
		if (!a) res->Disable();
		else
		{
			res->line = a->line;

			int r_diff = 255 - a->line.getFillColor().r;
			int g_diff = 255 - a->line.getFillColor().g;
			int b_diff = 255 - a->line.getFillColor().b;

			int red = a->line.getFillColor().r + t * r_diff;
			int green = a->line.getFillColor().g + t * g_diff;
			int blue = a->line.getFillColor().b + t * b_diff;

			alpha = 255 - (255 * t);

			res->line.setFillColor(Color(red, green, blue, alpha));
			res->setPositionByNode(a->pos1, a->pos2);
		}
	}
	else
	{
		if (!a)
		{
			int r_diff = b->line.getFillColor().r-255;
			int g_diff = b->line.getFillColor().g-255;
			int b_diff = b->line.getFillColor().b-255;

			int red = 255 + t * r_diff;
			int green = 255 + t * g_diff;
			int blue = 255 + t * b_diff;

			alpha = 0 + 255 * t;

			res->line.setFillColor(Color(red, green, blue, alpha));
			res->setPositionByNode(b->pos1, b->pos2);
		}
		else
		{
			int r_diff = b->line.getFillColor().r - a->line.getFillColor().r;
			int g_diff = b->line.getFillColor().g - a->line.getFillColor().g;
			int b_diff = b->line.getFillColor().b - a->line.getFillColor().b;

			int red = a->line.getFillColor().r + t * r_diff;
			int green = a->line.getFillColor().g + t * g_diff;
			int blue = a->line.getFillColor().b + t * b_diff;
			alpha = 255;

			res->line.setFillColor(Color(red, green, blue, alpha));

			Vector2f pos1Diff = b->pos1 - a->pos1;
			Vector2f pos2Diff = b->pos2 - a->pos2;

			res->setPositionByNode(Vector2f(a->pos1.x + pos1Diff.x * t, a->pos1.y + pos1Diff.y * t),Vector2f(a->pos2.x + pos2Diff.x * t, a->pos2.y + pos2Diff.y * t));
		}
	}

	return res;
}

// misc

void BST_Anime::CloneLastFrame()
{
	MakeNewFrame();

	for (auto a : AnimeFrameNode[AnimeFrameNode.size() - 2])
	{
		TreeNode* tmp = new TreeNode(noType, "", 0);
		tmp->Cir = a->Cir;
		tmp->text = a->text;
		tmp->isDisable = a->isDisable;

		AnimeFrameNode.back().push_back(tmp);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			Edge* tmp = nullptr;
			if (AnimeLinkMatrix[AnimeLinkMatrix.size() - 2][i][j] != nullptr)
			{
				auto a = AnimeLinkMatrix[AnimeLinkMatrix.size() - 2][i][j];
				tmp = new Edge(noType, "", 0);

				tmp->line = a->line;
				tmp->text = a->text;
				tmp->isDisable = a->isDisable;

				tmp->pos1 = a->pos1;
				tmp->pos2 = a->pos2;
			}

			AnimeLinkMatrix.back()[i][j] = tmp;
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
	for (auto a : TransitionNode) delete a;
	for (auto a : TransitionLink) delete a;

	TransitionNode.clear();
	TransitionLink.clear();

	if (!NodeVectorFirst.empty()) DelAll(NodeVectorFirst[FirstPos]);

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
}
