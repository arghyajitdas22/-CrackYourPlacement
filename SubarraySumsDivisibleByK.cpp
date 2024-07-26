class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for(auto it: nums) {
            sum += it;
            int rem = sum % k;
            if(rem < 0) rem += k;
            if(mp.count(rem)) ans += mp[rem];
            mp[rem]++;
        }

        return ans;
    }
};