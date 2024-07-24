class Solution {
public:
    int solve(int num, vector<int>& dp) {
        if(num == 0) return 0;
        if(dp[num] != -1) return dp[num];

        return dp[num] = num%2 + solve(num/2, dp);
    }

    vector<int> countBits(int n) {
       vector<int> dp(n+1, -1);

       for(int i=0; i<=n; i++) {
            if(dp[i] == -1) {
                dp[i] = solve(i, dp);
            }
       }

       return dp; 
    }
};