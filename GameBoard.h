#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <array>
#include "Player.h"
#include "HumanPlayer.h"
#include "RandomAI.h"

class GameBoard {
private:
	Player* p1;    // Player X
	Player* p2;    // Player O
	enum Status { WIN, DRAW, CONTINUE };
	std::array<std::array<int, 3>, 3> board;    // 3X3 game board of TicTacToe
public:
	GameBoard();	
	void printBoard() const;
	Status gameStatus() const;
	void run();
};

#endif
