#include <iostream> 
#include <iomanip> 
#include <stdexcept>
#include "GameBoard.h"

using namespace std;

GameBoard::GameBoard() {
    for (int j{ 0 }; j < 3; ++j) {
        for (int k{ 0 }; k < 3; ++k) {
            board[j][k] = -1;
        }
    }

    int playerType;
    cout << "Welcome to the TicTacToe game!\n" 
        << "0 - Human Player\n" << "1 - Random AI\n";

    while (true) {
        cout << "Choose player 1 (symbol X): ";
        cin >> playerType;
        if (playerType == 0) {
            static HumanPlayer player1(0);
            p1 = &player1;
            break;
        }
        else if (playerType == 1) {
            static RandomAI player1(0);
            p1 = &player1;
            break;
        }
        cout << "Input number must be 0 or 1!\n";
    }
    
    while (true) {
        cout << "Choose Player 2 (symbol O): ";
        cin >> playerType;
        if (playerType == 0) {
            static HumanPlayer player2{1};
            p2 = &player2;
            break;
        }
        else if (playerType == 1) {
            static RandomAI player2(1);
            p2 = &player2;
            break;
        }
        cout << "Input number must be 0 or 1!\n";
    }
}

void GameBoard::printBoard() const {
    // Function for printing the current board state.
    // Please do not edit this function.
    cout << "\n   0    1    2\n\n";

    for (int r{ 0 }; r < 3; ++r) {
        cout << r;

        for (int c = 0; c < 3; ++c) {
            char symbol;
            if (board[r][c] == -1)
                symbol = ' ';
            else if (board[r][c] == 0)
                symbol = 'X';
            else if (board[r][c] == 1)
                symbol = 'O';
            else
                throw "Invalid value in game board!";

            cout << setw(3) << symbol;

            if (c != 2) {
                cout << " |";
            }
        }

        if (r != 2) {
            cout << "\n ____|____|____\n     |    |    \n";
        }
    }

    cout << "\n\n";
}

GameBoard::Status GameBoard::gameStatus() const {
    
    const int caseOFWinning[8][3] = {
        {board[0][0], board[0][1], board[0][2]},
        {board[1][0], board[1][1], board[1][2]},
        {board[2][0], board[2][1], board[2][2]},
        {board[0][0], board[1][0], board[2][0]},
        {board[0][1], board[1][1], board[2][1]},
        {board[0][2], board[1][2], board[2][2]},
        {board[0][0], board[1][1], board[2][2]},
        {board[0][2], board[1][1], board[2][0]}
    };

    for (int i{0}; i < 8; ++i) {
        if (caseOFWinning[i][0] == caseOFWinning[i][1] && caseOFWinning[i][1] == caseOFWinning[i][2] && caseOFWinning[i][0] != -1) {
            return WIN;
        }
    }

    for (int j{0}; j < 3; ++j) {
        for (int k{0}; k < 3; ++k) {
            if (board[j][k] == -1) {
                return CONTINUE;
            }
        }
    }
    
    return DRAW;
}

void GameBoard::run() {
    array<int, 2> nextMove;
    Status currStatus;    
    printBoard();

    
    while (true) {        
        nextMove = p1->nextTurn(board);
        board[nextMove[0]][nextMove[1]] = 0;
        printBoard();
        
        currStatus = gameStatus();
        if (currStatus == WIN) {
            cout << "Player 1 (symbol X) wins!" << endl;
            break;
        }
        else if (currStatus == DRAW) {
            cout << "Game is a draw!" << endl;
            break;
        }

        nextMove = p2->nextTurn(board);
        board[nextMove[0]][nextMove[1]] = 1;
        printBoard();

        currStatus = gameStatus();
        if (currStatus == WIN) {
            cout << "Player 2 (symbol O) wins!" << endl;
            break;
        }
        else if (currStatus == DRAW) {
            cout << "Game is a draw!" << endl;
            break;
        }
    }
}
