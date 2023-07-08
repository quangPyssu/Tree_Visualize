#include "AVL_Tree.h"

AVL_node* AVL_Tree::new_node(int data)
{
	AVL_node* tmp = new AVL_node;

	tmp->data = data;
	tmp->height = 1;
	return tmp;
}

AVL_Tree::AVL_Tree() : Tree()
{
	anime = new AVL_Anime();

	PushAnime(anime);

	btnBack = new Button(Vector2f(WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT - 40), { 40,40 }, "<", black, black + Color(50, 50, 50), black, Color::Transparent, Middle);
	btnPlay = new Button(btnBack->pos + Vector2f(btnBack->size.x + 10, 0), btnBack->size, "=", black, black + Color(50, 50, 50), black, Color::Transparent, Middle);
	btnForw = new Button(btnPlay->pos + Vector2f(btnBack->size.x + 10, 0), btnBack->size, ">", black, black + Color(50, 50, 50), black, Color::Transparent, Middle);
	btnStart = new Button(btnBack->pos - Vector2f(btnBack->size.x + 10, 0), btnBack->size, "<<", black, black + Color(50, 50, 50), black, Color::Transparent, Middle);
	btnEnd = new Button(btnForw->pos + Vector2f(btnBack->size.x + 10, 0), btnBack->size, ">>", black, black + Color(50, 50, 50), black, Color::Transparent, Middle);

	PushToObject(ButtonTranslate(btnBack), Buttones);
	PushToObject(ButtonTranslate(btnForw), Buttones);
	PushToObject(ButtonTranslate(btnPlay), Buttones);
	PushToObject(ButtonTranslate(btnStart), Buttones);
	PushToObject(ButtonTranslate(btnEnd), Buttones);

	srand(time(NULL));
	Forge(10);
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

void AVL_Tree::Disable()
{
	if (isDisable) return;

	Obliterate();
	anime->cleanUp();

	isDisable = true;
}

void AVL_Tree::Able()
{
	if (!isDisable) return;

	Forge(rand() % 5 + 8);

	isDisable = false;
}

void AVL_Tree::Forge(int n)
{
	cout << "Randomizing" << endl;

	DelAll(root);

	for (int i = 0; i < n; i++)
	{
		int a = rand() % 50 + 10;
		root=insertT(root, a, root, true);
	}
	CreateVisual();
	print_console();

	btnFunctionHub->ForceOff();
}

void AVL_Tree::Obliterate()
{
	DestroyVisual();
	DelAll(root);
}

void AVL_Tree::CreateVisual()
{
	DestroyVisual();

	NodeVector.clear();

	BeginPosX = WINDOW_WIDTH / 2 - (NODE_DISTANCE * count_node(root));

	cnt = 0;

	if (!root) return;
	Push(root, cnt, root, true);
}

void AVL_Tree::DestroyVisual()
{
	Nodes->Children.clear();
	Linkes->Children.clear();
}

int AVL_Tree::count_node(AVL_node* cur)
{
	if (!cur) return 0;

	int res = (1 + count_node(cur->left) + count_node(cur->right));

	return res;
}

void AVL_Tree::Push(AVL_node*& Cur, int& cnt, AVL_node*& parent, bool isLeft)
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
	if (Cur->left) Push(Cur->left, cnt, Cur, true);

	TreeNode* tmp = new TreeNode(Type::AVL, "", Cur->data);

	//tmp->setPosition({ !Cur->par ? 500 : Cur->par->tVisual->getPosition().x + (NODE_DISTANCE*4 / Cur->level) * (Cur->isLeft ? -1 : 1),NODE_POS_HEAD + ((NODE_DISTANCE) * Cur->level)});

	tmp->setPosition({ BeginPosX + NODE_DISTANCE * 2 * cnt,NODE_POS_HEAD + ((NODE_DISTANCE)*Cur->level) });

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
		Push(Cur->right, cnt, Cur, false);

	}

	if (Cur->left) PushLink(Cur, Cur->left);
	if (Cur->right) PushLink(Cur, Cur->right);

	return;
}

void AVL_Tree::PushLink(AVL_node*& node1, AVL_node*& node2)
{
	Edge* tmp = new Edge(Type::Link, "", nothing);

	tmp->setPositionByNode(node1->tVisual->getPosition(), node2->tVisual->getPosition());

	shared_ptr <Edge> here(tmp);
	Linkes->attachChild(here);
}

void AVL_Tree::PushAnime(AVL_Anime*& anime1)
{
	shared_ptr <SceneNode> here(anime1);
	Animes->attachChild(here);
}

