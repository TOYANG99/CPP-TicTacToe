#include "TicTacToe.h"

using namespace std;

// Our array of all 8 possible win combos (rows, columns, diagonals)
int winningMoves[8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // winning rows
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // winning columns
    {0, 4, 8}, {2, 4, 6}             // winning diagonals
};

// Constructor to initialize the board
TicTacToe::TicTacToe()
{
    for (int i = 0; i < 9; ++i)
        m_board[i] = ' ';
    m_playerTurn = 0; // Player 1 starts
    m_gameOver = false;
}

// Display function - displays the current state of the board, which should be all cleareed at the start.
void TicTacToe::Display() const
{

    cout << "\n";
    cout << " " << m_board[0] << " | " << m_board[1] << " | " << m_board[2] << "\n";
    cout << "---+---+---\n";
    cout << " " << m_board[3] << " | " << m_board[4] << " | " << m_board[5] << "\n";
    cout << "---+---+---\n";
    cout << " " << m_board[6] << " | " << m_board[7] << " | " << m_board[8] << "\n\n";

    cout << "Player 1 = X | Player 2 = O\n";

    cout << "Player " << (m_playerTurn + 1) << "'s turn ("
        << (m_playerTurn == 0 ? 'X' : 'O') << ")\n";
}

// Take Turn function - handles a player's input and moves.

void TicTacToe::TakeTurn()
{
    int move; // players move input (1-9)
    bool validMove = false;

    do
    {
        cout << "Enter position (1-9): ";
        cin >> move;

        // Check if the move is between 1 and 9.
        if (move < 1 || move > 9)
        {
            cout << "Invalid position. Try again.\n";
        }
        else if (m_board[move - 1] != ' ')
        {
            cout << "That spot is already taken. Try again.\n"; // checks to see if the spot is taken.
        }
        else
        {
            m_board[move - 1] = (m_playerTurn == 0 ? 'X' : 'O'); // place X or O on the board based on player turn.
            validMove = true;
        }

    } while (!validMove);

    // Check if game is over before switching turns.
    if (!IsGameOver())
    {
        m_playerTurn = 1 - m_playerTurn; // switches between player 1 and 2.
    }
}



// Check if Game is Over
bool TicTacToe::IsGameOver() const
{
    // All 8 possible win combos (rows, columns, diagonals)
    int winningMoves[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // columns
        {0, 4, 8}, {2, 4, 6}             // diagonals
    };

    // Loop through each possible winning combination
    for (int i = 0; i < 8; i++)
    {
        // Get the three board positions that make up a win line
        int a = winningMoves[i][0];
        int b = winningMoves[i][1];
        int c = winningMoves[i][2];

        // If the three spots are not blank AND all three match,that means a player has won.
        if (m_board[a] != ' ' && m_board[a] == m_board[b] && m_board[b] == m_board[c])
        {
            cout << "\nPlayer " << (m_board[a] == 'X' ? 1 : 2) << " wins!\n";
            return true; // End the game
        }
    }

    // Check for a tie — if every spot is filled and no one has won
    for (int i = 0; i < 9; i++)
    {
        if (m_board[i] == ' ')
        {
            // If we find at least one empty space, the game keeps going
            return false;
        }
    }

    // If the loop finishes and no spaces are empty, it's a tie
    cout << "\nIt's a tie!\n";
    return true; // Game is over
}
