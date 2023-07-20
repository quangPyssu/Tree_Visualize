#include "AVL_Anime.h"

AVL_Anime::AVL_Anime() : AnimeBase()
{
	{	//setup code
		vector <CodeBox*> a;

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

		FakeCodes.push_back(d);
	}

}

AVL_Anime::~AVL_Anime()
{
	cleanUp();
}

//create a an empty frame
void AVL_Anime::MakeNewFrame()
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
void AVL_Anime::copyFirstTree(vector <AVL_node*>& org, int pos)
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
void AVL_Anime::CloneFromTree(SceneNode*& Nodes)
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
void AVL_Anime::makeLinkLevel(AVL_node*& Cur)
{
	if (!Cur) return;

	if (Cur->left)
	{
		changeLink(Cur, Cur->left, Default_Color);
		makeLinkLevel(Cur->left);
	}

	if (Cur->right)
	{
		changeLink(Cur, Cur->right, Default_Color);
		makeLinkLevel(Cur->right);
	}
}

Edge* AVL_Anime::makeLink(AVL_node*& node1, AVL_node*& node2, Color color)
{
	if (!node1 || !node2) return NULL;

	if (node1 == node2) return NULL;
	Edge* tmp = new Edge(noType, "", nothing);
	tmp->setPositionByNode(AnimeFrameNode.back()[node1->vectorPos]->getPosition(), AnimeFrameNode.back()[node2->vectorPos]->getPosition());
	tmp->line.setFillColor(color);

	return tmp;
}

void AVL_Anime::changeLink(AVL_node*& node1, AVL_node*& node2, Color color)
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

void AVL_Anime::breakLinkLevel()
{
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
	{
		if (AnimeLinkMatrix.back()[i][j]) delete AnimeLinkMatrix.back()[i][j];
		AnimeLinkMatrix.back()[i][j] = NULL;
	}
}

// Anime Making 

