class Solution {
public:
    int calculate(string s) {
        string str = "";
        for(auto it: s) {
            if(it != ' ') str += it;
        }
        str += '/';
        deque<string> dq;
        int start = 0;
        string currOp = " ";

        for(int i=0; i<str.size(); i++) {
            char it = str[i];
            if(it == '+' || it == '-' || it == '*' || it == '/') {
                string sub = str.substr(start, i - start);
                dq.push_back(sub);
                if(currOp == "*" || currOp == "/") {
                    int n2 = stoi(dq.back());
                    dq.pop_back();
                    dq.pop_back();
                    int n1 = stoi(dq.back());
                    dq.pop_back();
                    if(currOp == "*") dq.push_back(to_string((int)(n1 * n2)));
                    else dq.push_back(to_string((int)(n1 / n2)));
                }
                currOp.assign(1, it);
                start = i+1;
                dq.push_back(currOp);
            }
        }
        dq.pop_back();

        while(dq.size() != 1) {
            int n1 = stoi(dq.front());
            dq.pop_front();
            string op = dq.front();
            dq.pop_front();
            int n2 = stoi(dq.front());
            dq.pop_front();
            if(op == "+") dq.push_front(to_string(n1+n2));
            else dq.push_front(to_string(n1-n2));
        }

        return stoi(dq.front());
    }
};