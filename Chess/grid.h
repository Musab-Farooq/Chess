#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Grid {

    sf::RectangleShape** board;
    int** position;
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;

public:

    Grid();
    void highlight(int posX,int posY);
    sf::RectangleShape** getgrid();
    int** getposition();
    void draw(sf::RenderWindow& window);
};