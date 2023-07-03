#include "AVL_Tree.h"

AVL_node* AVL_Tree::new_node(int data)
{
	AVL_node* tmp = new AVL_node;

	tmp->data = data;
	return tmp;
}

AVL_Tree::AVL_Tree() : Tree()
{
	anime = new AVL_Anime();

	PushAnime(anime);

	btnBack = new Button(Vector2f(WINDOW_WIDTH / 2 - 70, WINDOW_HEIGHT - 40),{30,30},"<",black,black+Color(50,50,50),black,Color::Transparent,Middle);
	btnForw = new Button(Vector2f(WINDOW_WIDTH / 2 + 10, WINDOW_HEIGHT - 40),{30,30},">",black,black+Color(50,50,50),black,Color::Transparent,Middle);
	btnPlay = new Button(Vector2f(WINDOW_WIDTH / 2 - 30, WINDOW_HEIGHT - 40),{30,30},"=", black, black + Color(50, 50, 50), black, Color::Transparent, Middle);

	PushToObject(ButtonTranslate(btnBack), Buttones);
	PushToObject(ButtonTranslate(btnForw), Buttones);
	PushToObject(ButtonTranslate(btnPlay), Buttones);
}

AVL_Tree::~AVL_Tree()
{

	DelAll(root);
	/*delete Buttones;
	delete TextBoxes;
	delete Linkes;
	delete Nodes;

	delete btnCreate;
	delete butt2;
	delete txtDelete;*/
}

void AVL_Tree::CreateVisual()
{
	if (!root) return;

	Nodes->Children.clear();
	Linkes->Children.clear();

	NodeVector.clear();

	BeginPosX = WINDOW_WIDTH / 2 - (NODE_DISTANCE*count_node(root));

	cnt = 0;
	Push(root,cnt,root,true);
}

int AVL_Tree::count_node(AVL_node* cur)
{
	if (!cur) return 0;
		
	int res = (1 + count_node(cur->left) + count_node(cur->right));

	return res;
}

void AVL_Tree::Push(AVL_node* &Cur,int& cnt,AVL_node* &parent,bool isLeft)
{
	if (!Cur) return;

	if (parent != Cur)
	{
		Cur->par = parent;
		Cur->level = parent->level + 1;
	}
	else
	{
		Cur->par = NULL;
		Cur->level = 1;
	}

	Cur->isLeft = isLeft;
	
	// go left
	if (Cur->left) Push(Cur->left,cnt,Cur,true);
	
	TreeNode* tmp=new TreeNode(Type::AVL,"", Cur->data);

	//tmp->setPosition({ !Cur->par ? 500 : Cur->par->tVisual->getPosition().x + (NODE_DISTANCE*4 / Cur->level) * (Cur->isLeft ? -1 : 1),NODE_POS_HEAD + ((NODE_DISTANCE) * Cur->level)});
	
	tmp->setPosition({ BeginPosX+ NODE_DISTANCE*2 * cnt,NODE_POS_HEAD + ((NODE_DISTANCE)*Cur->level) });

	shared_ptr <TreeNode> here(tmp);
	Nodes->attachChild(here);

	// Vector dataing

	NodeVector.push_back(Cur);
	Cur->vectorPos = NodeVector.size() - 1;
	Cur->tVisual = here;
	cnt++;

	// go right
	if (Cur->right)
	{
		Push(Cur->right,cnt,Cur,false);

	}

	if (Cur->left) PushLink(Cur,Cur->left);
	if (Cur->right) PushLink(Cur,Cur->right);

	return;
}

void AVL_Tree::PushLink(AVL_node*& node1, AVL_node*& node2)
{
	Edge* tmp = new Edge(Type::Link, "",nothing);

	tmp->setPositionByNode(node1->tVisual->getPosition() , node2->tVisual->getPosition() );

	shared_ptr <Edge> here(tmp);
	Linkes->attachChild(here);
}

void AVL_Tree::PushAnime(AVL_Anime* &anime1)
{
	shared_ptr <SceneNode> here(anime1);
	Animes->attachChild(here);
}

