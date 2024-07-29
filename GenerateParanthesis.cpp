class Solution {
public:
    void solve(int n, vector<string>& ans, string str, int os, int cs) {
        int len = str.size();
        if(len == 2*n) {
            ans.push_back(str);
            return;
        }

        if(os < n) solve(n, ans, str+'(', os+1, cs);
        if(cs < os) solve(n, ans, str+')', os, cs+1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        solve(n, ans, str, 0, 0);
        return ans;
    }
};