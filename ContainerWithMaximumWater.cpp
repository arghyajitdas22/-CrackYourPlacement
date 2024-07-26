class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = INT_MIN;
        int  left = 0, right = height.size() - 1;

        while(left < right) {
            int ch = min(height[left], height[right]);
            int area = ch * (right - left);
            maxi = max(maxi, area);

            if(height[left] <= height[right]) left++;
            else right--;
        }

        return maxi;
    }
};