class Solution {
public:
    string addition(string &carry, char a, char b) {
        if(carry == "0") {
            if((a=='0' && b=='1') || (a=='1' && b=='0')) return "1";
            else if(a=='1' && b=='1') {
                carry = "1";
                return "0";
            } else return "0";
        } else {
            if((a=='0' && b=='1') || (a=='1' && b=='0')) {
                carry = "1";
                return "0";
            }
            else if(a=='1' && b=='1') {
                carry = "1";
                return "1";
            } else {
                carry = "0";
                return "1";
            }
        }
    }

    string addBinary(string a, string b) {
        int len1 = a.size(), len2 = b.size();
        string na = a, nb = b;

        if(len1 > len2) {
            int diff = len1 - len2;
            string newstr = ""; 
            for(int i=1; i<=diff; i++) {
                newstr +="0";
            }
            nb = newstr + b;
        } else {
            int diff = len2 - len1;
            string newstr = ""; 
            for(int i=1; i<=diff; i++) {
                newstr +="0";
            }
            na = newstr + a;
        }

        int len = na.size();
        string carry = "0", ans = "";
        for(int i=len-1; i>=0; i--) {
            string res = addition(carry, na[i], nb[i]);
            ans = res + ans;
        }

        if(carry == "1") ans = "1" + ans;
        return ans;
    }
};