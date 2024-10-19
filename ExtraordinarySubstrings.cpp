int countSubstrings(string s) {
    unordered_map<char, int> mp;
    for(char ch = 'a'; ch <= 'z'; ch++) {
        if(ch == 'a' || ch == 'b') mp[ch] = 1;
        else if(ch == 'c' || ch == 'd' || ch == 'e') mp[ch] = 2;
        else if(ch == 'f' || ch == 'g' || ch == 'h') mp[ch] = 3;
        else if(ch == 'j' || ch == 'k' || ch == 'i') mp[ch] = 4;
        else if(ch == 'l' || ch == 'm' || ch == 'n') mp[ch] = 5;
        else if(ch == 'o' || ch == 'p' || ch == 'q') mp[ch] = 6;
        else if(ch == 'r' || ch == 's' || ch == 't') mp[ch] = 7;
        else if(ch == 'u' || ch == 'v' || ch == 'w') mp[ch] = 8;
        else if(ch == 'x' || ch == 'y' || ch == 'z') mp[ch] = 9;
        }

    int n = s.size();
    vector<int> prefix(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += mp[s[i]];
        prefix[i] = sum;
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            sum = prefix[j] - (i > 0 ? prefix[i - 1] : 0);
            if(sum % (j - i + 1) == 0) count++;
        }
    }

    return count;
}