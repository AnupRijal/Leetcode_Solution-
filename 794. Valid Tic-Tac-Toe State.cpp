class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xCount = 0, oCount = 0;
        // Count the number of 'X' and 'O'
        for (const string& row : board) {
            for (char cell : row) {
                if (cell == 'X') xCount++;
                else if (cell == 'O') oCount++;
            }
        }
        // Check if the number of 'X' is equal to or one more than the number of 'O'
        if (!(xCount == oCount || xCount == oCount + 1)) return false;
        // Check if 'O' wins while 'X' has more moves
        if (wins(board, 'O') && xCount != oCount) return false;
        // Check if 'X' wins while 'X' has the same or less moves than 'O'
        if (wins(board, 'X') && xCount == oCount) return false;
        return true;
    }
    
private:
    // Helper function to check if a player wins
    bool wins(const vector<string>& board, char player) {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
                return true;
        }
        // Check columns
        for (int j = 0; j < 3; j++) {
            if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
                return true;
        }
        // Check diagonals
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player))
            return true;
        return false;
    }
};