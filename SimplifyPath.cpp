class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        int n = path.size(), end = n - 1;
        int skip = 0;

        for(int i=n-1; i>=0; i--) {
            if(path[i] == '/') {
                if(i == n-1 || path[i+1] == '/') {
                    end = i - 1;
                    continue;
                }
                string sub = path.substr(i+1, end-i);
                end = i-1;
                if(sub == "..") {
                    skip++;
                } else if(sub == ".") {
                    continue;
                } else {
                    if(skip == 0) {
                        ans = "/" + sub + ans;
                    } else {
                        skip--;
                    }
                }  
            }
        }

        if(ans == "") ans += "/";
        return ans;
    }
};