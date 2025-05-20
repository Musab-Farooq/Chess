# Chess Game

A classic two-player chess game developed using C++ and the SFML (Simple and Fast Multimedia Library) framework. This game provides a digital chessboard where players can move pieces according to standard chess rules, with intuitive mouse-based controls and a fullscreen interface. The game features a main menu and a visually appealing chessboard with piece-specific movement logic and audio feedback.

Features
Gameplay: Play a standard chess game on an 8x8 grid, moving pieces (pawns, rooks, knights, bishops, queens, kings) for both black and white sides. Capture opponent pieces and aim to checkmate the opponent's king.
Graphics: Pixel-art style sprites for all chess pieces (pawnblack.png, pawnwhite.png, rookblack.png, rookwhite.png, knightblack.png, knightwhite.png, bishopblack.png, bishopwhite.png, queenblack.png, queenwhite.png, kingblack.png, kingwhite.png) and a chessboard background (background.jpg, bg.jpg, bg2.jpg), rendered using SFML.
Audio: Movement sound effect (4.mp3) played when pieces are moved, enhancing the immersive experience.

Mechanics:
Board Setup: Standard 8x8 chessboard with pieces initialized in their traditional positions (pawns on rows 2 and 7, rooks at corners, knights, bishops, queens, and kings in their respective starting squares).

Piece Movement:
Pawn: Moves forward one square (or two on the first move) and captures diagonally. Direction depends on color (black moves down, white moves up).
Rook: Moves any number of squares horizontally or vertically, capturing enemy pieces in its path.
Knight: Moves in an L-shape (two squares in one direction, one perpendicular) and can jump over other pieces.
Bishop: Moves any number of squares diagonally, capturing enemy pieces in its path.
Queen: Combines rook and bishop movements, moving any number of squares in any direction (horizontal, vertical, or diagonal).
King: Moves one square in any direction (horizontal, vertical, or diagonal).
Capture Logic: Pieces can capture opponent pieces by moving to their square, removing the enemy piece from the board.
Check Detection: Bishops, rooks, and queens check for king threats (check condition) when moving, though full checkmate logic is not implemented.
Grid System: Uses an 8x8 grid with 80x80 pixel cells, highlighting the selected square for better user interaction.

Controls:
Mouse: Click and drag to select a piece and move it to a valid square. The piece follows the mouse during the drag, and valid moves are checked upon release.
Escape Key: Closes the game.
Back Button: Returns to the main menu from the game screen.
Start Button: Transitions from the main menu to the game screen.
Screens: Includes a main menu (bg2.jpg) with a start button and a game screen with a back button (backbutton.png) to return to the menu.
Technical Details

Classes:
chessmen: Abstract base class defining common properties and virtual methods for all chess pieces (sprite, position, movement, drawing).
Pawn, Rook, Knight, Bishop, Queen, King: Derived classes implementing piece-specific movement rules and capture logic.
Grid: Manages the 8x8 chessboard, handling cell positions, highlighting, and grid state for piece placement.
Screens: Manages the main menu and game screens, including background images and button interactions.
Buttons: Handles clickable buttons with hover effects for menu navigation.
SFML Integration: Utilizes SFML for rendering sprites, handling mouse events, playing audio, and managing the fullscreen window.
Game Loop: Processes events, updates piece positions, highlights selected grid cells, and renders the board and pieces in real-time.
This project demonstrates object-oriented programming, inheritance, polymorphism, event-driven input handling, and SFML-based graphics and audio integration. It’s ideal for learning game development or enjoying a digital chess experience!

Requirements
SFML library
C++ compiler
Texture files (Textures/ folder: pawnblack.png, pawnwhite.png, rookblack.png, rookwhite.png, knightblack.png, knightwhite.png, bishopblack.png, bishopwhite.png, queenblack.png, queenwhite.png, kingblack.png, kingwhite.png, background.jpg, bg.jpg, bg2.jpg, button.png, backbutton.png)
Audio file (Music/ folder: 4.mp3)

How to Run
Ensure SFML is installed and configured in your development environment.
Place all texture and audio files in the respective Textures/ and Music/ directories relative to the executable.
Compile and run main.cpp to start the game in fullscreen mode.
Use the mouse to navigate the main menu and play the game by dragging pieces to valid squares.

Note: To play game without setting up SFML in your system just download the zip file and hit the exe file
