#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    vector<int> a = {57, 71, 87,97,99,101,103,113,114,115,128,129,131,137,147,156,163,186};
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1;i < n + 1;i++){
        for(int j : a){
            if (i >= j) dp[i] += dp[i - j];
        }
    }
    cout << dp[n];
    return 0;
}