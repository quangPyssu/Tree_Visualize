#include "TreeNode.h"

TreeNode::TreeNode(Type type, string text,int data)
{
	Cir.setFillColor(white);
	Cir.setRadius(NODE_RADIUS);
	Cir.setOutlineThickness(OUTLINE_THICKNESS);
	Cir.setOutlineColor(Default_Color);
	Cir.setOrigin(Vector2f(NODE_RADIUS, NODE_RADIUS));
	Cir.setPosition(-100, -100);

	this->data = data;

	if (this->data != nothing)
	{	
		string s = to_string(this->data);
		text = s;
	}

	this->text.setFont(ResourceManager::getFont(ResourceManager::Arial, "asset/fonts/ArialTh.ttf"));
	this->text.setCharacterSize(font_size);
	this->text.setFillColor(black);
	this->text.setString(text);
	this->text.setPosition(Cir.getPosition().x  - this->text.getGlobalBounds().width / 2.f,
		Cir.getPosition().y  - this->text.getGlobalBounds().height / 2.f );

	mType = type;
}

void TreeNode::drawCurrent(RenderTarget& target, RenderStates states) const 
{
	target.draw(Cir);
	target.draw(text);
}

void TreeNode::setPosition(const Vector2f& position)
{
	Cir.setPosition(position);
	text.setPosition(position.x  - this->text.getGlobalBounds().width / 2.f,position.y  - this->text.getGlobalBounds().height / 2.f);
}

void TreeNode::setSize()
{
	Cir.setRadius(NODE_RADIUS);
	Cir.setOrigin(Vector2f(NODE_RADIUS, NODE_RADIUS));

	text.setCharacterSize(font_size);
}

Vector2f TreeNode::getPosition()
{
	return Cir.getPosition();
}

void TreeNode::make(const Vector2f& pos, const string& s)
{
	Cir.setPosition(pos);

	this->text.setString(s);

	this->text.setPosition(Cir.getPosition().x  - this->text.getGlobalBounds().width / 2.f,
		Cir.getPosition().y  - this->text.getGlobalBounds().height / 2.f);
}