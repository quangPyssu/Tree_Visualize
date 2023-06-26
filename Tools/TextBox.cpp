#include "TextBox.h"

TextBox::TextBox(Vector2f pos, Vector2f size, string text, Color idleColor, Color hoverColor, Color activeColor, Color borderColor, Color textColor, Vector2f btnDiff,int textLim)
{
	this->height = size.x ? height : size.x;
	this->width = size.y ? width : size.y;

	shape.setSize(Vector2f(this->width, this->height));
	shape.setPosition(pos);

	setPosition(pos);

	this->size = size;
	this->pos = pos;

	//this->btn_cofirm = new Button(x+btn_x, y+btn_y, 0, 0, "CONFIRM", Color::Black, Color::White, Color::Color(90, 90, 90, 155), Color::Color(90, 90, 90, 255), Color::Black);

	box_Stat = IDLE;

	this->text.setFont(ResourceManager::getFont(ResourceManager::Arial, "asset/fonts/ArialTh.ttf"));
	this->text.setString(text);
	this->text.setCharacterSize((int)this->height / 2);
	this->text.setFillColor(textColor);
	this->text.setPosition(this->shape.getPosition().x + this->shape.getSize().x / 10.f  ,
		this->shape.getPosition().y + this->shape.getSize().y / 2.f - this->text.getGlobalBounds().height / 2.f);


	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;
	this->borderColor = borderColor;
	this->textColor = textColor;

	shape.setFillColor(idleColor);
	shape.setOutlineColor(borderColor);
	shape.setOutlineThickness(OUTLINE_THICKNESS);

	target = NULL;
	this->event = event;

	data = 0;
	this->textLim = textLim;
}

TextBox::~TextBox()
{
	//delete btn_cofirm;
}

void TextBox::updateCurrent(Event& event, Vector2f& MousePos)
{
	// update Box_STATEs

	//btn_cofirm->update(MousePos,event);
	data = 0;

	if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
	{
		isHover = 0;
		if (this->shape.getGlobalBounds().contains(MousePos))box_Stat = ACTIVE;
		else box_Stat = IDLE;
	}
	else if (this->shape.getGlobalBounds().contains(MousePos)) isHover = 1; else isHover = 0;

	if (box_Stat == ACTIVE || isToggle)
	{
		shape.setFillColor(activeColor);
		text.setFillColor(idleColor);

		if (box_Stat == ACTIVE)
		{
			if (event.type == Event::TextEntered)
			{
				if (isprint(event.text.unicode) && input_text.size() < textLim)
					input_text += event.text.unicode;
			}
			else
				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::BackSpace)
					{
						if (!input_text.empty())
							input_text.pop_back();
					}
				}
		}
	}
	else
	{
		shape.setFillColor(idleColor);
		text.setFillColor(activeColor);
		text.setString(default_S);
		if (isHover) shape.setFillColor(hoverColor);
	}

	//if (btn_cofirm->isPressed() || 
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter) confirm(input_text), cout << "data " << data << endl; else data = nothing;
	outputRecal();
}

void TextBox::outputRecal()
{
	if (input_text.size() > 10)
	{
		output_text = "";
		for (int i = 1; i <= 10; i++)
			output_text = input_text[input_text.size() - i] + output_text;
		output_text = "..." + output_text;
	}
	else output_text = input_text;

	if (input_text != "" || box_Stat == ACTIVE)
	{
		if (box_Stat == ACTIVE)
		{
			static sf::Time text_effect_time;
			static bool show_cursor;

			text_effect_time += clock.restart();

			if (text_effect_time >= sf::seconds(0.5f))
			{
				show_cursor = !show_cursor;
				text_effect_time = sf::Time::Zero;
			}
			text.setString(output_text + (show_cursor ? '_' : ' '));
		}
		else text.setString(output_text);
	}
	else text.setString(default_S);
}

void TextBox::drawCurrent(RenderTarget& target, RenderStates states) const
{
	target.draw(shape);
	target.draw(text);
	//btn_cofirm->render(target);
}

bool TextBox::is_number(const string& s)
{
	return !s.empty() && find_if(s.begin(),	s.end(), [](unsigned char c) { return !isdigit(c); }) == s.end();
}

void TextBox::confirm(const string& s)
{
	data = nothing;
	if (is_number(s))
	{
		data = stoi(s);
		
		input_text = "";
	}
}

