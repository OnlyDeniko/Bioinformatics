// Copyright 2020 Kulandin Denis
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int x;
    multiset<int> in;
    while(cin >> x) in.insert(x);
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
    
    int n = s.size();
    multiset<int> su;
    auto calc = [&](string s){
        int ans = 0;
        for(char i : s) ans += mp[i];
        return ans;
    };
    su.insert(0);
    su.insert(calc(s));
    s += s;
    for(int i = 0;i < n;i++){
        string t;
        for(int j = i;j < i + n - 1;j++){
            t += s[j];
            
            su.insert(calc(t));
        }
    }
    multiset<int> ans;
    set_intersection(su.begin(), su.end(), in.begin(), in.end(), inserter(ans, ans.begin()));
    cout << ans.size() << '\n';
    return 0;
}