// Copyright 2020 Kulandin Denis
#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    map<string, multiset<string>> mp;
    for(int i = 0;i < s.size() - k + 1;i++){
        string t = s.substr(i, k);
        string q = t, w = t;
        q.pop_back();
        reverse(w.begin(), w.end());
        w.pop_back();
        reverse(w.begin(), w.end());
        mp[q].insert(w);
    }
    auto calc = [](multiset<string> s){
        string ans;
        for(auto i : s) ans += i + ",";
        ans.pop_back();
        return ans;
    };
    for(auto i : mp){
        cout << i.first << " -> " << calc(i.second) << '\n';
    }
    return 0;
}