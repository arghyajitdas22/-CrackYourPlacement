class Solution {
public:
    void sortColors(vector<int>& arr) {
        int start  = 0;
        int mid = 0;
        int end = arr.size() - 1;

        while(mid <= end)
        {
            if(arr[mid] == 0)
            {
                swap(arr[start++], arr[mid++]);
            }
            else if(arr[mid] == 1)
            {
                ++mid;
            }
            else
            {
                swap(arr[end--], arr[mid]);
            }
        }
    }
};