

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        unordered_map<int, int> mp;
        for(auto it: arr) {
            mp[it]++;
        }
        
        for(int i=0; i<n; i++) {
            int req = x + arr[i];
            if(mp.count(req) && req==arr[i] && mp[req]>1) return 1;
            else if(mp.count(req) && req!=arr[i]) return 1;
        }
        
        return -1;
    }
};

