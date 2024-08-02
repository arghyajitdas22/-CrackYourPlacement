//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  private:
    bool isPossible(long long mid, int n, int arr[], int m) {
        long long pages = 0;
        int students = 1;
        
        for(int i=0; i<n; i++) {
            if(arr[i] > mid) return false;
            if(pages+arr[i] <= mid) pages += arr[i];
            else {
                students++;
                if(students > m) return false;
                pages = arr[i];
            }
        }
        
        return true;
    }
    
  public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // code here
        if(m > n) return -1;
        long long sum = 0;
        for(int i=0; i<n; i++) sum += arr[i];
        
        long long low = 0, high = sum, ans = INT_MAX;
        while(low <= high) {
            long long mid = low + (high - low)/2;
            if(isPossible(mid, n, arr, m)) {
                ans = min(ans, mid);
                high = mid -1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends