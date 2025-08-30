#include <SFML/Graphics.hpp>
#include <iostream>
#include "grid.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Screen.h"
using namespace std;

int main() {

    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Chess", sf::Style::Fullscreen);

    // Grid Initialization
    Grid grid;

    // Grid Mouse
    sf::Mouse m;

    Pawn* pawn = new Pawn[16];

    for (int i = 0; i < 16; i++) {
        if (i <= 7) {
            pawn[i].pawncolor(0);
            pawn[i].setsprite("Textures/pawnblack.png", 2, -4);
            pawn[i].gridvalue(1, 2,3,4);
            pawn[i].setposition(grid.getgrid(), 1, i, grid.getposition());
        }

        else if (i >= 8){
            pawn[i].pawncolor(1);
            pawn[i].setsprite("Textures/pawnwhite.png", 2, 4);
            pawn[i].gridvalue(2, 1,4,3);
            pawn[i].setposition(grid.getgrid(), 6, i-8, grid.getposition());
        }
    }

    Rook* rook = new Rook[4];
    Bishop* bishops = new Bishop[4];
    Knight* knight = new Knight[4];

    for (int i = 0; i < 4; i++) {
        if (i < 2) {
            rook[i].setsprite("Textures/rookblack.png", 7, -4);
            rook[i].gridvalue(1,2,3,4);
            bishops[i].setsprite("Textures/bishopblack.png", 7, -4);
            bishops[i].gridvalue(1,2,3,4);
            knight[i].setsprite("Textures/knightblack.png", 0, -4);
            knight[i].gridvalue(1,2,3,4);
        }

        else {
            rook[i].setsprite("Textures/rookwhite.png", 7, 4);
            rook[i].gridvalue(2,1,4,3);
            bishops[i].setsprite("Textures/bishopwhite.png", 3, 4);
            bishops[i].gridvalue(2,1,4,3);
            knight[i].setsprite("Textures/knightwhite.png", 4, 4);
            knight[i].gridvalue(2,1,4,3);
        }

    }

    rook[0].setposition(grid.getgrid(), 0, 0, grid.getposition());
    rook[1].setposition(grid.getgrid(), 0, 7, grid.getposition());
    rook[2].setposition(grid.getgrid(), 7, 0, grid.getposition());
    rook[3].setposition(grid.getgrid(), 7, 7, grid.getposition());

    bishops[0].setposition(grid.getgrid(), 0, 2, grid.getposition());
    bishops[1].setposition(grid.getgrid(), 0, 5, grid.getposition());
    bishops[2].setposition(grid.getgrid(), 7, 2, grid.getposition());
    bishops[3].setposition(grid.getgrid(), 7, 5, grid.getposition());

    knight[0].setposition(grid.getgrid(), 0, 1, grid.getposition());
    knight[1].setposition(grid.getgrid(), 0, 6, grid.getposition());
    knight[2].setposition(grid.getgrid(), 7, 1, grid.getposition());
    knight[3].setposition(grid.getgrid(), 7, 6, grid.getposition());

    Queen* queen = new Queen[2];
    King* king = new King[2];

    for (int i = 0; i < 2; i++) {
        if (i < 1) {
            queen[i].setsprite("Textures/queenblack.png", 0, -4);
            queen[i].gridvalue(1,2,3,4);
            queen[i].setposition(grid.getgrid(), 0, 3, grid.getposition());

            king[i].setsprite("Textures/kingblack.png", 0, -4);
            king[i].gridvalue(1,2,3,4);
            king[i].setposition(grid.getgrid(), 0, 4, grid.getposition());
        }
        else {
            queen[i].setsprite("Textures/queenwhite.png", 4, 4);
            queen[i].gridvalue(2,1,4,3);
            queen[i].setposition(grid.getgrid(), 7, 3, grid.getposition());

            king[i].setsprite("Textures/kingwhite.png", 4, 4);
            king[i].gridvalue(2,1,4,3);
            king[i].setposition(grid.getgrid(), 7, 4, grid.getposition());
        }
    }

    Screens backgroundscreen;
    backgroundscreen.setscreen("Textures/bg.jpg",0);

    Screens main;
    main.setscreen("Textures/bg2.jpg", 0);
    bool check = true;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }
        if (check) {
            main.draw(window);
        }

        else {

            backgroundscreen.functionality(m, event, window);
            grid.highlight(m.getPosition().x, m.getPosition().y);

            for (int i = 0; i < 16; i++) {
                if (i < 2) {
                    queen[i].movement(event, grid.getgrid(), m, grid.getposition());
                    king[i].movement(event, grid.getgrid(), m, grid.getposition());
                }

                if (i < 4) {
                    rook[i].movement(event, grid.getgrid(), m, grid.getposition());
                    bishops[i].movement(event, grid.getgrid(), m, grid.getposition());
                    knight[i].movement(event, grid.getgrid(), m, grid.getposition());
                }

                pawn[i].movement(event, grid.getgrid(), m, grid.getposition());
            }

            window.clear();
            
            backgroundscreen.draw(window);
            grid.draw(window);
            for (int i = 0; i < 16; i++) {
                if (i < 2) {
                    queen[i].draw(window);
                    king[i].draw(window);
                }

                if (i < 4) {
                    rook[i].draw(window);
                    bishops[i].draw(window);
                    knight[i].draw(window);
                }

                pawn[i].draw(window);
            }
        }
        

        window.display();

        if (check) {
            Sleep(2000);
            check = false;
        }
    }

    return 0;
}
