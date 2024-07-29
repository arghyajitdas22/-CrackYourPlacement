class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int a[n][n];
        int total=n*n;
        int count=0;
        int col =n-1,row1=0;
        while(count < total)
        {
            int row2=0;
            for(int i=0;i<n;++i)
            {
                a[row2][col] = matrix[row1][i];
                ++row2;
                ++count;
            }
            ++row1;
            --col;
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
                matrix[i][j]=a[i][j];
        }
    }
};