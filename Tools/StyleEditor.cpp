#include "StyleEditor.h"

StyleEditor::StyleEditor()
{
	ColorBox.setSize({ 360,100 });
	SizeBox.setSize({ 60,100 });

	ColorBox.setOutlineColor(black);
	SizeBox.setOutlineColor(black);

	ColorBox.setOutlineThickness(OUTLINE_THICKNESS*2);
	SizeBox.setOutlineThickness(OUTLINE_THICKNESS*2);

	ColorBox.setPosition(Constants::MENU_POS_BOTTOM_LEFT+Vector2f(31 + OUTLINE_THICKNESS*2,-ColorBox.getSize().y- OUTLINE_THICKNESS*2-1));
	SizeBox.setPosition(ColorBox.getPosition() + Vector2f(ColorBox.getSize().x+ OUTLINE_THICKNESS*2,0 ));

	ColorText.setFont(ResourceManager::getFont(ResourceManager::Arial, "asset/fonts/ArialTh.ttf"));
	ColorText.setString("Color");
	ColorText.setCharacterSize(25);
	ColorText.setFillColor(black);
	ColorText.setPosition(ColorBox.getPosition().x + ColorBox.getSize().x / 2.f - ColorText.getGlobalBounds().width / 2.f, ColorBox.getPosition().y );

	SizeText.setFont(ResourceManager::getFont(ResourceManager::Arial, "asset/fonts/ArialTh.ttf"));
	SizeText.setString("Size");
	SizeText.setCharacterSize(22);
	SizeText.setFillColor(black);
	SizeText.setPosition(SizeBox.getPosition().x + SizeBox.getSize().x / 2.f - SizeText.getGlobalBounds().width / 2.f, SizeBox.getPosition().y);

	btnRed = new Button(ColorBox.getPosition() + Vector2f(15, 29), { 30,30 }, "", red, red + Color(50, 50, 50), red, red, Middle);
	btnRed->shape.setOutlineThickness(1); btnRed->shape.setOutlineColor(black);
	PushToObject(btnRed, this);

	btnYellow = new Button(btnRed->shape.getPosition() + Vector2f(btnRed->shape.getSize().x+5, 0), btnRed->shape.getSize(), "", yellow, yellow + Color(50, 50, 50), yellow, yellow, Middle);
	btnYellow->shape.setOutlineThickness(1); btnYellow->shape.setOutlineColor(black);
	PushToObject(btnYellow, this);

	btnCyan = new Button(btnYellow->shape.getPosition() + Vector2f(btnRed->shape.getSize().x + 5, 0), btnRed->shape.getSize(), "", cyan, cyan+ Color(50, 50, 50), cyan, cyan, Middle);
	btnCyan->shape.setOutlineThickness(1); btnCyan->shape.setOutlineColor(black);
	PushToObject(btnCyan, this);

	btnOrange = new Button(btnCyan->shape.getPosition() + Vector2f(btnRed->shape.getSize().x + 5, 0), btnRed->shape.getSize(), "", orange, orange + Color(50, 50, 50), orange, orange, Middle);
	btnOrange->shape.setOutlineThickness(1); btnOrange->shape.setOutlineColor(black);
	PushToObject(btnOrange, this);

	btnPink = new Button(btnOrange->shape.getPosition() + Vector2f(btnRed->shape.getSize().x + 5, 0), btnRed->shape.getSize(), "", pink, pink + Color(50, 50, 50), pink, pink, Middle);
	btnPink->shape.setOutlineThickness(1); btnPink->shape.setOutlineColor(black);
	PushToObject(btnPink, this);

	btnGrey = new Button(btnPink->shape.getPosition() + Vector2f(btnRed->shape.getSize().x + 5, 0), btnRed->shape.getSize(), "", grey, grey + Color(50, 50, 50), grey, grey, Middle);
	btnGrey->shape.setOutlineThickness(1); btnGrey->shape.setOutlineColor(black);
	PushToObject(btnGrey, this);

	btnBlue = new Button(btnGrey->shape.getPosition() + Vector2f(btnRed->shape.getSize().x + 5, 0), btnRed->shape.getSize(), "", blue, blue + Color(50, 50, 50), blue, blue, Middle);
	btnBlue->shape.setOutlineThickness(1); btnBlue->shape.setOutlineColor(black);
	PushToObject(btnBlue, this);

	btnGreen = new Button(btnBlue->shape.getPosition() + Vector2f(btnRed->shape.getSize().x + 5, 0), btnRed->shape.getSize(), "", green, green + Color(50, 50, 50), green, green, Middle);
	btnGreen->shape.setOutlineThickness(1); btnGreen->shape.setOutlineColor(black);
	PushToObject(btnGreen, this);

	btnCurrent = new Button(btnGreen->shape.getPosition() + Vector2f(btnRed->shape.getSize().x + 5, 0), {50,50}, "", Default_Color, Default_Color, Default_Color, Default_Color, Middle);
	btnCurrent->shape.setOutlineThickness(1); btnCurrent->shape.setOutlineColor(black);
	PushToObject(btnCurrent, this);

	btnChosenNode = new Button(btnRed->shape.getPosition() + Vector2f(0, btnRed->shape.getSize().y + 5), { 32,65 }, "Chosen", pink, pink + Color(60, 50, 50), pink , yellow, Middle);
	btnChosenNode->shape.setOutlineThickness(1); btnChosenNode->shape.setOutlineColor(black);
	btnChosenNode->SecondText = ">Chosen<";
	btnChosenNode->ForceOn();
	PushToObject(btnChosenNode, this);

	btnInsertNode = new Button(btnRed->shape.getPosition() + Vector2f(btnChosenNode->shape.getSize().x+5, btnRed->shape.getSize().y + 5), { 32,65 }, "Insert", pink, pink + Color(60, 50, 50), pink, yellow, Middle);
	btnInsertNode->shape.setOutlineThickness(1); btnInsertNode->shape.setOutlineColor(black);
	btnInsertNode->SecondText = ">Insert<";
	PushToObject(btnInsertNode, this);

	btnDeleteNode = new Button(btnInsertNode->shape.getPosition() + Vector2f(btnChosenNode->shape.getSize().x + 5,0), { 32,65 }, "Delete", pink, pink + Color(60, 50, 50), pink, yellow, Middle);
	btnDeleteNode->shape.setOutlineThickness(1); btnDeleteNode->shape.setOutlineColor(black);
	btnDeleteNode->SecondText = ">Delete<";
	PushToObject(btnDeleteNode, this);

	btnSearchNode = new Button(btnDeleteNode->shape.getPosition() + Vector2f(btnChosenNode->shape.getSize().x + 5, 0), { 32,65 }, "Search", pink, pink + Color(60, 50, 50), pink, yellow, Middle);
	btnSearchNode->shape.setOutlineThickness(1); btnSearchNode->shape.setOutlineColor(black);
	btnSearchNode->SecondText = ">Search<";
	PushToObject(btnSearchNode, this);

	ColorGroup = new GUIGroup;
	ColorGroup->adopt(btnChosenNode, NULL);
	ColorGroup->adopt(btnInsertNode, NULL);
	ColorGroup->adopt(btnDeleteNode, NULL);
	ColorGroup->adopt(btnSearchNode, NULL);

	PushToObject(ColorGroup, this);

	btnBig = new Button(SizeBox.getPosition() + Vector2f(5, 30), { 38,50 }, "Big", pink, pink + Color(60, 50, 50), pink, yellow, Middle);
	btnBig->SecondText = ">Big<";
	PushToObject(btnBig, this);

	btnSmall = new Button(SizeBox.getPosition() + Vector2f(5, 69), { 30,50 }, "Small", pink, pink + Color(60, 50, 50), pink, yellow, Middle);
	btnSmall->SecondText = ">Small<";
	btnSmall->ForceOn();
	PushToObject(btnSmall, this);

	SizeGroup = new GUIGroup;
	SizeGroup->adopt(btnBig,NULL);
	SizeGroup->adopt(btnSmall, NULL);
	PushToObject(SizeGroup, this);
}

void StyleEditor::updateCurrent(Event& event, Vector2f& MousePos) 
{
	// update BTN_STATEs

	

	//string s = text.getString();
	//cout << s << " isON: " << isOn << endl;
}

void StyleEditor::drawCurrent(RenderTarget& target, RenderStates states) const 
{
	target.draw(this->ColorBox);
	target.draw(this->SizeBox);
	target.draw(this->ColorText);
	target.draw(this->SizeText);
}
