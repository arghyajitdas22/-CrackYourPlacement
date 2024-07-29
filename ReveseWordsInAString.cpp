#include <boost/algorithm/string.hpp>
class Solution {
public:
    string reverseWords(string s) {
        trim(s);
        stack<string> st;
        int start = 0;

        for(int i=0; i<s.size(); i++) {
                if(s[i] == ' ') {
                    string word = s.substr(start, i-start);
                    trim(word);
                    st.push(word);
                    i++;
                    while(s[i] == ' ') {
                        i++;
                    }
                    start = i;
                }
        }

        string ans = "";
        while(!st.empty()) {
            string word = st.top();
            ans = word + " ";
            st.pop();
        }
        trim(ans);

        return ans;
    }
};