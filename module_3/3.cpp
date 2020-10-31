#include <bits/stdc++.h>
using namespace std;

set<int> a = {57, 71, 87,97,99,101,103,113,114,115,128,129,131,137,147,156,163,186};

int calc_score(vector<int> a, const multiset<int> & b){
    multiset<int> qwe;
    qwe.insert(0);
    
    int n = a.size();
    for(int i = 0;i < n;i++){
        int gg = 0;
        for(int j = i;j < n;j++){
            gg += a[j];
            qwe.insert(gg);
        }
    }
    multiset<int> intersect;
    set_intersection(qwe.begin(), qwe.end(), b.begin(), b.end(), inserter(intersect, intersect.begin()));
    return intersect.size();
}
int ma = -1;
vector<int> ans;

void calc(int pos, const multiset<int> &mas, vector<int> & tmp, int n, const multiset<int> & inp){
    
    if (pos == n){
        
        int gg = calc_score(tmp, inp);
        if (ma < gg){
            ma = gg;
            ans = tmp;
        }
        return;
    }
    auto kek = mas;
    for(int i : mas){
        tmp[pos] = i;
        
        kek.erase(kek.find(i));
        calc(pos + 1, kek, tmp, n, inp);
        kek.insert(i);
    }
}

int main() {
    int n;
    cin >> n;
    multiset<int> inp;
    int x;
    multiset<int> mas;
    while(cin >> x) {
        if (a.find(x) != a.end()){
            mas.insert(x);
        }
        inp.insert(x);
    }
    
    vector<int> tmp(n);
    calc(0, mas, tmp, n, inp);
    
    
    
    string out;
    for(int i : ans) out += to_string(i) + "-";
    out.pop_back();
    cout << out << '\n';
    return 0;
}