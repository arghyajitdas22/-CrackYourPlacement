class Solution {
public:
    bool solve(int row, int col, vector<vector<char>>& board, string word,
               int index) {
        int m = board.size(), n = board[0].size();
        if (index >= word.size())
            return true;
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] == '.' || word[index] != board[row][col])
            return false;
        
        board[row][col] = '.';
        if(solve(row - 1, col, board, word, index + 1) ||
               solve(row + 1, col, board, word, index + 1) ||
               solve(row, col - 1, board, word, index + 1) ||
               solve(row, col + 1, board, word, index + 1)) return true;
        board[row][col] = word[index];
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(solve(i, j, board, word, 0)) return true;
            }
        }
        
        return false;
    }
};