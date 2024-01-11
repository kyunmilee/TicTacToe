#ifndef PLAYER_H
#define PLAYER_H
#include <array>

class Player {
public:
	Player(int);
	virtual std::array<int, 2> nextTurn(std::array<std::array<int, 3>, 3>) const = 0;
private:
	int side;    // 0 for Player X and 1 for Player O
};
#endif
