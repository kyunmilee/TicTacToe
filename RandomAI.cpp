#include <stdlib.h>
#include "RandomAI.h"
using namespace std;

RandomAI::RandomAI(int side)
	:Player(side) {}

array<int, 2> RandomAI::nextTurn(array<array<int, 3>, 3> board) const {
	
	int row, col;

	do {
		row = rand() % 3;
		col = rand() % 3;
	} while (board[row][col] != -1);

	array <int, 2> next{row, col};
	return next;
}