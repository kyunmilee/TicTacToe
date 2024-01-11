#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include <array>
#include "Player.h"

class HumanPlayer : public Player{
public:
	HumanPlayer(int);
	virtual std::array<int, 2> nextTurn(std::array<std::array<int, 3>, 3>) const override;
private:
	int side;
};
#endif
