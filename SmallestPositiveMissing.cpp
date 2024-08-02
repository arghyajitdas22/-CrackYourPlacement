//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        int sp = INT_MAX, hp = 0;
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++) {
            if(arr[i] > 0) {
                sp = min(sp, arr[i]);
                hp = max(hp, arr[i]);
                mp[arr[i]] = 1;
            }
        }
        
        if(sp > 1) return 1;
        else if(sp==1 && mp.size() != (hp-sp+1)) {
           for(int i=sp; i<=hp; i++) {
               if(!mp.count(i)) return i;
           } 
        } else return hp+1;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends