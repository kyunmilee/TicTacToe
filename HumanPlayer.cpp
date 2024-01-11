#include <iostream>
#include "HumanPlayer.h"
using namespace std;

HumanPlayer::HumanPlayer(int side)
	:Player(side) {}

array<int, 2> HumanPlayer::nextTurn(array<array<int, 3>, 3> board) const {

	int col, row;
	
	array<int, 2> next;

	while (true) {
		std::cout << "Enter the row number of your next move: ";
		std::cin >> row;

		std::cout << "Enter the column of your next move: ";
		std::cin >> col;

		if (row < 0 || row > 2 || col < 0 || col > 2) {
			cout << "Please input value between 0 and 2!" << endl;
		}
		else if (board[row][col] != -1) {
			cout << "That point is already occupied!" << endl;
		}
		else {
			next = {row, col};
			break;
		}
	}
	return next;
}