void AVL_Anime::MakeInsertAnime(int data, SceneNode*& Nodes, vector <AVL_node*>& org, int pos, int n)
{
	isPlaying = 1;
	isHavingAnime = 1;
	

	this->n = n + 1;
	n++;

	cout << "anime insert " << endl;

	CloneFromTree(Nodes);

	TreeNode* tmp = new TreeNode(noType, "", data);
	tmp->Disable();
	AnimeFrameNode.back().push_back(tmp);

	copyFirstTree(org, pos);
	this->n++;
	CurAnime = aInsert;

	AVL_node* ttt = new AVL_node;
	ttt->vectorPos = this->n - 1;
	ttt->data = data;

	NodeVectorFirst.push_back(ttt);

	AVL_node* cur = NodeVectorFirst[FirstPos];
	AVL_node* par = NodeVectorFirst[FirstPos];

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
		AnimeFrameNode.back().back()->setPosition(AnimeFrameNode.back()[par->vectorPos]->getPosition() + Vector2f(NODE_DISTANCE * 2 * ((par->data > data) ? -1 : 1), NODE_DISTANCE));

		CloneLastFrame();

		AnimeFrameNode.back().back()->Able();

		CloneLastFrame();

		AnimeFrameNode.back().back()->Highlight(Insert_Color);

		CloneLastFrame();

		if (par->data > data) par->left = NodeVectorFirst.back();
		else par->right = NodeVectorFirst.back();

		AnimeFrameNode.back().back()->unHighlight();
		AnimeFrameNode.back().back()->Cir.setOutlineColor(Chosen_Color);

		changeLink(par, NodeVectorFirst[n - 1], Chosen_Color);

		BeginPosX = WINDOW_WIDTH / 2 - (NODE_DISTANCE * n);//give new pos

		int cnt = 0;
		ReposAfter(NodeVectorFirst[FirstPos], cnt,1,false);
		makeLinkLevel(NodeVectorFirst[FirstPos]);
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

void AVL_Anime::MakeDeleteAnime(int data, SceneNode*& Nodes, vector <AVL_node*>& org, int pos, int n)
{
	isPlaying = 1;
	isHavingAnime = 1;

	this->n = n;

	cout << "anime delete " << endl;

	CloneFromTree(Nodes);
	copyFirstTree(org, pos);
	CurAnime = aDelete;

	AVL_node* cur = NodeVectorFirst[FirstPos];
	AVL_node* par = NodeVectorFirst[FirstPos];

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
		AnimeFrameNode.back()[cur->vectorPos]->Highlight(Delete_Color);

		if (!cur->left && !cur->right) // delete leave node
		{
			CloneLastFrame();
			AnimeFrameNode.back()[cur->vectorPos]->Disable();
			if (par != cur)
			{
				changeLink(par, cur, trans);
				if (par->data > cur->data) par->left = NULL; else par->right = NULL;
			}
		}
		else

			if (cur->left && cur->right) // delete node that have 2 children
			{
				AVL_node* parTmp = cur;
				AVL_node* tmp = cur->left;

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

				CloneLastFrame(); // xoa cai node				

				AnimeFrameNode.back()[cur->vectorPos]->Disable(); 

				CloneLastFrame();// move it

				if (parTmp == cur) changeLink(tmp, tmp->left, trans);

				changeLink(cur->right, tmp, trans);
				changeLink(cur->left, tmp, trans);
				AnimeFrameNode.back()[tmp->vectorPos]->setPosition(AnimeFrameNode.back()[cur->vectorPos]->getPosition()); //flip node duoi len

				changeLink(par, tmp, Chosen_Color);
				changeLink(tmp, cur->right, Chosen_Color);

				if (parTmp == cur) changeLink(tmp, tmp->left, Chosen_Color);
				else changeLink(tmp, cur->left, Chosen_Color);

				CloneLastFrame(); //repos all
				if (par != cur)
				{
					if (par->data > tmp->data) par->left = tmp;
					else par->right = tmp;
				} else FirstPos = tmp->vectorPos;

				if (parTmp != cur)
				{
					parTmp->right = tmp->left;
					tmp->left = cur->left;
				}

				tmp->right = cur->right;
			}
			else              // have one child
				{
					AVL_node* tmp = cur->right ? cur->right : cur->left;

					CloneLastFrame();
					changeLink(cur, tmp, Chosen_Color);

					CloneLastFrame();
					AnimeFrameNode.back()[tmp->vectorPos]->Cir.setOutlineColor(Chosen_Color);

					CloneLastFrame();
					AnimeFrameNode.back()[cur->vectorPos]->Disable();
					changeLink(par, cur, trans);
					changeLink(cur, tmp, trans);

					if (par != cur)  //re linking real node
					{
						changeLink(par, tmp, Chosen_Color);
						if (par->data > tmp->data) par->left = tmp;
						else par->right = tmp;
					}
					else FirstPos = tmp->vectorPos;
				}
			BeginPosX = WINDOW_WIDTH / 2 - (NODE_DISTANCE * (n-1)); //give new pos
			int cnt = 0;
			ReposAfter(NodeVectorFirst[FirstPos],cnt,1,false);
			makeLinkLevel(NodeVectorFirst[FirstPos]);
	}
}

