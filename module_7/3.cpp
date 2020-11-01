// Copyright 2020 Kulandin Denis
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int> > dp(n + 1, vector<int> (m + 1, 0));
    for(int i = 0;i < n + 1;i++) dp[i][0] = i;
    for(int i = 0;i < m + 1;i++) dp[0][i] = i;
    for(int i = 1;i < n + 1;i++){
        for(int j = 1;j < m + 1;j++){
            dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (s[i - 1] != t[j - 1])});
        }
    }
    cout << dp[n][m];
    return 0;
}