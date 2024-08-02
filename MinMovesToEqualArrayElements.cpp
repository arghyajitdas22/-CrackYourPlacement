class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1, moves = 0;

        while(start < end) {
            moves += nums[end--] - nums[start++];
        }

        return moves;
    }
};