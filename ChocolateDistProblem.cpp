class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(), a.end());
    long long start = 0;
    long long end = m-1;
    long long diff = INT_MAX;
    
    while(end < n) {
       diff = min(diff, a[end++] - a[start++]);
    }
    
    return diff;
    }   
};