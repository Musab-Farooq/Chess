#include "grid.h"

const int rows = 8;
const int cols = 8;
const float cellSize = 80.0f;

Grid::Grid()
{
    // Initializing Background.
    backgroundTexture.loadFromFile("Textures/background.jpg");
    backgroundSprite.setTexture(backgroundTexture);
   // backgroundSprite.setColor(sf::Color(255, 255, 255, 255 * 0.9));
    backgroundSprite.setPosition(327, 28);


    board = new sf::RectangleShape* [rows];
    for (int i = 0; i < rows; i++) {
        board[i] = new sf::RectangleShape[cols];
    }

    float startX = 363;
    float startY = 64;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            board[i][j].setSize(sf::Vector2f(cellSize, cellSize));
            board[i][j].setFillColor(sf::Color::Transparent);
            board[i][j].setPosition(startX + j * cellSize, startY + i * cellSize);
        }
    }

    position = new int* [rows];
    for (int i = 0; i < rows; i++) {
        position[i] = new int[cols];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            position[i][j] = 0;
        }
    }
}

void Grid::highlight(int posX, int posY)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((board[i][j].getPosition().x <= posX && board[i][j].getPosition().x + cellSize >= posX) && (board[i][j].getPosition().y <= posY && board[i][j].getPosition().y + cellSize >= posY)) {
                board[i][j].setFillColor(sf::Color{ 0,0,255,80 });
            }

            else {
                board[i][j].setFillColor(sf::Color::Transparent);
            }
        }
    }
}

sf::RectangleShape** Grid::getgrid()
{
    return this->board;
}

int** Grid::getposition()
{
    return this->position;
}

void Grid::draw(sf::RenderWindow& window)
{
    window.draw(backgroundSprite);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            window.draw(board[i][j]);
        }
    }
}
