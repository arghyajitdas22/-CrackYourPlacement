class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        stack<int> unique;
        unique.push(nums[0]);

        for(int i=1; i<nums.size(); i++) {
            if( nums[i] != unique.top() ) {
                unique.push(nums[i]);
            }
        }

        int k = unique.size();
        for(int i=k-1; i>=0; i--) {
            nums[i] = unique.top();
            unique.pop();
        }

        return k;
    }
};