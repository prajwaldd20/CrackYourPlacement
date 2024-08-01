class Solution {
private:
    int n, m;

public:
    int delrow[4] = {0, 0, -1, 1};
    int delcol[4] = {-1, 1, 0, 0};
    bool solve(vector<vector<char>>& board, string word, int row, int col,
               int index) {
        if (row < 0 || row >= n || col < 0 || col >= m ||
            board[row][col] == '$' || word[index] != board[row][col])
            return false;

        if (index == word.length()-1)
            return true;
        char ch = board[row][col];
        // to mark visited
        board[row][col] = '$';
        for (int i = 0; i < 4; i++) {
            if (solve(board, word, row + delrow[i], col + delcol[i], index + 1))
                return true;
        }
        board[row][col] = ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (solve(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};
