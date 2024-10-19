class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        while(!st.empty()) {
            pair<int, int> p = st.top();
            if(p.first <= price) {
                cnt += p.second;
                st.pop();
            } else break;
        }
        st.push({price, cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */