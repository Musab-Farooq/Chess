#include <SFML/Graphics.hpp>
#include <iostream>
#include "chessmen.h"
using namespace std;

class Knight : public chessmen {

public:

	Knight();
	void setsprite(string img, int posX, int posY) override;
	void setposition(sf::RectangleShape** grid, int n, int m, int** gridposition) override;
	void gridvalue(int value, int enemy, int king, int kingenemy) override;
	void movement(sf::Event event, sf::RectangleShape** grid, sf::Mouse mouse, int** gridposition) override;
	void draw(sf::RenderWindow& window) override;
};