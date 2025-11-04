#pragma once
#include "Game.h"
#include <iostream>

class TicTacToe : public Game // inheriting from Game header.
{
private:
	char m_board[9]; // Holds the current state of the board (X, O, or empty).
	int m_playerTurn; // keeps trasck of whose turn it is.
	bool m_gameOver; // keeps track of whether the game is over.

public:
	TicTacToe(); // constructor 
	bool IsGameOver() const override; // checks if the game is over.
	void Display() const override; // displays the current state of the board.
	void TakeTurn() override; // handles a player's input and moves.

};
#pragma once
