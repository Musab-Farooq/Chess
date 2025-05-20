#include "Pawn.h"
const int rows = 8;
const int cols = 8;
const float cellSize = 80.0f;

Pawn::Pawn()
{
    this->exist = true;
    this->firstmove = true;
    this->movementsound.openFromFile("Music/4.mp3");
    this->movementsound.setVolume(60);
    this->kingcheck = false;
}

void Pawn::pawncolor(bool b)
{
    this->color = b;
}

void Pawn::setsprite(string img, int posX, int posY)
{
    this->texture.loadFromFile(img);
    this->sprite.setTexture(texture);

    this->spriteposX = posX;
    this->spriteposY = posY;
}

void Pawn::setposition(sf::RectangleShape** grid, int n, int m, int** gridposition)
{
    this->verticle = n;
    this->horizontal = m;
    gridposition[verticle][horizontal] = gridval;
    this->sprite.setPosition(grid[verticle][horizontal].getPosition().x + spriteposX, grid[verticle][horizontal].getPosition().y + spriteposY);
}

void Pawn::gridvalue(int value, int enemy, int king, int kingenemy)
{
    this->gridval = value;
    this->enemyposition = enemy;
    this->king = king;
    this->kingenemy = kingenemy;
}

void Pawn::movement(sf::Event event, sf::RectangleShape** grid, sf::Mouse mouse, int** gridposition)
{
    if (gridposition[verticle][horizontal] == enemyposition) {
        exist = false;
    }

    if (exist) {
        if ((grid[verticle][horizontal].getPosition().x <= mouse.getPosition().x && grid[verticle][horizontal].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle][horizontal].getPosition().y <= mouse.getPosition().y && grid[verticle][horizontal].getPosition().y + 80 >= mouse.getPosition().y)) {
            if (event.type == sf::Event::MouseButtonPressed) {
                while (mouse.isButtonPressed(sf::Mouse::Left)) {
                    sprite.setPosition(mouse.getPosition().x, mouse.getPosition().y);
                }

                if (!color) {
                    if (firstmove) {
                        if ((grid[verticle + 1][horizontal].getPosition().x <= mouse.getPosition().x && grid[verticle + 1][horizontal].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle + 1][horizontal].getPosition().y <= mouse.getPosition().y && grid[verticle + 1][horizontal].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle + 1][horizontal] != gridval && gridposition[verticle + 1][horizontal] != enemyposition) && (gridposition[verticle + 1][horizontal] != king && gridposition[verticle + 1][horizontal] != kingenemy)) {
                            gridposition[verticle][horizontal] = 0;
                            verticle += 1;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        else if ((grid[verticle + 2][horizontal].getPosition().x <= mouse.getPosition().x && grid[verticle + 2][horizontal].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle + 2][horizontal].getPosition().y <= mouse.getPosition().y && grid[verticle + 2][horizontal].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle + 1][horizontal] != gridval && gridposition[verticle + 1][horizontal] != enemyposition) && (gridposition[verticle + 2][horizontal] != king && gridposition[verticle + 2][horizontal] != kingenemy) && (gridposition[verticle + 2][horizontal] != gridval && gridposition[verticle + 2][horizontal] != enemyposition) && (gridposition[verticle + 1][horizontal] != king && gridposition[verticle + 1][horizontal] != kingenemy)) {
                            gridposition[verticle][horizontal] = 0;
                            verticle += 2;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        else if ((grid[verticle + 1][horizontal + 1].getPosition().x <= mouse.getPosition().x && grid[verticle + 1][horizontal + 1].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle + 1][horizontal + 1].getPosition().y <= mouse.getPosition().y && grid[verticle + 1][horizontal + 1].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle + 1][horizontal + 1] == enemyposition)) {
                            gridposition[verticle][horizontal] = 0;
                            verticle += 1;
                            horizontal += 1;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        else if ((grid[verticle + 1][horizontal - 1].getPosition().x <= mouse.getPosition().x && grid[verticle + 1][horizontal - 1].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle + 1][horizontal - 1].getPosition().y <= mouse.getPosition().y && grid[verticle + 1][horizontal - 1].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle + 1][horizontal - 1] == enemyposition)) {
                            gridposition[verticle][horizontal] = 0;
                            verticle += 1;
                            horizontal -= 1;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        //else if ((grid[verticle + 1][horizontal + 1].getPosition().x <= mouse.getPosition().x && grid[verticle + 1][horizontal + 1].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle + 1][horizontal + 1].getPosition().y <= mouse.getPosition().y && grid[verticle + 1][horizontal + 1].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle + 1][horizontal + 1] == kingenemy)) {
                        //    this->movementsound.play();
                        //}

                        //else if ((grid[verticle + 1][horizontal - 1].getPosition().x <= mouse.getPosition().x && grid[verticle + 1][horizontal - 1].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle + 1][horizontal - 1].getPosition().y <= mouse.getPosition().y && grid[verticle + 1][horizontal - 1].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle + 1][horizontal - 1] == kingenemy)) {
                        //    this->movementsound.play();
                        //}

                        else {
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        this->firstmove = false;
                    }

                    else {
                        if ((grid[verticle + 1][horizontal].getPosition().x <= mouse.getPosition().x && grid[verticle + 1][horizontal].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle + 1][horizontal].getPosition().y <= mouse.getPosition().y && grid[verticle + 1][horizontal].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle + 1][horizontal] != gridval && gridposition[verticle + 1][horizontal] != enemyposition) && (gridposition[verticle + 1][horizontal] != king && gridposition[verticle + 1][horizontal] != kingenemy)) {
                            gridposition[verticle][horizontal] = 0;
                            verticle += 1;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        else if ((grid[verticle + 1][horizontal + 1].getPosition().x <= mouse.getPosition().x && grid[verticle + 1][horizontal + 1].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle + 1][horizontal + 1].getPosition().y <= mouse.getPosition().y && grid[verticle + 1][horizontal + 1].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle + 1][horizontal + 1] == enemyposition)) {
                            gridposition[verticle][horizontal] = 0;
                            verticle += 1;
                            horizontal += 1;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        else if ((grid[verticle + 1][horizontal - 1].getPosition().x <= mouse.getPosition().x && grid[verticle + 1][horizontal - 1].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle + 1][horizontal - 1].getPosition().y <= mouse.getPosition().y && grid[verticle + 1][horizontal - 1].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle + 1][horizontal - 1] == enemyposition)) {
                            gridposition[verticle][horizontal] = 0;
                            verticle += 1;
                            horizontal -= 1;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        else {
                            setposition(grid, verticle, horizontal, gridposition);
                        }
                    }
                }

                else {
                    if (firstmove) {
                        if ((grid[verticle - 1][horizontal].getPosition().x <= mouse.getPosition().x && grid[verticle - 1][horizontal].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle - 1][horizontal].getPosition().y <= mouse.getPosition().y && grid[verticle - 1][horizontal].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle - 1][horizontal] != gridval && gridposition[verticle + 1][horizontal] != enemyposition) && (gridposition[verticle + 1][horizontal] != king && gridposition[verticle + 1][horizontal] != kingenemy)) {
                            gridposition[verticle][horizontal] = 0;
                            verticle -= 1;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        else if ((grid[verticle - 2][horizontal].getPosition().x <= mouse.getPosition().x && grid[verticle - 2][horizontal].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle - 2][horizontal].getPosition().y <= mouse.getPosition().y && grid[verticle - 2][horizontal].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle - 1][horizontal] != gridval && gridposition[verticle - 1][horizontal] != enemyposition) && (gridposition[verticle - 2][horizontal] != king && gridposition[verticle - 2][horizontal] != kingenemy) && (gridposition[verticle - 2][horizontal] != gridval && gridposition[verticle - 2][horizontal] != enemyposition) && (gridposition[verticle - 1][horizontal] != king && gridposition[verticle - 1][horizontal] != kingenemy)) {
                            gridposition[verticle][horizontal] = 0;
                            verticle -= 2;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        else if ((grid[verticle - 1][horizontal + 1].getPosition().x <= mouse.getPosition().x && grid[verticle - 1][horizontal + 1].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle - 1][horizontal + 1].getPosition().y <= mouse.getPosition().y && grid[verticle - 1][horizontal + 1].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle - 1][horizontal + 1] == enemyposition)) {
                            gridposition[verticle][horizontal] = 0;
                            verticle -= 1;
                            horizontal += 1;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        else if ((grid[verticle - 1][horizontal - 1].getPosition().x <= mouse.getPosition().x && grid[verticle - 1][horizontal - 1].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle - 1][horizontal - 1].getPosition().y <= mouse.getPosition().y && grid[verticle - 1][horizontal - 1].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle - 1][horizontal - 1] == enemyposition)) {
                            gridposition[verticle][horizontal] = 0;
                            verticle -= 1;
                            horizontal -= 1;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        else {
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        this->firstmove = false;
                    }

                    else {
                        if ((grid[verticle - 1][horizontal].getPosition().x <= mouse.getPosition().x && grid[verticle - 1][horizontal].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle - 1][horizontal].getPosition().y <= mouse.getPosition().y && grid[verticle - 1][horizontal].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle - 1][horizontal] != gridval && gridposition[verticle - 1][horizontal] != enemyposition) && (gridposition[verticle - 1][horizontal] != king && gridposition[verticle - 1][horizontal] != kingenemy)) {
                            gridposition[verticle][horizontal] = 0;
                            verticle -= 1;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        else if ((grid[verticle - 1][horizontal + 1].getPosition().x <= mouse.getPosition().x && grid[verticle - 1][horizontal + 1].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle - 1][horizontal + 1].getPosition().y <= mouse.getPosition().y && grid[verticle - 1][horizontal + 1].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle - 1][horizontal + 1] == enemyposition)) {
                            gridposition[verticle][horizontal] = 0;
                            verticle -= 1;
                            horizontal += 1;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        else if ((grid[verticle - 1][horizontal - 1].getPosition().x <= mouse.getPosition().x && grid[verticle - 1][horizontal - 1].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle - 1][horizontal - 1].getPosition().y <= mouse.getPosition().y && grid[verticle - 1][horizontal - 1].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle - 1][horizontal - 1] == enemyposition)) {
                            gridposition[verticle][horizontal] = 0;
                            verticle -= 1;
                            horizontal -= 1;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        else {
                            setposition(grid, verticle, horizontal, gridposition);
                        }
                    }
                }
            }
        }
    }
}

void Pawn::draw(sf::RenderWindow& window)
{
    if (exist) {
        window.draw(sprite);
    }
}
