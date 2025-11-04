// Assignment 6 - TicTacToe
// Tommy Yang

// This file is complete, and should not be modified!

#include <iostream>

#include "TicTacToe.h"

bool PlayAgain();

int main()
{
	while (true)
	{
		Game* pGame = new TicTacToe();
		if (!pGame) return 0;

		// play game
		pGame->Display();

		while (!pGame->IsGameOver())
		{
			pGame->TakeTurn();
			pGame->Display();
		}

		delete pGame;

		if (!PlayAgain()) return 0;
	}
}

bool PlayAgain()
{
	while (true)
	{
		char input = ' ';
		std::cout << "Play again? (y/n): ";
		std::cin >> input;

		if (std::tolower(input) == 'y') return true;
		else if (std::tolower(input) == 'n') return false;
	}
}