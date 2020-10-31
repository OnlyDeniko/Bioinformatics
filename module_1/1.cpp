#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, t;
    cin >> t >> s;
    int ans = 0;
    for(int i = 0;i < s.size() - t.size() + 1;i++){
        string gg = s.substr(i, t.size());
        if (gg == t) ans++;
    }
    cout << ans << '\n';
    return 0;
}