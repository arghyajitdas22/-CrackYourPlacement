class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> ans(m, vector<int>(n));

        for(int row=0; row<m; row++) {
            for(int col=0; col<n; col++) {
                int cnt = 0;
                for(int delrow = -1; delrow <= 1; delrow++) {
                    for(int delcol = -1; delcol <= 1; delcol++) {
                        if(delrow == 0 && delcol == 0) continue;
                        int nrow = row + delrow; 
                        int ncol = col + delcol;
                        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol]) cnt++;
                    }
                }
                if(cnt == 3) ans[row][col] = 1;
                else if(cnt == 2) ans[row][col] = board[row][col];
                else ans[row][col] = 0;
            }
        }

        board = ans;
    }
};