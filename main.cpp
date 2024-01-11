#include <iostream>
#include "GameBoard.h"

int main() {
	while (true) {
		//Make GameBoard class and start the game
		GameBoard g;
		g.run();
		char cont;		

		// Get request from the user
		while (true) {
			std::cout << "Want to play again? (y/n): ";
			std::cin >> cont;
			if (cont == 'y' || cont == 'n')
				break;
		}

		//Exit
		if (cont == 'n')
			break;
	}
} 
