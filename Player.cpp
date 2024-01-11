#include <stdexcept>
#include "Player.h"
using namespace std;

Player::Player(int side) {
	//Validity checking
	if (side < 0 || side > 1) {
		throw invalid_argument("side must be 0 or 1!");
	}

	this->side = side;
}
