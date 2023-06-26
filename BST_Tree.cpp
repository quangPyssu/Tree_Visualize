#include "BST_Tree.h"

BST_node* BST_Tree::new_node(int data)
{
	BST_node* tmp = new BST_node;

	tmp->data = data;
	return tmp;
}

BST_Tree::BST_Tree()
{
	Buttones = new SceneNode();
	TextBoxes = new SceneNode();
	Linkes = new SceneNode();
	Nodes = new SceneNode();

	butt1 = new Button(Vector2f(0, 0), Vector2f(50, 100), "Generate", cyan, yellow, red, black);
	butt2 = new Button(Vector2f(0, 110), Vector2f(50, 100), "Show", black, yellow, red, white);

	tet1 = new TextBox({ 0,52 }, { 50,100 }, "Text Box", cyan, yellow, red, black,black,{60,0},10);

	shared_ptr <SceneNode> FirstLayer(Buttones);
	shared_ptr <SceneNode> SecondLayer(TextBoxes);
	shared_ptr <SceneNode> ThirdLayer(Linkes);
	shared_ptr <SceneNode> FourthLayer(Nodes);

	PushBtn(butt1);
	PushBtn(butt2);

	PushTxtBox(tet1);

	this->attachChild(FirstLayer);
	this->attachChild(SecondLayer);
	this->attachChild(ThirdLayer);
	this->attachChild(FourthLayer);
}

void BST_Tree::CreateVisual()
{
	if (!root) return;

	Nodes->Children.clear();
	Linkes->Children.clear();

	BeginPosX = WINDOW_WIDTH / 2 - (NODE_DISTANCE*count_node(root));

	cnt = 0;
	Push(root,cnt);
}

int BST_Tree::count_node(BST_node* cur)
{
	if (!cur) return 0;
		
	int res = (1 + count_node(cur->left) + count_node(cur->right));

	return res;
}

void BST_Tree::Push(BST_node* &Cur,int& cnt)
{
	if (!Cur) return;
	
	if (Cur->left)
	{
		Push(Cur->left,cnt);
	}
	
	TreeNode* tmp=new TreeNode(Type::BST,"", Cur->data);

	//tmp->setPosition({ !Cur->par ? 500 : Cur->par->tVisual->getPosition().x + (NODE_DISTANCE*4 / Cur->level) * (Cur->isLeft ? -1 : 1),NODE_POS_HEAD + ((NODE_DISTANCE) * Cur->level)});
	
	tmp->setPosition({ BeginPosX+ NODE_DISTANCE*2 * cnt,NODE_POS_HEAD + ((NODE_DISTANCE)*Cur->level) });

	shared_ptr <TreeNode> here(tmp);
	Nodes->attachChild(here);
	
	Cur->tVisual = here;
	cnt++;
	//cout << Cur->data << " " << cnt << endl;

	if (Cur->right)
	{
		Push(Cur->right,cnt);

	}

	if (Cur->left) PushLink(Cur,Cur->left);
	if (Cur->right) PushLink(Cur,Cur->right);

	return;
}

void BST_Tree::PushLink(BST_node*& node1, BST_node*& node2)
{
	Edge* tmp = new Edge(Type::Link, "",nothing);

	tmp->setPositionByNode(node1->tVisual->getPosition() , node2->tVisual->getPosition() );

	shared_ptr <Edge> here(tmp);
	Linkes->attachChild(here);
}

void BST_Tree::PushBtn(Button* &btn)
{
	shared_ptr <Button> here(btn);
	Buttones->attachChild(here);
}

void BST_Tree::PushTxtBox(TextBox* &TxtBox)
{
	shared_ptr <TextBox> here(TxtBox);
	TextBoxes->attachChild(here);
}

void BST_Tree::drawCurrent(RenderTarget& target, RenderStates states) const
{
}

void BST_Tree::updateCurrent(Event& event, Vector2f& MousePos)
{
	if (butt1->isPressed())
	{
		cout << "roger that" << endl;

		DelAll(root);

		for (int i = 0; i < 10; i++) insertT(root, rand() % 50 + 10, root, true);

		print_console();
	}

	if (butt2->isPressed())
	{

		CreateVisual();
		cout << " df " << endl;

		cout << "here :" << Children.size() << endl;
	}
}

BST_node* BST_Tree::insertT(BST_node*& cur, int data, BST_node*& parent,bool isLeft)
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

void BST_Tree::print_console(BST_node* cur, string prefix,bool isLeft)
{
	if (!cur) return;

	if (isLeft) cout << "|--"; else cout << "`--";

	cout << cur->data << endl;

	if (cur->left) cout << "   " + prefix;
	print_console(cur->left, cur->right ? prefix + "|  " : prefix + "   ", 1);

	if (cur->right) cout << "   " + prefix;
	print_console(cur->right, prefix + "   ", 0);
}

void BST_Tree::print_console()
{
	print_console(root, "", 1);
}

BST_node* BST_Tree::Del(BST_node* &cur,int data)
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
		BST_node* par = cur;
		BST_node* tmp = cur->left;

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
		BST_node* tmp = cur->left;
		delete cur;

		return tmp;
	}
	else			// have right child
	{
		BST_node* tmp = cur->right;
		delete cur;

		return tmp;
	}


	return cur;
}

BST_node* BST_Tree::Search(BST_node* &cur,int data)
{
	if (!cur) return NULL;

	if (cur->data > data) return Search(cur->left, data);
	if (cur->data < data) return Search(cur->right, data);
		
	return cur;
}

void BST_Tree::DelAll(BST_node* cur)
{
	if (!cur) return;

	BST_node* tmp = cur;

	DelAll(cur->left);
	DelAll(cur->right);

	delete tmp;
	root = NULL;
}
