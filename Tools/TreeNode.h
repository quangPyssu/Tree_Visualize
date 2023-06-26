#pragma once

#include <SFML/Graphics.hpp>
#include "SceneNode.h";

using namespace sf;


class TreeNode : public SceneNode // inherits  SceneNode
{
public:

	explicit TreeNode(Type type,string text,int data);
	virtual void drawCurrent(RenderTarget& target, RenderStates states) const;
	virtual void setPosition(const Vector2f& position);
	virtual Vector2f getPosition();

	void make(const Vector2f& pos, const string& s);

	int data = nothing;
private:
	Type mType;
	Sprite mSprite;

	CircleShape Cir;
	Text text;

};

