class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, int delrow[], int delcol[]) {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;

        for(int i=0; i<4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>0 && nrow<n && ncol>0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O') {
                dfs(nrow, ncol, vis, board, delrow, delcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        //first row and last row
        for(int j=0; j<m; j++) {
            //first row
            if(board[0][j]=='O' && !vis[0][j]) {
                dfs(0, j, vis, board, delrow, delcol);
            }
            //last row
            if(board[n-1][j]=='O' && !vis[n-1][j]) {
                dfs(n-1, j, vis, board, delrow, delcol);
            }
        }

        //first col and last col
        for(int i=0; i<n; i++) {
            //first col
            if(board[i][0]=='O' && !vis[i][0]) {
                dfs(i, 0, vis, board, delrow, delcol);
            }
            //last col
            if(board[i][m-1]=='O' && !vis[i][m-1]) {
                dfs(i, m-1, vis, board, delrow, delcol);
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};