#include <iostream>
#include <vector>

using namespace std;

class TicTacToe
{
private:
    vector<vector<char>> board;
    char currentPlayer;

    void displayBoard()
    {
        cout << "Current board state:" << endl;
        for (const auto &row : board)
        {
            for (const auto &cell : row)
            {
                cout << cell << " ";
            }
            cout << endl;
        }
    }

    bool checkWin()
    {
        // Check rows and columns
        for (int i = 0; i < 3; ++i)
        {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            {
                return true;
            }
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            {
                return true;
            }
        }

        // Check diagonals
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        {
            return true;
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        {
            return true;
        }

        return false;
    }

    bool checkDraw()
    {
        for (const auto &row : board)
        {
            for (const auto &cell : row)
            {
                if (cell == '-')
                {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayer()
    {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

public:
    TicTacToe() : board(3, vector<char>(3, '-')), currentPlayer('X') {}

    void playGame()
    {
        bool gameEnded = false;

        while (!gameEnded)
        {
            displayBoard();
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            // Check if the move is valid
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-')
            {
                board[row][col] = currentPlayer;
                if (checkWin())
                {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    gameEnded = true;
                }
                else if (checkDraw())
                {
                    displayBoard();
                    cout << "The game is a draw!" << endl;
                    gameEnded = true;
                }
                else
                {
                    switchPlayer();
                }
            }
            else
            {
                cout << "Invalid move. Try again." << endl;
            }
        }
    }
};

int main()
{
    char playAgain;
    do
    {
        TicTacToe game;
        game.playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
