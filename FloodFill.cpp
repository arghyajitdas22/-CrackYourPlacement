class Solution {
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int inic, vector<vector<int>>& ans) {
        ans[sr][sc] = color;
        int n = image.size(); 
        int m = image[0].size();

        for(int delrow = -1; delrow <= 1; delrow++) {
            for(int delcol = -1; delcol <= 1; delcol++) {
                if(abs(delrow) == abs(delcol)) continue;

                int nrow = sr + delrow;
                int ncol = sc + delcol;

                if((nrow >= 0 && nrow < n) &&
                   (ncol >= 0 && ncol < m) &&
                   (image[nrow][ncol] == inic) &&
                   (ans[nrow][ncol] != color)) {
                       dfs(image, nrow, ncol, color, inic, ans);
                   }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int inic = image[sr][sc];
        int n = image.size(); 
        int m = image[0].size();

        dfs(image, sr, sc, color, inic, ans);

        return ans;
    }
};