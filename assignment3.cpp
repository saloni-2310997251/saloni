#include <iostream>
using namespace std;
class TickTacToe {
private:
    char board[3][3]; 
    char currentPlayer; 

public:
   
    TickTacToe() {
        initializeBoard();
        currentPlayer = 'O';
    }

    
    void displayBoard() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

   
    void makeMove(int row, int col) {
        if (isValidMove(row, col)) {
            board[row][col] = currentPlayer;
            togglePlayer();
        } else {
            cout << "Invalid move. Please try again." << endl;
        }
    }
    
    bool checkWin() const {
        return checkRows() || checkColumns() || checkDiagonals();
    }

    
    bool isGameOver() const {
        return checkWin() || isBoardFull();
    }

    
    char getCurrentPlayer() const {
        return currentPlayer;
    }

private:
    
    void initializeBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
    }

    void togglePlayer() {
        currentPlayer = (currentPlayer == '0') ? 'X' : '0';
    }

   
    bool isValidMove(int row, int col) const {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
    }
    
    

   
    bool checkRows() const {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
                return true;
            }
        }
        return false;
    }

    
    bool checkColumns() const {
        for (int j = 0; j < 3; ++j) {
            if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
                return true;
            }
        }
        return false;
    }

    
    bool checkDiagonals() const {
        return ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
                (board[0][2] == board[1][1] && board[1][1] == board[2][0])) && (board[1][1] != ' ');
    }

    
    bool isBoardFull() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    TickTacToe game;

    while (!game.isGameOver()) {
        int row, col;
        cout << "Current board:" << endl;
        game.displayBoard();
        cout << "Player " << game.getCurrentPlayer() << ", enter your move (row and column): ";
        cin >> row >> col;
        game.makeMove(row, col);
    }

    cout << "Game Over!" << endl;

    if (game.checkWin()) {
        cout << "Player " << game.getCurrentPlayer() << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}

