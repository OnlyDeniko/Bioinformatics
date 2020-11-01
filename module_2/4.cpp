// Copyright 2020 Kulandin Denis
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<string> a;
    a.push_back(s);
    s += s;
    
    a.push_back("");
    for(int i = 0;i < n;i++){
        string t;
        for(int j = i;j < i + n - 1;j++){
            t += s[j];
            a.push_back(t);
        }
    }
    map<char, int> mp;
    mp['G'] = 57;
    mp['A'] = 71;
    mp['S'] = 87;
    mp['P'] = 97;
    mp['V'] = 99;
    mp['T'] = 101;
    mp['C'] = 103;
    mp['I'] = 113;
    mp['L'] = 113;
    mp['N'] = 114;
    mp['D'] = 115;
    mp['K'] = 128;
    mp['Q'] = 128;
    mp['E'] = 129;
    mp['M'] = 131;
    mp['H'] = 137;
    mp['F'] = 147;
    mp['R'] = 156;
    mp['Y'] = 163;
    mp['W'] = 186;
    vector<int> ans;
    for(auto i : a){
        int gg = 0;
        for(auto j : i) gg += mp[j];
        ans.push_back(gg);
    }
    sort(ans.begin(), ans.end());
    for(auto i : ans) cout << i << ' ';
    return 0;
}