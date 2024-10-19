class Solution {
public:
    
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }

        for (int left = n - 1; left >= 0; left--) {
            for (int right = left; right < n; right++) {
                if (left == right)
                    continue;

                int ans = INT_MAX;
                for (int k = left; k < right; k++) {
                    ans = min(ans, maxi[{left, k}] * maxi[{k + 1, right}] +
                                       dp[left][k] + dp[k + 1][right]);
                }
                dp[left][right] = ans;
            }
        }
        return dp[0][n - 1];
    }
};