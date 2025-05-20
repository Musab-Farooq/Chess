#include "Bishop.h"

Bishop::Bishop()
{
    this->exist = true;
    this->movementsound.openFromFile("Music/4.mp3");
    this->movementsound.setVolume(60);
    this->kingcheck = false;
}

void Bishop::setsprite(string img, int posX, int posY)
{
    this->texture.loadFromFile(img);
    this->sprite.setTexture(texture);

    this->spriteposX = posX;
    this->spriteposY = posY;
}

void Bishop::setposition(sf::RectangleShape** grid, int n, int m, int** gridposition)
{
    this->verticle = n;
    this->horizontal = m;
    gridposition[verticle][horizontal] = gridval;
    this->sprite.setPosition(grid[verticle][horizontal].getPosition().x + spriteposX, grid[verticle][horizontal].getPosition().y + spriteposY);
}

void Bishop::gridvalue(int value, int enemy, int king, int kingenemy)
{
    this->gridval = value;
    this->enemyposition = enemy;
    this->king = king;
    this->kingenemy = kingenemy;
}

void Bishop::movement(sf::Event event, sf::RectangleShape** grid, sf::Mouse mouse, int** gridposition)
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

                for (int i = 0; i < 8; i++) {
                    if (verticle + i <= 7 && horizontal + i <= 7) {
                        if ((grid[verticle + i][horizontal + i].getPosition().x <= mouse.getPosition().x && grid[verticle + i][horizontal+i].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle + i][horizontal+i].getPosition().y <= mouse.getPosition().y && grid[verticle + i][horizontal+i].getPosition().y + 80 >= mouse.getPosition().y)) {

                            bool check = true;
                            for (int j = i; j > 0; j--) {
                                if (gridposition[verticle + j][horizontal + j] == gridval || gridposition[verticle + j][horizontal + j] == king) {
                                    check = false;
                                    break;
                                }
                                
                                if (j < i && gridposition[verticle + i - j][horizontal + i - j] == enemyposition) {
                                    check = false;
                                    break;
                                }
                            }

                            if (check) {
                                for (int j = i; j > 0; j--) {
                                    if (gridposition[verticle + i - j][horizontal + i - j] == kingenemy) {
                                        this->kingcheck = true;
                                        break;
                                    }
                                }
                                gridposition[verticle][horizontal] = 0;
                                verticle += i;
                                horizontal += i;
                                this->movementsound.play();
                                setposition(grid, verticle, horizontal, gridposition);
                            }
                        }

                        else {
                            setposition(grid, verticle, horizontal, gridposition);
                        }
                    }

                    if (verticle + i <= 7 && horizontal - i >= 0) {
                        if ((grid[verticle + i][horizontal - i].getPosition().x <= mouse.getPosition().x && grid[verticle + i][horizontal - i].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle + i][horizontal - i].getPosition().y <= mouse.getPosition().y && grid[verticle + i][horizontal - i].getPosition().y + 80 >= mouse.getPosition().y)) {
                            
                            bool check = true;
                            for (int j = i; j > 0; j--) {
                                if (gridposition[verticle + j][horizontal - j] == gridval || gridposition[verticle + j][horizontal - j] == king) {
                                    check = false;
                                    break;
                                }

                                if (j < i && gridposition[verticle + i - j][horizontal - i + j] == enemyposition) {
                                    check = false;
                                    break;
                                }
                            }

                            if (check) {
                                for (int j = i; j > 0; j--) {
                                    if (gridposition[verticle + i - j][horizontal - i + j] == kingenemy) {
                                        this->kingcheck = true;
                                        break;
                                    }
                                }
                                gridposition[verticle][horizontal] = 0;
                                verticle += i;
                                horizontal -= i;
                                this->movementsound.play();
                                setposition(grid, verticle, horizontal, gridposition);
                            }
                        }

                        else {
                            setposition(grid, verticle, horizontal, gridposition);
                        }
                    }

                    if (verticle - i >= 0 && horizontal + i <= 7) {
                        if ((grid[verticle - i][horizontal + i].getPosition().x <= mouse.getPosition().x && grid[verticle - i][horizontal + i].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle - i][horizontal + i].getPosition().y <= mouse.getPosition().y && grid[verticle - i][horizontal + i].getPosition().y + 80 >= mouse.getPosition().y)) {
                            
                            bool check = true;
                            for (int j = i; j > 0; j--) {
                                if (gridposition[verticle - j][horizontal + j] == gridval || gridposition[verticle - j][horizontal + j] == king) {
                                    check = false;
                                    break;
                                }

                                if (j < i && gridposition[verticle - i + j][horizontal + i - j] == enemyposition) {
                                    check = false;
                                    break;
                                }
                            }

                            if (check) {
                                for (int j = i; j > 0; j--) {
                                    if (gridposition[verticle - i + j][horizontal + i - j] == kingenemy) {
                                        this->kingcheck = true;
                                        break;
                                    }
                                }
                                gridposition[verticle][horizontal] = 0;
                                verticle -= i;
                                horizontal += i;
                                this->movementsound.play();
                                setposition(grid, verticle, horizontal, gridposition);
                            }
                        }

                        else {
                            setposition(grid, verticle, horizontal, gridposition);
                        }
                    }

                    if (verticle - i >= 0 && horizontal - i >= 0) {
                        if ((grid[verticle - i][horizontal - i].getPosition().x <= mouse.getPosition().x && grid[verticle - i][horizontal - i].getPosition().x + 80 >= mouse.getPosition().x) && (grid[verticle - i][horizontal - i].getPosition().y <= mouse.getPosition().y && grid[verticle - i][horizontal - i].getPosition().y + 80 >= mouse.getPosition().y)) {
                            
                            bool check = true;
                            for (int j = i; j > 0; j--) {
                                if (gridposition[verticle - j][horizontal - j] == gridval || gridposition[verticle - j][horizontal - j] == king) {
                                    check = false;
                                    break;
                                }

                                if (j < i && gridposition[verticle - i + j][horizontal - i + j] == enemyposition) {
                                    check = false;
                                    break;
                                }
                            }

                            if (check) {
                                for (int j = i; j > 0; j--) {
                                    if (gridposition[verticle - i + j][horizontal - i + j] == kingenemy) {
                                        this->kingcheck = true;
                                        break;
                                    }
                                }
                                gridposition[verticle][horizontal] = 0;
                                verticle -= i;
                                horizontal -= i;
                                this->movementsound.play();
                                setposition(grid, verticle, horizontal, gridposition);
                            }
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

void Bishop::draw(sf::RenderWindow& window)
{
    if (exist) {
        window.draw(sprite);
    }
}
