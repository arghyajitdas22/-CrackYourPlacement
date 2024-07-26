class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n+1, 0);

        for(int i=0; i<n; i++) {
            ++arr[nums[i]];
        }

        vector<int> ans;
        for(int i=0; i<n+1; i++) {
            if( arr[i] == 2) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};