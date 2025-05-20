#include "buttons.h"
#include <SFML/Window.hpp>

Buttons::Buttons()
{
	this->path = "";
	this->buttonpositionX = 0;
	this->buttonpositionY = 0;
	this->buttonsizeX = 0;
	this->buttonsizeY = 0;
	exist = true;
}

void Buttons::setButton(string path, float Bsizex, float Bsizey, float Bposx, float Bposy, sf::Color c)
{
	this->path = path;
	this->buttonpositionX = Bposx;
	this->buttonpositionY = Bposy;
	this->buttonsizeX = Bsizex;
	this->buttonsizeY = Bsizey;
	this->color = c;
	exist = true;

	buttonTexture.loadFromFile(path);
	button.setSize(sf::Vector2f(Bsizex, Bsizey));
	button.setPosition(Bposx, Bposy);
	button.setTexture(&buttonTexture);
	button.setFillColor(c);
}

void Buttons::hover(float Bsizex, float Bsizey, float Bposx, float Bposy)
{
	button.setSize(sf::Vector2f(Bsizex, Bsizey));
	button.setPosition(Bposx, Bposy);
}

void Buttons::functionality(sf::Mouse m, sf::Event e, sf::RenderWindow& window)
{
	exist = true;

	if ((m.getPosition().x >= buttonpositionX && m.getPosition().x <= buttonpositionX + buttonsizeX ) && (m.getPosition().y >= (buttonpositionY) && m.getPosition().y <= buttonpositionY + buttonsizeY)) {
		hover(this->buttonsizeX + 20, this->buttonsizeY + 20, this->buttonpositionX - 20, this->buttonpositionY - 20);
		if (e.type == sf::Event::MouseButtonPressed) {
			exist = false;
		}
	}

	else {
		hover(this->buttonsizeX, this->buttonsizeY, this->buttonpositionX, this->buttonpositionY);
	}
}

bool Buttons::getcheck()
{
	return exist;
}

void Buttons::draw(sf::RenderWindow& window)
{
	window.draw(button);
}