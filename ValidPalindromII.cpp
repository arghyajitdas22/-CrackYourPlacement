class Solution {
public:
    bool validPalindrome(string s) {
        string s1 = s;
        int low=0, high=s.size()-1;
        while(low < high)
        {
            if(s[low] != s[high])
            {
                s.erase(low,1);
                s1.erase(high,1);
                break;
            }
            ++low;
            --high;
        }

        low=0; 
        high=s.size()-1;
        int cntL = 0, cntH = 0;
        while(low < high)
        {
            if(s[low] != s[high])
                ++cntL;
            if(s1[low] != s1[high])
                ++cntH;
            ++low;
            --high;
        }
        if(cntL >= 1 && cntH >=1)
            return false;
        return true;    
    }
};