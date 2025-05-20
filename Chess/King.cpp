#include "King.h"

King::King()
{
    this->exist = true;
    this->movementsound.openFromFile("Music/4.mp3");
    this->movementsound.setVolume(60);
}

void King::setsprite(string img, int posX, int posY)
{
    this->texture.loadFromFile(img);
    this->sprite.setTexture(texture);

    this->spriteposX = posX;
    this->spriteposY = posY;
}

void King::setposition(sf::RectangleShape** grid, int n, int m, int** gridposition)
{
    this->verticle = n;
    this->horizontal = m;
    gridposition[verticle][horizontal] = gridval;
    this->sprite.setPosition(grid[verticle][horizontal].getPosition().x + spriteposX, grid[verticle][horizontal].getPosition().y + spriteposY);
}

void King::gridvalue(int value, int enemy, int king, int kingenemy)
{
    this->gridval = value;
    this->enemyposition = enemy;
    this->king = king;
    this->kingenemy = kingenemy;
}

void King::movement(sf::Event event, sf::RectangleShape** grid, sf::Mouse mouse, int** gridposition)
{
    if (gridposition[verticle][horizontal] == enemyposition) {
        exist = false;
    }

    if (exist) {
        if ((grid[verticle][horizontal].getPosition().x <= mouse.getPosition().x && grid[verticle][horizontal].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle][horizontal].getPosition().y <= mouse.getPosition().y && grid[verticle][horizontal].getPosition().y + 80 >= mouse.getPosition().y)) {
            if (event.type == sf::Event::MouseButtonPressed) {
                while (mouse.isButtonPressed(sf::Mouse::Left)) {
                    //sprite.setPosition(mouse.getPosition().x, mouse.getPosition().y);
                }

                if ((verticle >= 0 && verticle <= 7) && (horizontal >= 0 && horizontal <= 7)) {
                    if (verticle + 1 <= 7) {
                        if ((grid[verticle + 1][horizontal].getPosition().x <= mouse.getPosition().x && grid[verticle + 1][horizontal].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle + 1][horizontal].getPosition().y <= mouse.getPosition().y && grid[verticle + 1][horizontal].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle + 1][horizontal] != gridval)) {
                            gridposition[verticle][horizontal] = 0;
                            verticle += 1;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        else {
                            setposition(grid, verticle, horizontal, gridposition);
                        }
                    }

                    if (horizontal + 1 <= 7) {
                        if ((grid[verticle][horizontal + 1].getPosition().x <= mouse.getPosition().x && grid[verticle][horizontal + 1].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle][horizontal + 1].getPosition().y <= mouse.getPosition().y && grid[verticle][horizontal + 1].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle][horizontal + 1] != gridval)) {
                            gridposition[verticle][horizontal] = 0;
                            horizontal += 1;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        else {
                            setposition(grid, verticle, horizontal, gridposition);
                        }
                    }

                    if (verticle - 1 >= 0) {
                        if ((grid[verticle - 1][horizontal].getPosition().x <= mouse.getPosition().x && grid[verticle - 1][horizontal].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle - 1][horizontal].getPosition().y <= mouse.getPosition().y && grid[verticle - 1][horizontal].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle - 1][horizontal] != gridval)) {
                            gridposition[verticle][horizontal] = 0;
                            verticle -= 1;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        else {
                            setposition(grid, verticle, horizontal, gridposition);
                        }
                    }

                    if (horizontal - 1 >= 0) {
                        if ((grid[verticle][horizontal - 1].getPosition().x <= mouse.getPosition().x && grid[verticle][horizontal - 1].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle][horizontal - 1].getPosition().y <= mouse.getPosition().y && grid[verticle][horizontal - 1].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle][horizontal - 1] != gridval)) {
                            gridposition[verticle][horizontal] = 0;
                            horizontal -= 1;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        else {
                            setposition(grid, verticle, horizontal, gridposition);
                        }
                    }

                    if (verticle + 1 <= 7 && horizontal + 1 <= 7) {
                        if ((grid[verticle + 1][horizontal + 1].getPosition().x <= mouse.getPosition().x && grid[verticle + 1][horizontal + 1].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle + 1][horizontal + 1].getPosition().y <= mouse.getPosition().y && grid[verticle + 1][horizontal + 1].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle + 1][horizontal + 1] != gridval)) {
                            gridposition[verticle][horizontal] = 0;
                            verticle += 1;
                            horizontal += 1;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        else {
                            setposition(grid, verticle, horizontal, gridposition);
                        }
                    }

                    if (verticle + 1 <= 7 && horizontal - 1 >= 0) {
                        if ((grid[verticle + 1][horizontal - 1].getPosition().x <= mouse.getPosition().x && grid[verticle + 1][horizontal - 1].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle + 1][horizontal - 1].getPosition().y <= mouse.getPosition().y && grid[verticle + 1][horizontal - 1].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle + 1][horizontal - 1] != gridval)) {
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

                    if (verticle - 1 >= 0 && horizontal + 1 <= 7) {
                        if ((grid[verticle - 1][horizontal + 1].getPosition().x <= mouse.getPosition().x && grid[verticle - 1][horizontal + 1].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle - 1][horizontal + 1].getPosition().y <= mouse.getPosition().y && grid[verticle - 1][horizontal + 1].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle - 1][horizontal + 1] != gridval)) {
                            gridposition[verticle][horizontal] = 0;
                            verticle -= 1;
                            horizontal += 1;
                            this->movementsound.play();
                            setposition(grid, verticle, horizontal, gridposition);
                        }

                        else {
                            setposition(grid, verticle, horizontal, gridposition);
                        }
                    }

                    if (verticle - 1 >= 0 && horizontal - 1 >= 0) {
                        if ((grid[verticle - 1][horizontal - 1].getPosition().x <= mouse.getPosition().x && grid[verticle - 1][horizontal - 1].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle - 1][horizontal - 1].getPosition().y <= mouse.getPosition().y && grid[verticle - 1][horizontal - 1].getPosition().y + 80 >= mouse.getPosition().y) && (gridposition[verticle - 1][horizontal - 1] != gridval)) {
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

void King::draw(sf::RenderWindow& window)
{
    if (exist) {
        window.draw(sprite);
    }
}