void AVL_Anime::MakeUpdateAnime(int dataDel,int dataAdd,SceneNode*& Nodes, vector <AVL_node*>& org, int pos, int n)
{
	isPlaying = 1;
	isHavingAnime = 1;

	this->n = n + 1;
	n++;

	cout << "anime Update " << endl;

	CloneFromTree(Nodes);

	TreeNode* tmp = new TreeNode(noType, "", dataAdd);
	tmp->Disable();
	AnimeFrameNode.back().push_back(tmp);

	copyFirstTree(org, pos);
	this->n++;

	AVL_node* ttt = new AVL_node;
	ttt->vectorPos = this->n - 1;
	ttt->data = dataAdd;

	NodeVectorFirst.push_back(ttt);

	AVL_node* cur = NodeVectorFirst[FirstPos];
	AVL_node* par = NodeVectorFirst[FirstPos];

	CurAnime = aUpdate;

	curFrame = 0;
	{   //Delete part
		while (1) // find node
		{
			if (!cur || cur->data == dataDel) break;

			if (par != cur)
			{
				CloneLastFrame();

				changeLink(par, cur, Chosen_Color);
			}

			CloneLastFrame();
			AnimeFrameNode.back()[cur->vectorPos]->Cir.setOutlineColor(Chosen_Color);

			par = cur;

			if (cur->data > dataDel) cur = cur->left; else
				if (cur->data < dataDel) cur = cur->right;
		}

		if (!cur) // no node matches data
		{
			cout << " dit me m xoa cc" << endl;
			return;
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
			AnimeFrameNode.back()[cur->vectorPos]->Highlight(Delete_Color);

			if (!cur->left && !cur->right) // delete leave node
			{
				CloneLastFrame();
				AnimeFrameNode.back()[cur->vectorPos]->Disable();
				if (par != cur)
				{
					changeLink(par, cur, trans);
					if (par->data > cur->data) par->left = NULL; else par->right = NULL;
				}
			}
			else

				if (cur->left && cur->right) // delete node that have 2 children
				{
					AVL_node* parTmp = cur;
					AVL_node* tmp = cur->left;

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
					//swap(AnimeFrameNode.back()[cur->vectorPos]->data, AnimeFrameNode.back()[tmp->vectorPos]->data);

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

					CloneLastFrame();
					AnimeFrameNode.back()[cur->vectorPos]->Disable(); // xoa cai node

					CloneLastFrame(); // move it

					if (parTmp == cur) changeLink(tmp, tmp->left, trans);

					changeLink(cur->right, tmp, trans);
					changeLink(cur->left, tmp, trans);
										
					AnimeFrameNode.back()[tmp->vectorPos]->setPosition(AnimeFrameNode.back()[cur->vectorPos]->getPosition()); //flip node duoi len

					changeLink(par, tmp, Chosen_Color);
					changeLink(tmp, cur->right, Chosen_Color);

					if (parTmp == cur) changeLink(tmp, tmp->left, Chosen_Color);
					else changeLink(tmp, cur->left, Chosen_Color);

					CloneLastFrame(); //repos all
					if (par != cur)
					{
						if (par->data > tmp->data) par->left = tmp;
						else par->right = tmp;
					}
					else FirstPos = tmp->vectorPos;

					if (parTmp != cur)
					{
						parTmp->right = tmp->left;
						tmp->left = cur->left;
					}

					tmp->right = cur->right;
				}
				else              // have one child
				{
					AVL_node* tmp = cur->right ? cur->right : cur->left;

					CloneLastFrame();
					changeLink(cur, tmp, Chosen_Color);

					CloneLastFrame();
					AnimeFrameNode.back()[tmp->vectorPos]->Cir.setOutlineColor(Chosen_Color);

					CloneLastFrame();
					AnimeFrameNode.back()[cur->vectorPos]->Disable();
					changeLink(par, cur, trans);
					changeLink(cur, tmp, trans);

					if (par != cur)  //re linking real node
					{
						changeLink(par, tmp, Chosen_Color);
						if (par->data > tmp->data) par->left = tmp;
						else par->right = tmp;
					}
					else FirstPos = tmp->vectorPos;
				}
			BeginPosX = WINDOW_WIDTH / 2 - (NODE_DISTANCE * (n - 2)); //give new pos
			int cnt = 0;
			ReposAfter(NodeVectorFirst[FirstPos], cnt, 1, false);
			makeLinkLevel(NodeVectorFirst[FirstPos]);
		}
	}
}

