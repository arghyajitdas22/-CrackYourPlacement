class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lSum = 0, rSum = 0, maxSum = INT_MIN, right = cardPoints.size() - 1;
        for(int i=0; i<k; i++) lSum += cardPoints[i];
        maxSum = lSum;
        for(int i=k-1; i>=0; i--) {
            lSum -= cardPoints[i];
            rSum += cardPoints[right];
            right--;
            maxSum = max(maxSum, lSum + rSum);
        }

        return maxSum;
    }
};