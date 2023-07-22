#include "B_Tree.h"

B_Tree::B_Tree() : Tree()
{
	txtUpdate = new TextBox(txtDelete->pos + Vector2f(txtDelete->size.y + txtDelete->btn_cofirm->size.y + OUTLINE_THICKNESS * 10, 0), btnDelete->size, "Replace with", "Go", pink, black, black, black, white, { -50,0 }, { 40,40 }, 10, TextAlign::Middle);
	PushToObject(txtUpdate, btnDelete);

	DeleteGroup->adopt( txtUpdate->btn_cofirm,txtUpdate);

	anime = new B_Anime();

	PushAnime(anime);

	srand(time(NULL));
}

B_Tree::~B_Tree()
{

	DelAll(root);
}

void B_Tree::Disable()
{
	if (isDisable) return;

	Obliterate();
	anime->cleanUp();

	isDisable = true;
}

void B_Tree::Able()
{
	if (!isDisable) return;

	Forge(rand() % 5 + 8);

	isDisable = false;
}

void B_Tree::Forge(int n)
{
	cout << "Randomizing " << n << endl;

	DelAll(root);

	for (int i = 0; i < n; i++)
	{
		int a = rand() % 70 + 10;
		insertT(a);
	}
	
	CreateVisual(0);
	cout << endl <<  "help";
	
	btnFunctionHub->ForceOff();
}

void B_Tree::Obliterate()
{
	DestroyVisual(); 
	DelAll(root); 
}

