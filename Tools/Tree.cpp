#include "Tree.h"

Tree::Tree()
{
	Buttones = new SceneNode();
	Linkes = new SceneNode();
	Nodes = new SceneNode();
	Animes = new SceneNode();

	FunctionGroup = new GUIGroup();

	CreateGroup = new GUIGroup();
	InsertGroup = new GUIGroup();
	DeleteGroup = new GUIGroup();
	SearchGroup = new GUIGroup();

	// testies
	btnTest = new Button(Vector2f(21, 10), Vector2f(30.f, 110), "test", pink, black, red, black, TextAlign::Middle);
	PushToObject(ButtonTranslate(btnTest),Buttones);
	// testies

	btnCreate = new Button(MENU_POS_BOTTOM_LEFT + Vector2f(21, 0), Vector2f(30.f, 110), "Generate", pink, black, red, black, TextAlign::Left);
	btnInsert = new Button(btnCreate->pos + Vector2f(0, btnCreate->size.x + BUTTON_THICKNESS * 2), Vector2f(30, 110), "Insert", pink, black, red, black, TextAlign::Left);
	btnDelete = new Button(btnInsert->pos + Vector2f(0, btnInsert->size.x + BUTTON_THICKNESS * 2), Vector2f(30, 110), "Delete", pink, black, red, black, TextAlign::Left);
	btnSearch = new Button(btnDelete->pos + Vector2f(0, btnDelete->size.x + BUTTON_THICKNESS * 2), Vector2f(30, 110), "Search", pink, black, red, black, TextAlign::Left);
	btnFunctionHub = new Button(MENU_POS_BOTTOM_LEFT, Vector2f(btnCreate->size.x*4, 20), ">", pink, pink, pink+Color(30,0,0), black, TextAlign::Middle);
	btnFunctionHub->SecondText = "<";

	btnCreateRandom = new Button(btnCreate->pos + Vector2f(btnInsert->size.y + OUTLINE_THICKNESS * 5, 0), Vector2f(30.f, 60), "Random", pink, black, red, black, TextAlign::Middle);
	btnCreateLoad= new Button(btnCreate->pos + Vector2f(btnInsert->size.y + btnCreateRandom->size.y +OUTLINE_THICKNESS * 8, 0), Vector2f(30.f, 60), "From File", pink, black, red, black, TextAlign::Middle);

	txtInsert = new TextBox(btnInsert->pos + Vector2f(btnInsert->size.y + OUTLINE_THICKNESS * 5, 0), Vector2f(30, 110), "Input", "Go", pink, black, black, black, white, {120,0 }, { 30,30 }, 10, TextAlign::Middle);
	txtDelete = new TextBox(btnDelete->pos + Vector2f(btnDelete->size.y + OUTLINE_THICKNESS * 5, 0), Vector2f(30, 110), "Input", "Go", pink, black, black, black, white, {120,0 }, { 30,30 }, 10, TextAlign::Middle);
	txtSearch = new TextBox(btnSearch->pos + Vector2f(btnSearch->size.y + OUTLINE_THICKNESS * 5, 0), Vector2f(30, 110), "Input", "Go", pink, black, black, black, white, { 120,0 }, { 30,30 }, 10, TextAlign::Middle);

	shared_ptr <SceneNode> FirstLayer(Buttones);
	shared_ptr <SceneNode> SecondLayer(Linkes);
	shared_ptr <SceneNode> ThirdLayer(Nodes);
	shared_ptr <SceneNode> FourthLayer(Animes);

	this->attachChild(FirstLayer);
	this->attachChild(SecondLayer);
	this->attachChild(ThirdLayer);
	this->attachChild(FourthLayer);

	PushToObject(ButtonTranslate(btnCreateRandom), ButtonTranslate(btnCreate));
	PushToObject(ButtonTranslate(btnCreateLoad), ButtonTranslate(btnCreate));

	PushToObject(TextBoxTranslate(txtInsert), ButtonTranslate(btnInsert));
	PushToObject(TextBoxTranslate(txtDelete), ButtonTranslate(btnDelete));
	PushToObject(TextBoxTranslate(txtSearch), ButtonTranslate(btnSearch));
	

	PushToObject(ButtonTranslate(btnFunctionHub), Buttones);
	PushToObject(ButtonTranslate(btnCreate), Buttones);
	PushToObject(ButtonTranslate(btnInsert), Buttones);
	PushToObject(ButtonTranslate(btnDelete), Buttones);
	PushToObject(ButtonTranslate(btnSearch), Buttones);

	PushToObject(GroupTranslate(FunctionGroup), Buttones);
	PushToObject(GroupTranslate(CreateGroup), Buttones);
	PushToObject(GroupTranslate(InsertGroup), Buttones);
	PushToObject(GroupTranslate(DeleteGroup), Buttones);
	PushToObject(GroupTranslate(SearchGroup), Buttones);

	FunctionGroup->FatherBtn(btnFunctionHub);

	FunctionGroup->adopt(btnCreate, nullptr);
	FunctionGroup->adopt(btnInsert, nullptr);
	FunctionGroup->adopt(btnDelete, nullptr);
	FunctionGroup->adopt(btnSearch, nullptr);

	CreateGroup->FatherBtn(btnCreate);
	CreateGroup->adopt(btnCreateRandom, nullptr);
	CreateGroup->adopt(btnCreateLoad, nullptr);

	DeleteGroup->FatherBtn(btnDelete);
	DeleteGroup->adopt(txtDelete->btn_cofirm,txtDelete);

	InsertGroup->FatherBtn(btnInsert);
	InsertGroup->adopt(txtInsert->btn_cofirm, txtInsert);

	SearchGroup->FatherBtn(btnSearch);
	SearchGroup->adopt(txtSearch->btn_cofirm, txtSearch);
}

Tree::~Tree()
{
}

void Tree::PushToObject(SceneNode* tmp, SceneNode* Father)
{
	shared_ptr <SceneNode> here(tmp);
	Father->attachChild(here);
}

SceneNode* Tree::ButtonTranslate(Button*& btn)
{
	SceneNode* tmp = static_cast<SceneNode*>(btn);
	return tmp;
}

SceneNode* Tree::TextBoxTranslate(TextBox*& txt)
{
	SceneNode* tmp = static_cast<SceneNode*>(txt);
	return tmp;
}

SceneNode* Tree::GroupTranslate(GUIGroup*& grp)
{
	SceneNode* tmp = static_cast<SceneNode*>(grp);
	return tmp;
}
