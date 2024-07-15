class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int>:: iterator it = nums.begin();
        for(int i=0;i<n;++i)
        {
            if(*it == 0)
            {
                nums.erase(it);
                nums.push_back(0);
            }
            else
                ++it;
        }
        
    }
};