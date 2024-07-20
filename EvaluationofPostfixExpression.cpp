class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0; i<tokens.size(); i++) {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                st.push(stoi(tokens[i]));
            } else {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                int res = 0;
                if(tokens[i] == "+") res = n2 + n1;
                else if(tokens[i] == "-") res = n2 - n1;
                else if(tokens[i] == "*") res = n2 * n1;
                else if(tokens[i] == "/") res = n2 / n1;
                cout<<res<<endl;
                st.push(res);
            }
        }
        return st.top();
    }
};