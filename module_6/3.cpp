// Copyright 2020 Kulandin Denis
#include <bits/stdc++.h>

using namespace std;
pair<int, string> dp[2050][2050];
#define X first
#define Y second

pair<int, string> calc(string s, string t, int pos1, int pos2){
    if (pos1 == 0 || pos2 == 0){
        return {0, ""};
    }
    if (dp[pos1][pos2].X != -1) return dp[pos1][pos2];
    if (s[pos1 - 1] == t[pos2 - 1]){
        auto ans = calc(s, t, pos1 - 1, pos2 - 1);
        ans.X++;
        ans.Y += s[pos1 - 1];
        return dp[pos1][pos2] = ans;
    }
    auto q = calc(s, t, pos1 - 1, pos2);
    auto w = calc(s, t, pos1, pos2 - 1);
    q = max(q, w);
    return dp[pos1][pos2] = q;
}

int main() {
    for(int i = 0;i < 2050;i++) for(int j = 0;j < 2050;j++) dp[i][j] = {-1, ""};
    string s, t;
    cin >> s >> t;
    cout << calc(s, t , s.size(), t.size()).Y << '\n';
    return 0;
}