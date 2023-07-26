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

	anime->DelAll(anime->root);
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

	anime->DelAll(anime->root);

	for (int i = 0; i < n; i++)
	{
		int a = rand() % 70 + 10;
		anime->insertT(a,0);
	}
	
	CreateVisual(0);
	cout << endl <<  "help";
	
	btnFunctionHub->ForceOff();
}

void B_Tree::Obliterate()
{
	DestroyVisual(); 
	anime->DelAll(anime->root); 
}

void B_Tree::CreateVisual(int Forced)
{
	DestroyVisual();

	anime->NodeVector.clear();
	
	cnt = 0;
	Push(anime->root, anime->root);
	if (!cnt) return;

	int BottomX = 0;

	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < anime->NodeVector[i].size(); j++)
		{
			for (int k = 0; k < anime->NodeVector[i][j]->nKey; k++)
			{
				if (i == cnt - 1) BottomX++;
				cout << anime->NodeVector[i][j]->data[k] << " ";
			}cout << endl;
		}cout << endl;
	}

	redoSize(BottomX+2);

	BeginPosX = WINDOW_WIDTH/2.f - (NODE_RADIUS * BottomX * 2 + (anime->NodeVector[cnt-1].size()-1)*NODE_DISTANCE*2)/2.f;

	int id = cnt - 1;
	anime->maxNodeCnt = 0;
	//bottom floor
	for (int j = 0; j < anime->NodeVector[id].size(); j++)
	{
		for (int k = 0; k < anime->NodeVector[id][j]->nKey; k++)
		{
			TreeNode* tmp = new TreeNode(AVL, "", anime->NodeVector[id][j]->data[k]);
			tmp->setPosition({ BeginPosX,NODE_POS_HEAD + ((NODE_DISTANCE*2)*id) });

			shared_ptr <TreeNode> ttt(tmp);
			Nodes->attachChild(ttt);
			anime->NodeVector[id][j]->tVisual[k] = ttt;
			anime->NodeVector[id][j]->Nodeid[k] = anime->maxNodeCnt++;

			BeginPosX += NODE_RADIUS*2.f;
		}
		BeginPosX += NODE_DISTANCE*2;
	}
	//rest of the tree
	while (id--)
	{
		for (int j = 0; j < anime->NodeVector[id].size(); j++)
		{
			auto &Cur = anime->NodeVector[id][j];
			BeginPosX = (Cur->childs[0]->tVisual[0]->Cir.getPosition().x + Cur->childs[Cur->nKey]->tVisual[Cur->childs[Cur->nKey]->nKey-1]->Cir.getPosition().x)/2.f
				-Cur->nKey*NODE_RADIUS/2.f ;

			for (int k = 0; k < Cur->nKey; k++)
			{
				TreeNode* tmp = new TreeNode(AVL, "", Cur->data[k]);
				tmp->setPosition({ BeginPosX,NODE_POS_HEAD + ((NODE_DISTANCE*2)*id) });

				shared_ptr <TreeNode> ttt(tmp);
				Nodes->attachChild(ttt);
				Cur->tVisual[k] = ttt;
				Cur->Nodeid[k] = anime->maxNodeCnt++;

				BeginPosX += NODE_RADIUS * 2.f;
			}
		}
	}

	anime->maxLinkCnt = 0;
	//make linkes
	for (int i = 0; i < cnt-1; i++)
	{
		for (int j = 0; j < anime->NodeVector[i].size(); j++) if (anime->NodeVector[i][j]->nKey)
		{
			int k = 0;
			for (; k < anime->NodeVector[i][j]->nKey; k++)
			{
				PushLink(anime->NodeVector[i][j]->tVisual[k]->Cir.getPosition() - Vector2f(NODE_RADIUS / 2.f + OUTLINE_THICKNESS, -NODE_RADIUS / 2.f), anime->NodeVector[i][j]->childs[k]->middlePos());
				anime->NodeVector[i][j]->Edgeid[k] = anime->maxLinkCnt++;
			}

			PushLink(anime->NodeVector[i][j]->tVisual[k-1]->Cir.getPosition() + Vector2f(NODE_RADIUS / 2.f, NODE_RADIUS / 2.f), anime->NodeVector[i][j]->childs[k]->middlePos());
			anime->NodeVector[i][j]->Edgeid[k] = anime->maxLinkCnt++;
		}
	}
}

void B_Tree::DestroyVisual()
{
	Nodes->Children.clear();
	Linkes->Children.clear();
}

void B_Tree::Push(B_node*& Cur, B_node*& parent)
{
	if (!Cur) return;

	if (Cur == parent) Cur->level = 0; else Cur->level = parent->level + 1;

	if (cnt <= Cur->level)
	{
		vector <B_node*> tmp;
		anime->NodeVector.push_back(tmp);
	}

	cnt = max(cnt, Cur->level+1);

	anime->NodeVector[Cur->level].push_back(Cur);

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
		if (data<0 || data > 50) return;
		Forge(data);
	}else
		if (btnCreateRandom->isPressed()) Forge(rand() % 5 + 10); else 
			if (btnCreateLoad->isPressed())
	{
		ifstream fin("dataForLoad/B_Tree.in");
		int a;
		cout << "Loading..." << endl;

		anime->DelAll(anime->root);

		while (fin >> a) anime->insertT(a,0);

		CreateVisual(0);

		btnFunctionHub->ForceOff();
	} else
				//if (anime->root)
		{
			if (txtDelete->data != nothing) // delete
			{
				if (txtUpdate->data != nothing)
				{
					cout << "update " << endl;

					int dataDel = txtDelete->getIntdata();
					int dataAdd = txtUpdate->getIntdata();

					anime->MakeUpdateAnime(dataDel,dataAdd, Nodes);
				}
				else
				{
					cout << "delete " << endl;

					int data = txtDelete->getIntdata();

					anime->MakeDeleteAnime(data, Nodes);
				}
				CreateVisual(0);

				btnFunctionHub->ForceOff();
			}
			else
				if (txtInsert->data != nothing) // delete
				{
					cout << "Insert " << endl;

					int data = txtInsert->getIntdata();

					anime->MakeInsertAnime(data,Nodes);

					CreateVisual(0);

					btnFunctionHub->ForceOff();
				}
				else
					if (txtSearch->data != nothing) // delete
					{
						cout << "Search " << endl;

						int data = txtSearch->getIntdata();

						anime->MakeSearchAnime(data, Nodes);
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