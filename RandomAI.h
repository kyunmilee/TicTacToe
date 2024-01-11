#ifndef RANDOMAI_H
#define RANDOMAI_H
#include <array>
#include "Player.h"

class RandomAI : public Player {
public:
	RandomAI(int);
	virtual std::array<int, 2> nextTurn(std::array<std::array<int, 3>, 3>) const override;
private:
	int side;
};
#endif