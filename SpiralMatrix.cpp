class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int total = rows*cols;
        int count=0;
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = rows-1;
        int endingCol = cols-1;
        
        vector<int> spiral;
        while(count < total)
        {
            //printing starting row
            for(int i=startingCol;count<total && i<=endingCol;++i)
            {
                spiral.push_back(matrix[startingRow][i]);
                ++count;
            }
            ++startingRow;
            
            //printing ending col
            for(int i=startingRow;count<total && i<=endingRow;++i)
            {
                spiral.push_back(matrix[i][endingCol]);
                ++count;
            }
            --endingCol;
                
            //printing ending row
            for(int i=endingCol;count<total && i>=startingCol;--i)
            {
                spiral.push_back(matrix[endingRow][i]);
                ++count;
            }
            --endingRow;
            
            //printing starting col
            for(int i=endingRow;count<total && i>=startingRow;--i)
            {
                spiral.push_back(matrix[i][startingCol]);
                ++count;
            }
            ++startingCol; 
        
        }
        return spiral;
    }
};