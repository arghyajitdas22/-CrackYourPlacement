class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int m = grid.size();
        int n = grid[0].size();

        for(int delrow = -1; delrow <= 1; delrow++) {
            for(int delcol = -1; delcol <= 1; delcol++) {
                if(abs(delrow) == abs(delcol)) continue;

                int nrow = row + delrow;
                int ncol = col + delcol;

                if((nrow >= 0 && nrow < m) && 
                (ncol >= 0 && ncol < n) && 
                (!vis[nrow][ncol]) && 
                (grid[nrow][ncol] == '1')) {
                    dfs(nrow, ncol, grid, vis);
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));
        int cnt = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid, vis);
                }
            }
        }

        return cnt;
    }
};