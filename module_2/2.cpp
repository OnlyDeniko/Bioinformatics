#include <bits/stdc++.h>
using namespace std;
bool check1(string s, string t){
    map<string, string> mp;
    mp["AAA"] = "K";
    mp["AAC"] = "N";
    mp["AAG"] = "K";
    mp["AAU"] = "N";
    mp["ACA"] = "T";
    mp["ACC"] = "T";
    mp["ACG"] = "T";
    mp["ACU"] = "T";
    mp["AGA"] = "R";
    mp["AGC"] = "S";
    mp["AGG"] = "R";
    mp["AGU"] = "S";
    mp["AUA"] = "I";
    mp["AUC"] = "I";
    mp["AUG"] = "M";
    mp["AUU"] = "I";
    mp["CAA"] = "Q";
    mp["CAC"] = "H";
    mp["CAG"] = "Q";
    mp["CAU"] = "H";
    mp["CCA"] = "P";
    mp["CCC"] = "P";
    mp["CCG"] = "P";
    mp["CCU"] = "P";
    mp["CGA"] = "R";
    mp["CGC"] = "R";
    mp["CGG"] = "R";
    mp["CGU"] = "R";
    mp["CUA"] = "L";
    mp["CUC"] = "L";
    mp["CUG"] = "L";
    mp["CUU"] = "L";
    mp["GAA"] = "E";
    mp["GAC"] = "D";
    mp["GAG"] = "E";
    mp["GAU"] = "D";
    mp["GCA"] = "A";
    mp["GCC"] = "A";
    mp["GCG"] = "A";
    mp["GCU"] = "A";
    mp["GGA"] = "G";
    mp["GGC"] = "G";
    mp["GGG"] = "G";
    mp["GGU"] = "G";
    mp["GUA"] = "V";
    mp["GUC"] = "V";
    mp["GUG"] = "V";
    mp["GUU"] = "V";
    mp["UAA"] = "STOP";
    mp["UAC"] = "Y";
    mp["UAG"] = "STOP";
    mp["UAU"] = "Y";
    mp["UCA"] = "S";
    mp["UCC"] = "S";
    mp["UCG"] = "S";
    mp["UCU"] = "S";
    mp["UGA"] = "STOP";
    mp["UGC"] = "C";
    mp["UGG"] = "W";
    mp["UGU"] = "C";
    mp["UUA"] = "L";
    mp["UUC"] = "F";
    mp["UUG"] = "L";
    mp["UUU"] = "F";
    string ans;
    for(int  i = 0;i < s.size();i += 3){
        string asd = s.substr(i, 3);
        ans += mp[asd];
    }
    return ans == t;
}
int main() {
    string s, t;
    cin >> s >> t;
    int len = (int)t.size() * 3;
    auto tr = [](string &s){
        for(char &i : s) if (i == 'T') i = 'U';
        
    };
    for(int i = 0;i < s.size() - len + 1;i++){
        string gg = s.substr(i, len);
        string was = gg;
        tr(gg);
        string qwe = was;
        
        reverse(qwe.begin(), qwe.end());
        for (char &j : qwe){
            if (j == 'A') j = 'T';
            else if (j == 'T') j = 'A';
            else if (j == 'G') j = 'C';
            else j = 'G';
        }
        tr(qwe);
        if (check1(gg, t) || check1(qwe, t)){
            cout << was << '\n';
        }
    }
    return 0;
}