void AVL_Anime::MakeUpdateAddin(int dataAdd)
{
	AVL_node* cur = NodeVectorFirst[FirstPos];
	AVL_node* par = NodeVectorFirst[FirstPos];

	{	// insert part

		while (1) // find node
		{
			if (!cur || cur->data == dataAdd) break;

			if (par != cur)
			{
				CloneLastFrame();

				changeLink(par, cur, Chosen_Color);
			}

			CloneLastFrame();
			AnimeFrameNode.back()[cur->vectorPos]->Cir.setOutlineColor(Chosen_Color);

			par = cur;

			if (cur->data > dataAdd) cur = cur->left; else
				if (cur->data < dataAdd) cur = cur->right;
		}

		if (!cur) // find empty slot
		{
			AnimeFrameNode.back().back()->setPosition(AnimeFrameNode.back()[par->vectorPos]->getPosition() + Vector2f(NODE_DISTANCE * 2 * ((par->data > dataAdd) ? -1 : 1), NODE_DISTANCE));

			CloneLastFrame();

			AnimeFrameNode.back().back()->Able();

			CloneLastFrame();

			AnimeFrameNode.back().back()->Highlight(Insert_Color);

			CloneLastFrame();

			if (par->data > dataAdd) par->left = NodeVectorFirst.back();
			else par->right = NodeVectorFirst.back();

			AnimeFrameNode.back().back()->unHighlight();
			AnimeFrameNode.back().back()->Cir.setOutlineColor(Chosen_Color);

			changeLink(par, NodeVectorFirst[n - 1], Chosen_Color);

			BeginPosX = WINDOW_WIDTH / 2 - (NODE_DISTANCE * (n - 1));//give new pos

			int cnt = 0;
			ReposAfter(NodeVectorFirst[FirstPos], cnt, 1, false);
			makeLinkLevel(NodeVectorFirst[FirstPos]);
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
}

void AVL_Anime::MakeSearchAnime(int data, SceneNode*& Nodes, vector <AVL_node*>& org, int pos, int n)
{
	isPlaying = 1;
	isHavingAnime = 1;

	this->n = n;

	cout << "anime Search " << endl;

	CloneFromTree(Nodes);
	copyFirstTree(org, pos);

	CurAnime = aSearch;

	AVL_node* cur = NodeVectorFirst[FirstPos];
	AVL_node* par = NodeVectorFirst[FirstPos];

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
		AnimeFrameNode.back()[cur->vectorPos]->Highlight(Search_Color);
	}
}

void AVL_Anime::ReposAfter(AVL_node* cur, int& cnt, int level, bool isLeft)
{
	if (!cur) return;

	cur->isLeft = isLeft;

	// go left
	if (cur->left) ReposAfter(cur->left, cnt, level + 1, true);

	//reposing

	TreeNode*& tmp = AnimeFrameNode.back()[cur->vectorPos];

	tmp->setPosition({ BeginPosX + NODE_DISTANCE * 2 * cnt,NODE_POS_HEAD + ((NODE_DISTANCE)*level) });
	tmp->Cir.setOutlineColor(Default_Color);
	cnt++;

	// go right
	if (cur->right)	ReposAfter(cur->right, cnt, level + 1, false);
}

void AVL_Anime::makeRotation(AVL_node* cur,AVL_node* par, int data, Type type)
{
	if (AnimeFrameNode.empty() || !isHavingAnime || !cur) return;

	if (cur->data == data)
	{
		AVL_node* x = cur;
		AVL_node* y = nullptr;

		switch (type)
		{
			case Left_Left:
				x = cur->right;
				y = x->left;

				x->left = cur;
				cur->right = y;
				
				break;

			case Right_Right:
				x = cur->left;
				y = x->right;				

				x->right = cur;
				cur->left = y;
				
				break;

		}

		if (par == cur) FirstPos = x->vectorPos;
		else
		{
			if (par->data > data) par->left = x;
			else par->right = x;
		}

		int cnt = 0;
		CloneLastFrame();
		ReposAfter(NodeVectorFirst[FirstPos], cnt, 1, false);
		breakLinkLevel();
		makeLinkLevel(NodeVectorFirst[FirstPos]);

		return;
	}
	

	makeRotation(cur->left, cur, data,type);
	makeRotation(cur->right, cur, data,type);
}

// misc

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

void AVL_Anime::cleanUp()
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
