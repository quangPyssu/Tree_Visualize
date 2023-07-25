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

B_node::B_node(bool isLeaf,B_Anime* anime)
{
	this->isLeaf = isLeaf;

	for (int i = 0; i < T ; i++) data.push_back(0), childs.push_back(NULL);

	childs.push_back(NULL);

	for (int i = 0; i < T; i++) tVisual.push_back(NULL);

	nKey = 0;

	this->anime = anime;
}

void B_node::splitChild(int i, B_node* y)
{
	// Create a new node which sibling

	B_node* z = new B_node(y->isLeaf,anime);
	z->nKey = 1;

	// Copy the last keys of y to z
	z->data[0] = y->data[2];
	z->tVisual[0] = y->tVisual[2];

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
	for (int j = nKey-1; j >= i; j--) data[j+1] = data[j],tVisual[j+1]=tVisual[j];

	// Copy the middle key of y to this node
	data[i] = y->data[1];
	tVisual[i] = y->tVisual[1];

	// Increment count of keys in this node
	nKey++;
}

void B_node::insertNonFull(int data)
{
	// make frame for action
	paintNode(Chosen_Color, 0, nKey - 1,0);

	int i = nKey - 1;

	if (isLeaf)
	{
		// Finds the location of new key to be inserted & Moves all greater keys to one place ahead
		while (i >= 0 && this->data[i] > data)
		{
			this->data[i + 1] =this->data[i];
			i--;
		}

		// Insert the new key at found location
		this->data[i + 1] = data;
		nKey = nKey ++;

		paintNode(Insert_Color, i+1, i+1,0);
	
	}
	else // not leaf
	{
		// Find the child which is going to have the new key
		while (i >= 0 && this->data[i] > data)	i--;

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

void B_node::paintNode(Color color, int l, int r,bool HasPred)
{
	if (anime->isAnime)
	{
		if (HasPred) anime->CloneLastFrame(); else anime->MakeCurState();

		for (int i = l; i <= r; i++) if (tVisual[i])
			tVisual[i]->Cir.setOutlineColor(color);
	}
}

// delete bs for B-TRees_node

int B_node::findKey(int data)
{
	for (int i = 0; i < nKey; i++) if (this->data[i] >= data) return i;

	return nKey;
}

void B_node::remove(int data)
{
	// make frame for action
	paintNode(Chosen_Color, 0, nKey - 1,0);

	int id = findKey(data);

	if (id < nKey && this->data[id] == data)
	{
		if (isLeaf) removeFromLeaf(id);
		else removeFromInternal(id);
	}
	else
	{
		if (isLeaf)
		{
			cout << "eos cos" << endl;
			return;
		}

		bool flag = ((id == nKey) ? true : false);


		if (childs[id]->nKey == 1) fill(id);

		if (flag && id > nKey) childs[id - 1]->remove(data);
		else childs[id]->remove(data);
	}
}

void B_node::removeFromLeaf(int id)
{
	paintNode(Delete_Color, id, id,1);

	for (int i = id + 1; i < nKey; ++i)	data[i - 1] = data[i],tVisual[i-1]=tVisual[i];

	nKey--;
}

void B_node::removeFromInternal(int id)
{
	paintNode(Delete_Color, id, id,1);

	int k = data[id];
		
	if (childs[id]->nKey >= 2)
	{
		int pred = getPred(id);
		data[id] = pred;
		childs[id]->remove(pred);
	}

	else if (childs[id + 1]->nKey >= 2)
	{
		int succ = getSucc(id);
		data[id] = succ;
		childs[id + 1]->remove(succ);
	}

	else
	{
		merge(id);
		childs[id]->remove(k);
	}
}

int B_node::getPred(int id)
{
	// Keep moving to the right most node until we reach a leaf
	B_node* cur = childs[id];
	while (!cur->isLeaf) cur = cur->childs[cur->nKey];

	// Return the last key of the leaf
	return cur->data[cur->nKey - 1];
}

int B_node::getSucc(int id)
{

	// Keep moving to the left most node  until we reach a leaf
	B_node* cur = childs[id + 1];
	while (!cur->isLeaf) cur = cur->childs[0];

	// Return the first key of the leaf
	return cur->data[0];
}

void B_node::fill(int id)
{
	if (id != 0 && childs[id - 1]->nKey >= 2) borrowFromPrev(id);//if (sibling left) co nhieu con hon 1)

	else if (id != nKey && childs[id + 1]->nKey >= 2) borrowFromNext(id); //if (sibling right) co nhieu con hon 1)

	else
	{
		if (id != nKey) merge(id); //merge with its next sibling
		else merge(id - 1); //merge with its prev sibling
	}
}

void B_node::merge(int id)
{
	B_node* child = childs[id];
	B_node* sibling = childs[id + 1];

	// Pulling a key from the current node and inserting it into (t-1)th position of child
	child->data[1] = data[id];

	// Copying the data from childs[id+1] to childs[id] at the end
	child->data[2] = sibling->data[0];

	// Copying the child pointers from childs[id+1] to childs[id]
	if (!child->isLeaf)
	{
		child->childs[2] = sibling->childs[0];
		child->childs[3] = sibling->childs[1];
	}

	// Moving all data after id in the current node one step before 
	for (int i = id + 1; i < nKey; ++i)	data[i - 1] = data[i];

	// Moving the child pointers after (id+1) in the current node one step before
	for (int i = id + 2; i <= nKey; i++) childs[i - 1] = childs[i];

	// Updating the key count of child and the current node
	child->nKey += sibling->nKey + 1;
	nKey--;

	// Freeing the memory occupied by sibling
	delete(sibling);
	return;
}

void B_node::borrowFromPrev(int id)
{

	B_node* child = childs[id];
	B_node* sibling = childs[id - 1];

	// The last key from childs[id-1] goes up to the parent and key[id-1]
	// from parent is inserted as the first key in childs[id]. 

	// Moving all key in childs[id] one step ahead
	for (int i = child->nKey - 1; i >= 0; --i) 
		child->data[i + 1] = child->data[i];

	// If childs[id] is not a leaf, move all its child pointers one step ahead
	if (!child->isLeaf)
		for (int i = child->nKey; i >= 0; --i) 
			child->childs[i + 1] = child->childs[i];
	

	// Setting child's first key equal to data[id-1] from the current node
	child->data[0] = data[id - 1];

	// Moving sibling's last child as childs[id]'s first child
	if (!child->isLeaf) 
		child->childs[0] = sibling->childs[sibling->nKey];

	// Moving the key from the sibling to the parent
	data[id - 1] = sibling->data[sibling->nKey - 1];

	child->nKey += 1;
	sibling->nKey -= 1;

	return;
}

void B_node::borrowFromNext(int id)
{

	B_node* child = childs[id];
	B_node* sibling = childs[id + 1];

	// data[id] is inserted as the last key in childs[id]
	child->data[(child->nKey)] = data[id];

	// Sibling's first child is inserted as the last child
	// into childs[id]
	if (!(child->isLeaf))
		child->childs[(child->nKey) + 1] = sibling->childs[0];

	//The first key from sibling is inserted into data[id]
	data[id] = sibling->data[0];

	// Moving all keys in sibling one step behind
	for (int i = 1; i < sibling->nKey; ++i)	
		sibling->data[i - 1] = sibling->data[i];

	// Moving the child pointers one step behind
	if (!sibling->isLeaf)
		for (int i = 1; i <= sibling->nKey; ++i) 
			sibling->childs[i - 1] = sibling->childs[i];

	child->nKey += 1;
	sibling->nKey -= 1;

	return;
}

// Btree

void B_Anime::insertT(int data,bool isAnime)
{
	this->isAnime = isAnime;

	if (root == NULL)
	{
		root = new B_node(true,this);
		root->data[0] = data;  // Insert key
		root->nKey = 1;		   // Update number of keys in root
	}
	else // If tree is not empty
	{
		if (root->nKey == T)// If root is full, then tree grows up
		{
			B_node* tmp = new B_node(false,this);

			tmp->childs[0] = root;// Make old root as child of new root

			tmp->splitChild(0, root);

			int i = 0;
			if (tmp->data[0] < data) i++;
			root = tmp;

			tmp->childs[i]->insertNonFull(data);
		}
		else  root->insertNonFull(data);
	}

}

void B_Anime::Del(int data,bool isAnime)
{
	this->isAnime = isAnime;

	if (!root) return;

	root->remove(data);

	if (root->nKey == 0)
	{
		B_node* tmp = root;
		if (root->isLeaf) root = NULL;
		else root = root->childs[0];

		delete tmp;
	}
}

B_node* B_Anime::Search(B_node*& cur, int data)
{
	cur->paintNode(Chosen_Color, 0, cur->nKey - 1,0);

	int i = 0;
	while (i < cur->nKey && data > cur->data[i]) i++;

	if (i < cur->nKey && data == cur->data[i])
	{
		cur->paintNode(Search_Color, i, i, 1);
		return cur;
	}
	if (cur->isLeaf) return nullptr;

	return Search(cur->childs[i], data);
}

void B_Anime::DelAll(B_node* cur)
{
	if (!cur) return;

	B_node* tmp = cur;

	for (int i = 0; i < cur->nKey; i++) DelAll(cur->childs[i]);

	delete tmp;
	root = NULL;
}

int B_Anime::count_node(B_node* cur)
{
	if (!cur) return 0;

	int res = 1;

	for (auto a : cur->childs) res += count_node(a);

	return res;
}

//draw

void B_Anime::drawFrame(RenderTarget& target, int id) const 
{
	if (id > -1 && AnimeFrameNode.size() > id)
	{
		for (auto a : AnimeFrameLink[id]) target.draw(*a);

		for (auto a : AnimeFrameNode[id]) target.draw(*a);		
	}
}

//create a an empty frame
void B_Anime::MakeNewFrame()
{
	vector<shared_ptr<TreeNode>> tmp{};
	AnimeFrameNode.push_back(tmp);

	vector<Edge*> pmt{};
	AnimeFrameLink.push_back(pmt);
}

void B_Anime::PushCurNode(B_node*& Cur, B_node*& parent)
{
	if (!Cur) return;

	if (Cur == parent) Cur->level = 0; else Cur->level = parent->level + 1;

	if (cnt <= Cur->level)
	{
		vector <B_node*> tmp;
		NodeVector.push_back(tmp);
	}

	cnt = max(cnt, Cur->level + 1);

	NodeVector[Cur->level].push_back(Cur);

	if (!Cur->isLeaf) for (int i = 0; i <= Cur->nKey; i++)
		PushCurNode(Cur->childs[i], Cur);
}

void B_Anime::PushCurLink(Vector2f pos1, Vector2f pos2)
{
	Edge* tmp = new Edge(Type::Link, "", nothing);

	tmp->setPositionByNode(pos1, pos2);

	AnimeFrameLink.back().push_back(tmp);
}

void B_Anime::MakeCurState()
{
	NodeVector.clear();
	MakeNewFrame(); cout << "help but anime" << endl;

	cnt = 0;
	PushCurNode(root, root);
	if (!cnt) return;

	int BottomX = 0;

	for (int i = 0; i < cnt; i++)
		for (int j = 0; j < NodeVector[i].size(); j++)
			for (int k = 0; k <NodeVector[i][j]->nKey; k++)
				if (i == cnt - 1) BottomX++;

	redoSize(BottomX + 2);

	BeginPosX = WINDOW_WIDTH / 2.f - (NODE_RADIUS * BottomX * 2 + (NodeVector[cnt - 1].size() - 1) * NODE_DISTANCE * 2) / 2.f;

	int id = cnt - 1;

	for (int j = 0; j < NodeVector[id].size(); j++)
	{
		for (int k = 0; k < NodeVector[id][j]->nKey; k++)
		{
			TreeNode* tmp = new TreeNode(AVL, "", NodeVector[id][j]->data[k]);
			tmp->setPosition({ BeginPosX,NODE_POS_HEAD + ((NODE_DISTANCE * 2) * id) });

			shared_ptr <TreeNode> ttt(tmp);
			AnimeFrameNode.back().push_back(ttt);
			NodeVector[id][j]->tVisual[k] = ttt;

			BeginPosX += NODE_RADIUS * 2.f;
		}
		BeginPosX += NODE_DISTANCE * 2;
	}

	while (id--)
	{
		for (int j = 0; j < NodeVector[id].size(); j++)
		{
			auto& Cur = NodeVector[id][j];
			BeginPosX = (Cur->childs[0]->tVisual[0]->Cir.getPosition().x + Cur->childs[Cur->nKey]->tVisual[Cur->childs[Cur->nKey]->nKey - 1]->Cir.getPosition().x) / 2.f
				- Cur->nKey * NODE_RADIUS / 2.f;

			for (int k = 0; k < Cur->nKey; k++)
			{
				TreeNode* tmp = new TreeNode(AVL, "", Cur->data[k]);
				tmp->setPosition({ BeginPosX,NODE_POS_HEAD + ((NODE_DISTANCE * 2) * id) });

				shared_ptr <TreeNode> ttt(tmp);
				AnimeFrameNode.back().push_back(ttt);
				Cur->tVisual[k] = ttt;

				BeginPosX += NODE_RADIUS * 2.f;
			}
		}
	}

	for (int i = 0; i < cnt - 1; i++)
	{
		for (int j = 0; j < NodeVector[i].size(); j++) if (NodeVector[i][j]->nKey)
		{
			int k = 0;
			for (; k < NodeVector[i][j]->nKey; k++) PushCurLink(NodeVector[i][j]->tVisual[k]->Cir.getPosition() - Vector2f(NODE_RADIUS / 2.f + OUTLINE_THICKNESS, -NODE_RADIUS / 2.f), NodeVector[i][j]->childs[k]->middlePos());

			PushCurLink(NodeVector[i][j]->tVisual[k - 1]->Cir.getPosition() + Vector2f(NODE_RADIUS / 2.f, NODE_RADIUS / 2.f), NodeVector[i][j]->childs[k]->middlePos());
		}
	}
}

//create a display_node copy of the tree and setup
void B_Anime::CloneFromTree(SceneNode*& Nodes)
{
	if (n >= 20) isBig = true; else isBig = false; isBig = true;

	cleanUp();

	MakeCurState();
}

void B_Anime::CloneLastFrame()
{
	MakeNewFrame();
	for (auto a : AnimeFrameNode[AnimeFrameNode.size() - 2])
	{
		TreeNode* tmp = new TreeNode(noType, "", 0);
		tmp->Cir = a->Cir;
		tmp->text = a->text;
		tmp->AdditionalText = a->AdditionalText;
		tmp->isDisable = a->isDisable;
		tmp->data = a->data;

		shared_ptr<TreeNode> ttt(tmp);
		AnimeFrameNode.back().push_back(ttt);
	}

	for (auto a : AnimeFrameLink[AnimeFrameLink.size() - 2])
	{
		Edge* tmp = new Edge(noType, "", 0);
		tmp->line = a->line;
		tmp->text = a->text;
		tmp->isDisable = a->isDisable;
		tmp->data = a->data;

		tmp->pos1 = a->pos1;
		tmp->pos2 = a->pos2;

		AnimeFrameLink.back().push_back(tmp);
	}
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

// Anime Making 

void B_Anime::MakeInsertAnime(int data, SceneNode*& Nodes)
{
	isPlaying = 1;
	isHavingAnime = 1;
	isBig = 1;
	isAnime = 1;
	curFrame = 0;

	CloneFromTree(Nodes);

	insertT(data, 1);
}

void B_Anime::MakeDeleteAnime(int data, SceneNode*& Nodes)
{
	isPlaying = 1;
	isHavingAnime = 1;
	isBig = 1;
	isAnime = 1;
	curFrame = 0;

	CloneFromTree(Nodes);

	Del(data,1);
}

void B_Anime::MakeUpdateAnime(int dataDel,int dataAdd,SceneNode*& Nodes)
{
	isPlaying = 1;
	isHavingAnime = 1;
	isBig = 1;
	isAnime = 1;
	curFrame = 0;

	CloneFromTree(Nodes);

	Del(dataDel, 1);
	insertT(dataAdd, 1);
}

void B_Anime::MakeSearchAnime(int data, SceneNode*& Nodes)
{
	isPlaying = 1;
	isHavingAnime = 1;
	isBig = 1;
	isAnime = 1;
	curFrame = 0;

	CloneFromTree(Nodes); isAnime = 1;

	Search(root, data);
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

	for (auto a : AnimeFrameNode) a.clear();
	for (auto a : AnimeFrameLink) for (auto b : a)	delete b;

	AnimeFrameNode.clear();
	AnimeFrameLink.clear();
	AnimeNodePos.clear();

	int n = 0;
	int FirstPos = 0;
	int SecondPos = 0;

	curFrame = 0;
	transProgress = 0;

	BeginPosX = 0;

	isAnime = 0;
}
