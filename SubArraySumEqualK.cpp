class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0;

        for(int i=0; i<nums.size(); i++) {
            prefixSum += nums[i];
            int remove = prefixSum - k;
            cnt += mp[remove];
            mp[prefixSum]++;
        }

        return cnt;
    }
};