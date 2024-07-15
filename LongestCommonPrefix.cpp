class Solution {
public:
    int findMinLength(vector<string>& strs) {
        int ans = INT_MAX;

        for(int i=0; i<strs.size(); i++) {
            string s = strs[i];
            if(s.length() < ans) ans = s.length();
        }

        return ans;
    }

    string longestCommonPrefix(vector<string>& strs) {
        int minLen = findMinLength(strs);

        string ans = "";
        int i = 0;

        while(i < minLen) {
            char ch = strs[0][i];

            for(int j=1; j<strs.size(); j++) {
                string s = strs[j];
                if(s[i] != ch) return ans;
            }

            ans = ans + ch;
            i++;
        }

        return ans;
    }
};