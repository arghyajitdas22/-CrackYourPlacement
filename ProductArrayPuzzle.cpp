

class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here  
        vector<long long int> ans(n);
        int cnt = 0;
        
        long long int p = 1;
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                cnt++;
            } else {
                p *= nums[i];
            }
        }
        
        if(cnt > 1) {
            for(int i=0; i<n; i++) ans[i] = 0;
            return ans;
        }
        
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) ans[i] = 0;
            else ans[i] = p/nums[i];
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends