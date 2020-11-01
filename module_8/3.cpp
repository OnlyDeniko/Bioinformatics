// Copyright 2020 Kulandin Denis
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<string> a;
    string s;
    while(cin >> s) a.push_back(s);
    map<string, multiset<string>> mp;
    for(int i = 0;i < a.size();i++){
        for(int j = 0;j < a.size();j++){
            string s = a[i].substr(1, INT_MAX);
            string t = a[j].substr(0, a[j].size() - 1);
            if (s == t){
                mp[a[i]].insert(a[j]);
            }
        }
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