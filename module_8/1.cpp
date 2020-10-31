#include <bits/stdc++.h>
using namespace std;
set<string> ans;
void calc(int pos, string & tmp, vector<int> &used, const string & s, int k){
    if (pos == k){
        ans.insert(tmp);
        return;
    }
    for(int i = 0;i < s.size();i++){
        if (used[i]) continue;
        used[i] = 1;
        tmp[pos] = s[i];
        calc(pos + 1, tmp, used, s, k);
        used[i] = 0;
    }
}

int main() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    for(int i = 0;i < s.size() - k + 1;i++){
        string t = s.substr(i, k);
        ans.insert(t);
    }
    for(auto i : ans) cout << i << '\n';
    return 0;
}