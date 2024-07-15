class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), start = 0;
        for(int i=1; i<n; i++) {
            if(nums[i] != nums[i-1]) {
                int cnt = i - start;
                if(cnt > n/2) return nums[i-1];
                start = i;
            }
        }
        if(n - start > n/2) return nums[start];
        return nums[0];
    }
};