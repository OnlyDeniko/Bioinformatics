// Copyright 2020 Kulandin Denis
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string ans = s;
    while(cin >> s){
        ans += s.back();
    }
    cout << ans << '\n';
    return 0;
}