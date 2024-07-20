class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        int m = nums2.size();
        mp[nums2[m-1]] = -1;
        stack<int> st;
        st.push(nums2[m-1]);

        for(int i=m-2; i>=0; i--) {
            while(!st.empty()) {
                if(st.top() > nums2[i]) {
                    mp[nums2[i]] = st.top();
                    break;
                } else {
                    mp[nums2[i]] = -1;
                    st.pop();
                }  
            }
            st.push(nums2[i]);
        }

        for(int i=0; i<nums1.size(); i++) {
            nums1[i] = mp[nums1[i]];
        }

        return nums1;
    }
};