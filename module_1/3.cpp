#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    map<char, char> mp;
    mp['A'] = 'T';
    mp['T'] = 'A';
    mp['C'] = 'G';
    mp['G'] = 'C';
    for(char &i : s) i = mp[i];
    cout << s << '\n';
    return 0;
}