class Solution {
public:
    string convertToTitle(int columnNumber) {
        vector<string> mp = {"Z"};
        for (char c = 'A'; c <= 'Z'; ++c) {
            mp.push_back(string(1, c));
        }
        string ans = "";
        int cn = columnNumber;
        
        while(cn> 26) {
            int r = cn % 26;
            if(r == 0) {
                cn = cn / 26 - 1;
            } else {
                cn = cn / 26;
            }
            ans = mp[r] + ans;
        }

        ans = mp[cn] + ans;
        return ans;
    }
};