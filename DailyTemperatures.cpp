class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> ans(temperatures.size());
        
        for(int i=temperatures.size()-1; i>=0; i--) {
            while(!st.empty()) {
                pair<int, int> p = st.top();
                if(p.first > temperatures[i]) {
                    ans[i] = p.second - i;
                    break;
                } else {
                    st.pop();
                }
            }
            if(st.empty()) ans[i] = 0;
            st.push({temperatures[i], i});
        }

        return ans;
    }
};