void AVL_Tree::updateCurrent(Event& event, Vector2f& MousePos)
{
	if (btnCreateRandom->isPressed())// Generate
	{
		cout << "roger that" << endl;

		DelAll(root);

		for (int i = 0; i < 10; i++) insertT(root, rand() % 50 + 10, root, true);
		CreateVisual();
		print_console();
		btnFunctionHub->ForceOff();
	}
	else
		if (root)
		{
			if (txtDelete->data != nothing) // delete
			{
				cout << "delete " << endl;

				int data = txtDelete->getIntdata();

				anime->MakeDeleteAnime(data, Nodes, NodeVector, root->vectorPos);

				root = Del(root, data);
				CreateVisual();
				//print_console();

				btnFunctionHub->ForceOff();

				anime->copySecondTree(NodeVector, root->vectorPos);

			}
			else
				if (txtInsert->data != nothing) // delete
				{
					cout << "Insert " << endl;
					anime->CloneFromTree(Nodes);
					anime->copyFirstTree(NodeVector, root->vectorPos);

					insertT(root, txtInsert->getIntdata(), root, false);
					CreateVisual();
					//print_console();

					btnFunctionHub->ForceOff();

					anime->copySecondTree(NodeVector, root->vectorPos);
				}
				else
					if (txtSearch->data != nothing) // delete
					{
						anime->CloneFromTree(Nodes);
						anime->copyFirstTree(NodeVector, root->vectorPos);

						Search(root, txtSearch->getIntdata()); cout << endl;
						CreateVisual();
						//print_console();

						btnFunctionHub->ForceOff();

						anime->copySecondTree(NodeVector, root->vectorPos);
					}
		}

	if (btnBack->isPressed()) anime->ChooseFrame(-1); else if (btnForw->isPressed()) anime->ChooseFrame(1);
	if (btnPlay->isPressed()) anime->isPlaying = anime->isPlaying ? 0:1;

	anime->isHavingAnime = (anime->curFrame < (int)anime->AnimeFrameNode.size()) ? 1 : 0;

	if (anime->isHavingAnime)
	{
		Nodes->Disable();
		Linkes->Disable();
		Animes->Able();
	}
	else
	{
		Nodes->Able();
		Linkes->Able();
		Animes->Disable();
	}
}

AVL_node* AVL_Tree::insertT(AVL_node*& cur, int data, AVL_node*& parent,bool isLeft)
{
	if (cur == NULL)
	{
		cur = new_node(data);
		if (parent != cur)
		{
			cur->par = parent;
			cur->level = parent->level + 1;
		}
		cur->isLeft = isLeft;

		return cur;
	}

	if (cur->data > data) return insertT(cur->left, data,cur,true); else
		if (cur->data < data) return insertT(cur->right, data,cur,false); else
			return NULL;
	
}

void AVL_Tree::print_console(AVL_node* cur, string prefix,bool isLeft)
{
	if (!cur) return;

	if (isLeft) cout << "|--"; else cout << "`--";

	cout << cur->data << endl;

	if (cur->left) cout << "   " + prefix;
	print_console(cur->left, cur->right ? prefix + "|  " : prefix + "   ", 1);

	if (cur->right) cout << "   " + prefix;
	print_console(cur->right, prefix + "   ", 0);
}

void AVL_Tree::print_console()
{
	print_console(root, "", 1);
}

AVL_node* AVL_Tree::Del(AVL_node* &cur,int data)
{
	if (!cur) return NULL;

	if (cur->data > data)
	{
		cur->left = Del(cur->left, data);

		return cur;
	} else
	if (cur->data < data)
	{
		cur->right = Del(cur->right, data);

		return cur;
	}

	if (!cur->left && !cur->right) // delete leave node
	{
		delete cur;
		return NULL;
	} 

	if (cur->left && cur->right) // delete node that have 2 children
	{
		AVL_node* par = cur;
		AVL_node* tmp = cur->left;

		while (tmp->right)
		{
			par = tmp;
			tmp = tmp->right;
		}

		if (par == cur) par->left = tmp->left;
		else par->right = tmp->left;

		tmp->left = cur->left;
		tmp->right = cur->right;

		delete cur;

		return tmp;
	} else
	if (cur->left)   // have left child
	{
		AVL_node* tmp = cur->left;
		delete cur;

		return tmp;
	}
	else			// have right child
	{
		AVL_node* tmp = cur->right;
		delete cur;

		return tmp;
	}


	return cur;
}

AVL_node* AVL_Tree::Search(AVL_node* &cur,int data)
{
	if (!cur) return NULL;

	cout << cur->data << "-> ";

	if (cur->data > data) return Search(cur->left, data);
	if (cur->data < data) return Search(cur->right, data);
		
	return cur;
}

void AVL_Tree::DelAll(AVL_node* cur)
{
	if (!cur) return;

	AVL_node* tmp = cur;

	DelAll(cur->left);
	DelAll(cur->right);

	delete tmp;
	root = NULL;
}