void B_Tree::CreateVisual(int Forced)
{
	DestroyVisual();

	NodeVector.clear();

	//root->printConsole(root);
	
	cnt = 0;
	Push(root, root);
	if (!cnt) return;

	int BottomX = 0;

	for (int i = 0; i < cnt; i++)
	{
		cout << "level " << i << endl;
		for (int j = 0; j < NodeVector[i].size(); j++)
		{
			for (int k = 0; k < NodeVector[i][j]->nKey; k++)
			{
				if (i==cnt-1) BottomX++;
				cout << NodeVector[i][j]->data[k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	redoSize(BottomX+2);

	BeginPosX = WINDOW_WIDTH/2.f - (NODE_RADIUS * BottomX * 2 + (NodeVector[cnt-1].size()-1)*NODE_DISTANCE*2)/2.f;

	int id = cnt - 1;

	for (int j = 0; j < NodeVector[id].size(); j++)
	{
		for (int k = 0; k < NodeVector[id][j]->nKey; k++)
		{
			TreeNode* tmp = new TreeNode(AVL, "", NodeVector[id][j]->data[k]);
			tmp->setPosition({ BeginPosX,NODE_POS_HEAD + ((NODE_DISTANCE*2)*id) });

			shared_ptr <TreeNode> ttt(tmp);
			Nodes->attachChild(ttt);
			NodeVector[id][j]->tVisual[k] = ttt;

			BeginPosX += NODE_RADIUS*2.f;
		}
		BeginPosX += NODE_DISTANCE*2;
	}

	while (id--)
	{
		for (int j = 0; j < NodeVector[id].size(); j++)
		{
			auto &Cur = NodeVector[id][j];
			BeginPosX = (Cur->childs[0]->tVisual[0]->Cir.getPosition().x + Cur->childs[Cur->nKey]->tVisual[Cur->childs[Cur->nKey]->nKey-1]->Cir.getPosition().x)/2.f
				-Cur->nKey*NODE_RADIUS/2.f ;

			for (int k = 0; k < Cur->nKey; k++)
			{
				TreeNode* tmp = new TreeNode(AVL, "", Cur->data[k]);
				tmp->setPosition({ BeginPosX,NODE_POS_HEAD + ((NODE_DISTANCE*2)*id) });

				shared_ptr <TreeNode> ttt(tmp);
				Nodes->attachChild(ttt);
				Cur->tVisual[k] = ttt;

				BeginPosX += NODE_RADIUS * 2.f;
			}
		}
	}

	for (int i = 0; i < cnt-1; i++)
	{
		for (int j = 0; j < NodeVector[i].size(); j++)
		{
			int k = 0;
			for (; k < NodeVector[i][j]->nKey; k++) PushLink(NodeVector[i][j]->tVisual[k]->Cir.getPosition() - Vector2f(NODE_RADIUS / 2.f + OUTLINE_THICKNESS, -NODE_RADIUS / 2.f), NodeVector[i][j]->childs[k]->middlePos());

			PushLink(NodeVector[i][j]->tVisual[k-1]->Cir.getPosition() + Vector2f(NODE_RADIUS / 2.f, NODE_RADIUS / 2.f), NodeVector[i][j]->childs[k]->middlePos());
		}
	}
}

void B_Tree::DestroyVisual()
{
	Nodes->Children.clear();
	Linkes->Children.clear();
}

int B_Tree::count_node(B_node* cur)
{
	if (!cur) return 0;

	int res = 1;

	for (auto a : cur->childs) res += count_node(a);

	return res;
}

void B_Tree::Push(B_node*& Cur, B_node*& parent)
{
	if (!Cur) return;

	if (Cur == parent) Cur->level = 0; else Cur->level = parent->level + 1;

	if (cnt <= Cur->level)
	{
		vector <B_node*> tmp;
		NodeVector.push_back(tmp);
	}

	cnt = max(cnt, Cur->level+1);

	NodeVector[Cur->level].push_back(Cur);

	if (!Cur->isLeaf) for (int i = 0; i <= Cur->nKey; i++)
		Push(Cur->childs[i], Cur);

}

void B_Tree::PushLink(Vector2f pos1, Vector2f pos2)
{
	Edge* tmp = new Edge(Type::Link, "", nothing);

	tmp->setPositionByNode(pos1, pos2);

	PushToObject(tmp, Linkes);
}

void B_Tree::PushAnime(B_Anime*& anime1)
{
	shared_ptr <SceneNode> here(anime1);
	Animes->attachChild(here);
}

void B_Tree::updateCurrent(Event& event, Vector2f& MousePos)
{
	if (txtCreateSize->data != nothing)
	{
		int data = txtCreateSize->getIntdata();
		if (!data || data > 50) return;
		Forge(data);
	}else
		if (btnCreateRandom->isPressed()) Forge(rand() % 5 + 10); else 
			if (btnCreateLoad->isPressed())
	{
		ifstream fin("dataForLoad/B_Tree.in");
		int a;
		cout << "Loading..." << endl;

		DelAll(root);

		while (fin >> a) insertT(a);

		CreateVisual(0);

		btnFunctionHub->ForceOff();
	} else
				if (root)
		{
			if (txtDelete->data != nothing) // delete
			{
				if (txtUpdate->data != nothing)
				{
					cout << "update " << endl;

					int dataDel = txtDelete->getIntdata();
					int dataAdd = txtUpdate->getIntdata();

					/*anime->MakeUpdateAnime(dataDel,dataAdd, Nodes, NodeVector, root->vectorPos, count_node(root));

					int cnt = count_node(root);
					root = Del(root, dataDel);

					if (cnt != count_node(root))
					{
						anime->MakeUpdateAddin(dataAdd);
						root = insertT(root, dataAdd, root);
					}*/
				}
				else
				{
					cout << "delete " << endl;

					int data = txtDelete->getIntdata();

					/*anime->MakeDeleteAnime(data, Nodes, NodeVector, root->vectorPos, count_node(root));

					root = Del(root, data);*/
				}
				CreateVisual(0);
				//print_console();

				btnFunctionHub->ForceOff();
			}
			else
				if (txtInsert->data != nothing) // delete
				{
					cout << "Insert " << endl;

					int data = txtInsert->getIntdata();

					//anime->MakeInsertAnime(data, Nodes, NodeVector, root->vectorPos, count_node(root));

					insertT(data);
					CreateVisual(0);
					//print_console();

					btnFunctionHub->ForceOff();
				}
				else
					if (txtSearch->data != nothing) // delete
					{
						cout << "Search " << endl;

						int data = txtSearch->getIntdata();

						/*anime->MakeSearchAnime(data, Nodes, NodeVector, root->vectorPos, count_node(root));

						Search(root, data); cout << endl;
						CreateVisual(0);*/
						//print_console();

						btnFunctionHub->ForceOff();
					}
		}
}

void B_Tree::takeTimeCurrent(Time& dt)
{
	if (anime->isHavingAnime)
	{
		Nodes->Disable();
		Linkes->Disable();
	}
	else
	{
		Nodes->Able();
		Linkes->Able();
	}
}

void B_Tree::insertT(int data)
{
	if (root == NULL)
	{
		root = new B_node(true);
		root->data[0] = data;  // Insert key
		root->nKey = 1;		   // Update number of keys in root
	}
	else // If tree is not empty
	{
		if (root->nKey == T)// If root is full, then tree grows up
		{
			B_node* tmp = new B_node(false);

			tmp->childs[0] = root;// Make old root as child of new root

			
			tmp->splitChild(0, root);

			int i = 0;
			if (tmp->data[0] < data) i++;
			tmp->childs[i]->insertNonFull(data);

			// Change root
			root = tmp;
		}
		else  root->insertNonFull(data);
	}

}


B_node* B_Tree::Del(B_node*& cur, int data)
{
	if (!cur) return NULL;

	return cur;
}

B_node* B_Tree::Search(B_node*& cur, int data)
{
	if (!cur) return NULL;

	return cur;
}

void B_Tree::DelAll(B_node* cur)
{
	if (!cur) return;

	B_node* tmp = cur;

	for (int i = 0; i < cur->nKey;i++) DelAll(cur->childs[i]);

	delete tmp;
	root = NULL;
}