#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;

class chessmen {

protected:
	sf::Sprite sprite;
	sf::Texture texture;
	bool exist;
	int verticle;
	int horizontal;
	int gridval;
	int spriteposX;
	int spriteposY;
	int enemyposition;
	sf::Music movementsound;
	int king;
	int kingenemy;
	bool kingcheck;

public:

	virtual void setsprite(string img, int posX, int posY) = 0;
	virtual void setposition(sf::RectangleShape** grid, int n, int m, int** gridposition) = 0;
	virtual void gridvalue(int value, int enemy, int king, int kingenemy) = 0;
	virtual void movement(sf::Event event, sf::RectangleShape** grid, sf::Mouse mouse, int** gridposition) = 0;
	//virtual void Check();
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual ~chessmen() {}
};