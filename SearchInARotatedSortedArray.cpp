class Solution {
public:
    int find(vector<int>& nums, int low, int high, int target)
    {
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                high = mid-1;
            else
                low = mid+1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if(nums[0] <= nums[nums.size()-1])
        {
            return find(nums, 0, nums.size()-1, target);
        }

        int low = 0, high = nums.size()-1;
        while(low < high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] >= nums[0])
                low = mid+1;
            else
                high = mid;
        }

        if(target >= nums[0])
            return find(nums, 0, high-1, target);
        else
            return find(nums, high, nums.size()-1, target);
    }
};