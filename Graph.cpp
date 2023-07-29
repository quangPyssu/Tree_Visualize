#include "Graph.h"

Graphs::Graphs() : Tree()
{
	txtUpdate = new TextBox(txtDelete->pos + Vector2f(txtDelete->size.y + txtDelete->btn_cofirm->size.y + OUTLINE_THICKNESS * 10, 0), btnDelete->size, "End Pos", "Go", pink, black, black, black, white, { -50,0 }, { 40,40 }, 10, TextAlign::Middle);
	PushToObject(txtUpdate, btnDelete);

	btnDelete->text.setString("Dijkstra");
	btnInsert->text.setString("Connected Comp");
	btnSearch->text.setString("Min Span Tree");

	txtInsert->default_S="Start Pos";
	txtDelete->default_S="Start Pos";
	txtSearch->default_S="Start Pos";

	DeleteGroup->adopt(txtUpdate->btn_cofirm, txtUpdate);

	anime = new Graph_Anime();

	PushAnime(anime);

	srand(time(NULL));
}

Graphs::~Graphs()
{

	anime->DelAll();
}

void Graphs::Disable()
{
	if (isDisable) return;

	Obliterate();
	anime->cleanUp();

	isDisable = true;
}

void Graphs::Able()
{
	if (!isDisable) return;

	Forge(rand() % 5 + 8);

	isDisable = false;
}

void Graphs::Forge(int n)
{
	cout << "Randomizing " << n << endl;

	anime->DelAll(); 

	anime->GenerateGraph(n); 
	
	CreateVisual(0);
	
	btnFunctionHub->ForceOff();
}

void Graphs::Obliterate()
{
	DestroyVisual(); 
	anime->DelAll(); 
}

void Graphs::CreateVisual(int Forced)
{
	DestroyVisual();
	
	if (!anime->n) return;

	redoSize(anime->n);
	BeginPosX = WINDOW_WIDTH / 2 - (NODE_DISTANCE * anime->n);

	cnt = 0;

	Push(0);

	for (int i = 0; i < anime->n; i++)
		for (int j = 0; j < i; j++)
			if (anime->NodeVector[i]->childs[j])
			{
				PushLink(anime->NodeVector[j]->tVisual->getPosition(), anime->NodeVector[i]->tVisual->getPosition(), anime->NodeVector[i]->childs[j]);
				anime->NodeVector[j]->Edgeid[i] = anime->NodeVector[i]->Edgeid[j] = anime->maxLinkCnt++;
			}
}

void Graphs::Push(int id)
{
	if (id >= anime->n) return;

	Graph_node*& a = anime->NodeVector[id];

	Push(id * 2 + 1);

	TreeNode* tmp = new TreeNode(AVL,"",id+1);
	tmp->CanBeDrag = 1;

	int cntH = (id % 2 ? id+1 : id-1)+1;

	tmp->setPosition({ BeginPosX + NODE_DISTANCE * 2 * cnt,NODE_POS_HEAD + (NODE_DISTANCE*cntH/1.5f)});

	shared_ptr <TreeNode> here(tmp);

	a->tVisual = here;
	a->Nodeid = cnt;
	Nodes->attachChild(here);
	cnt++;

	Push(id * 2 + 2);
}

void Graphs::DestroyVisual()
{
	Nodes->Children.clear();
	Linkes->Children.clear();
}

void Graphs::PushLink(Vector2f pos1, Vector2f pos2,int data)
{
	Edge* tmp = new Edge(Type::Link, "", data);

	tmp->text.setFillColor(Default_Color);

	if (pos1.y > pos2.y) swap(pos1, pos2);
	
	tmp->setPositionByNode(pos1, pos2);

	PushToObject(tmp, Linkes);
}

void Graphs::PushAnime(Graph_Anime*& anime1)
{
	shared_ptr <SceneNode> here(anime1);
	Animes->attachChild(here);
}

void Graphs::updateCurrent(Event& event, Vector2f& MousePos)
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
		ifstream fin("dataForLoad/Graph.in");
		int a=0;
		cout << "Loading..." << endl;

		anime->DelAll();

		//

		CreateVisual(0);

		btnFunctionHub->ForceOff();
	} else
				//if (anime->root)
		{
			if (txtDelete->data != nothing && txtUpdate->data!=nothing) // delete
			{
				if (txtDelete->data <1 || txtDelete->data > anime->n || txtUpdate->data <1 || txtUpdate->data > anime->n) return;
				cout << "Diskjcha " << endl;

				int data1 = txtDelete->getIntdata();
				int data2 = txtUpdate->getIntdata();

				anime->MakeDijsktraAnime(Nodes,Linkes,data1,data2);

				btnFunctionHub->ForceOff();
			}
			else
				if (txtInsert->data != nothing && txtInsert->data>0) // delete
				{
					if (txtInsert->data <1 || txtInsert->data > anime->n) return;
					cout << "Connected Component " << endl;

					int data = txtInsert->getIntdata();

					anime->MakeConnectedComponent(Nodes,Linkes,data);

					btnFunctionHub->ForceOff();
				}
				else
					if (txtSearch->data != nothing) // delete
					{
						if (txtSearch->data <1 || txtSearch->data > anime->n) return;
						cout << "Minimum spanning tree " << endl;

						int data = txtSearch->getIntdata();

						anime->MakeMinSpanAnime(Nodes,Linkes,data);

						btnFunctionHub->ForceOff();
					}
		}

	for (int i = 0; i < anime->n; i++) if (anime->NodeVector[i]->tVisual->isDraggin)
	{
		for (int j = 0; j < anime->n; j++) if (i != j && anime->NodeVector[i]->childs[j])
		{
			Vector2f pos1 = anime->NodeVector[i]->tVisual->getPosition();
			Vector2f pos2 = anime->NodeVector[j]->tVisual->getPosition();

			if (pos1.y > pos2.y) swap(pos1, pos2);

			shared_ptr<Edge> a= dynamic_pointer_cast<Edge>(Linkes->Children[anime->NodeVector[i]->Edgeid[j]]);

			a->setPositionByNode(pos1, pos2);
		}
	}
}

void Graphs::takeTimeCurrent(Time& dt)
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