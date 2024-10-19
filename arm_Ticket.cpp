#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> regs(n);
    int ans = m;
    for(int i = 0; i < n; i++) {
        cin >> regs[i];
        ans += regs[i]*2;
        if(i != n-1) ans += 4;
    }
    cout << ans << endl;
    return 0;
}