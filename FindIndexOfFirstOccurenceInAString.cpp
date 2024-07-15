class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();

        for(int i=0; i<=n-m; i++) {
            string str = haystack.substr(i, m);
            if(str == needle) return i;
        }

        return -1;
    }
};