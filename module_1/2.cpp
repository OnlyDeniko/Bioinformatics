// Copyright 2020 Kulandin Denis
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int k;
    cin >>s >> k;
    map<string, int> mp;
    for(int i = 0;i < s.size() - k + 1;i++){
        string t = s.substr(i, k);
        mp[t]++;
    }
    int ma = -1;
    for(auto i : mp){
        ma = max(ma, i.second);
    }
    for(auto i : mp){
        if (i.second == ma) cout << i.first << ' ';
    }
    return 0;
}