#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> down(n, vector<int>(m + 1));
    for(auto &i : down) for(auto &j : i) cin >> j;
    char x;
    cin >> x;
    vector<vector<int>> right(n + 1, vector<int>(m));
    for(auto &i : right) for(auto &j : i) cin >> j;    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1;i <= m;i++){
    	dp[0][i] = dp[0][i - 1] + right[0][i - 1];
    }
    for(int i = 1;i <= n;i++) dp[i][0] = dp[i - 1][0] + down[i - 1][0];
    for(int i = 1;i <= n;i++){
    	for(int j = 1;j <= m;j++){
    		int q = dp[i - 1][j] + down[i - 1][j];
    		int w = dp[i][j - 1] + right[i][j - 1];
    		dp[i][j] = max(q, w);
    	}
    }
    cout << dp[n][m];
    return 0;
}