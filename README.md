# ♟️ SFML Chess Game

Welcome to the **SFML Chess Game** — a fully interactive, two-player chess experience developed using **C++** and the **SFML (Simple and Fast Multimedia Library)**. This project brings a digital twist to the timeless game of chess with intuitive controls, beautiful pixel art, and sound effects.


---

## 🚀 Features

### 🎮 Gameplay
- Standard 8x8 chessboard with all major pieces: **Pawn**, **Rook**, **Knight**, **Bishop**, **Queen**, and **King**.
- Fully mouse-controlled: click-and-drag mechanics for intuitive piece movement.
- Turn-based two-player mode (Black vs. White).
- Capturing mechanics implemented for all pieces.
- Partial check detection (no checkmate logic).
- Start screen and in-game back-to-menu functionality.

### 🖼️ Graphics
- Pixel-art style chess piece sprites:
  - `pawnblack.png`, `pawnwhite.png`
  - `rookblack.png`, `rookwhite.png`
  - `knightblack.png`, `knightwhite.png`
  - `bishopblack.png`, `bishopwhite.png`
  - `queenblack.png`, `queenwhite.png`
  - `kingblack.png`, `kingwhite.png`
- Backgrounds: `bg.jpg`, `bg2.jpg`, `background.jpg`
- Menu elements: `button.png`, `backbutton.png`

### 🔊 Audio
- Includes a movement sound effect (`4.mp3`) played on each successful move.

---

## ⚙️ Mechanics

### 🧠 Piece Movement Logic
- **Pawn**: One square forward (or two on the first move), captures diagonally.
- **Rook**: Moves any number of squares horizontally or vertically.
- **Knight**: L-shaped movement (jumps over pieces).
- **Bishop**: Moves diagonally any number of squares.
- **Queen**: Combines the moves of a rook and bishop.
- **King**: Moves one square in any direction.

### 🗺️ Grid System
- 8x8 board with 80x80 pixel cells.
- Each grid square can detect piece presence and valid movements.
- Highlights the selected square for better UX.

---

## 🧱 Code Structure

- `main.cpp`: Game entry point and main loop.
- `chessmen`: Abstract base class with virtual methods for all piece types.
- `Pawn`, `Rook`, `Knight`, `Bishop`, `Queen`, `King`: Derived classes for each piece’s behavior.
- `Grid`: Manages board state and piece positions.
- `Screens`: Manages UI screens like menu and gameplay.
- `Buttons`: Detects mouse hover/click on buttons.
- Uses **SFML** for:
  - Rendering (graphics)
  - Event handling (mouse/keyboard)
  - Audio (piece movement sound)

---

## 🛠️ Requirements

- C++ compiler (g++, clang++, MSVC)
- Install [SFML](https://www.sfml-dev.org/download.php) and configure your compiler to link it properly.
- Texture and audio files (included)
---

## ▶️ How to Run

1. **Install SFML** on your system and configure it with your C++ environment.
2. Place all asset files in the following folder structure:
    ```
    ProjectFolder/
    ├── Textures/
    │   ├── pawnblack.png
    │   ├── pawnwhite.png
    │   ├── ... (other pieces and backgrounds)
    ├── Music/
    │   └── 4.mp3
    └── main.cpp
    ```
3. **Compile and run** using your preferred method:
    ```bash
    g++ main.cpp -o chess -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
    ./chess
    ```
4. Use your **mouse** to interact with the menu and drag chess pieces to valid squares.

---

## 📦 One-Click Run
Want to try **without compiling**?

- [**Download the ZIP release**](https://github.com/Musab-Farooq/Chess/blob/main/Chess.zip)  
- Extract the folder.
- Run the provided `.exe` file inside to launch Chess instantly!


---

## 🎓 Learning Highlights

This project demonstrates:
- Object-Oriented Programming (OOP)
- Inheritance & Polymorphism
- SFML-based graphics and sound
- Event-driven architecture
- Custom UI design in C++

---


## 📬 Feedback

Have suggestions or want to contribute? Feel free to open issues or pull requests!

---