void AVL_Tree::updateCurrent(Event& event, Vector2f& MousePos)
{
	if (btnCreateRandom->isPressed())// Generate
	{
		Forge(rand() % 5 + 10);
	}
	else if (btnCreateLoad->isPressed())
	{
		ifstream fin("dataForLoad/AVL_Tree.in");
		int a;
		cout << "Loading..." << endl;

		DelAll(root);

		while (fin >> a) root=insertT(root, a, root, true);

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

				anime->MakeDeleteAnime(data, Nodes, NodeVector, root->vectorPos, count_node(root));

				root = Del(root, data);
				CreateVisual();
				//print_console();

				btnFunctionHub->ForceOff();
			}
			else
				if (txtInsert->data != nothing) // delete
				{
					cout << "Insert " << endl;

					int data = txtInsert->getIntdata();

					anime->MakeInsertAnime(data, Nodes, NodeVector, root->vectorPos, count_node(root));

					root=insertT(root, data, root, false);
					CreateVisual();
					//print_console();

					btnFunctionHub->ForceOff();
				}
				else
					if (txtSearch->data != nothing) // delete
					{
						cout << "Search " << endl;

						int data = txtSearch->getIntdata();

						anime->MakeSearchAnime(data, Nodes, NodeVector, root->vectorPos, count_node(root));

						Search(root, data); cout << endl;
						CreateVisual();
						//print_console();

						btnFunctionHub->ForceOff();
					}
		}

	if (btnBack->isPressed()) anime->ChooseFrame(-1); else if (btnForw->isPressed()) anime->ChooseFrame(1);
	if (btnPlay->isPressed()) anime->isPlaying = anime->isPlaying ? 0 : 1;
	if (btnStart->isPressed()) anime->ChooseFrame(-100); else if (btnEnd->isPressed()) anime->ChooseFrame(100);
}

void AVL_Tree::takeTimeCurrent(Time& dt)
{
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

int AVL_Tree::height(AVL_node* cur)
{
	if (!cur) return 0;
	return cur->height;
}

void AVL_Tree::updateHeight(AVL_node* &cur)
{
	if (!cur) return;
	cur->height = max(height(cur->left), height(cur->right)) + 1;
}

AVL_node* AVL_Tree::rightRotate(AVL_node* cur)
{
	AVL_node* x=cur->left;
	AVL_node* y = x->right;
	
	cur->left = y;
	x->right = cur;

	updateHeight(cur);
	updateHeight(x);	

	return x;
}

AVL_node* AVL_Tree::leftRotate(AVL_node* cur)
{
	AVL_node* x = cur->right;
	AVL_node* y = x->left;
	
	cur->right = y;
	x->left = cur;

	updateHeight(cur);
	updateHeight(x);	

	return x;
}

int AVL_Tree::GetBalance(AVL_node* cur)
{
	if (!cur) return 0;
	return height(cur->right) - height(cur->left);
}

AVL_node* AVL_Tree::insertT(AVL_node*& cur, int data, AVL_node*& parent, bool isLeft)
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

	if (cur->data > data) cur->left=insertT(cur->left, data, cur, true); else
		if (cur->data < data) cur->right=insertT(cur->right, data, cur, false); else
			return cur;

	updateHeight(cur);
	int balance = GetBalance(cur);

	if (balance > 1)
	{
		if (data > cur->right->data) return leftRotate(cur); // left left
		else 
		if (data < cur->right->data) // right left 
		{
			cur->right=rightRotate(cur->right);
			return leftRotate(cur);
		}
	} else
	
	if (balance < -1)
	{
		if (data < cur->left->data) return rightRotate(cur); // right right
		else
		if (data > cur->left->data)  // left right
		{
			cur->left=leftRotate(cur->left);
			return rightRotate(cur);
		}
	}

	return cur;

}

void AVL_Tree::print_console(AVL_node* cur, string prefix, bool isLeft)
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

AVL_node* AVL_Tree::Del(AVL_node*& cur, int data)
{
	if (!cur) return NULL;

	if (cur->data > data) cur->left = Del(cur->left, data); else 
		if (cur->data < data) cur->right = Del(cur->right, data); else
		{	//delete this node

			if (!cur->left && !cur->right) // delete leave node
			{
				delete cur;
				return NULL;
			} else

			if (cur->left && cur->right) // delete node that have 2 children
			{
				AVL_node* tmp = cur->left;

				while (tmp->right) tmp = tmp->right;

				cur->data = tmp->data;
				cur->left = Del(cur->left, tmp->data);
			}
			else //have one child
			{
				AVL_node* tmp = cur->left ? cur->left : cur->right;
				AVL_node* del = cur;
				cur = tmp;

				delete del;
			}
		}

	updateHeight(cur);
	int balance = GetBalance(cur);

	if (balance > 1)
	{
		cout << "ady " << endl;
		if (GetBalance(cur->right)>=0) return leftRotate(cur);
		else 
		{
			cur->right=rightRotate(cur->right);
			return leftRotate(cur);
		}
	} else
		if (balance < -1)
		{
			cout << "ads " << endl;
			if (GetBalance(cur->right) <= 0) return rightRotate(cur);
			else
			{
				cur->left = leftRotate(cur->left);
				return leftRotate(cur);
			}
		}	

	return cur;
}

AVL_node* AVL_Tree::Search(AVL_node*& cur, int data)
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