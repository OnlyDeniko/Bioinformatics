// Copyright 2020 Kulandin Denis
#include <bits/stdc++.h>

using namespace std;
map<int, vector<int>> g;
map<int, int> deg1, deg2;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s;
    while(getline(cin, s)){
        s += ',';
        stringstream ss(s);
        int from;
        ss >> from;
        char _x;
        ss >> _x >> _x;
        int last = 0;
        while(ss){
            int to;
            ss >> to >> _x;
            g[from].push_back(to);
            last = to;
            deg1[from]++;
            deg2[to]++;
        }           
        deg2[last]--;
        deg1[from]--;
        g[from].pop_back();
    }

    int start = 0;
    vector<int> can;
    for(auto &i : g){
        if (deg1[i.first] > deg2[i.first]) can.push_back(i.first);
    }
    if (can.size() == 0) assert(0);
    auto gg = g;
    for(int start : can){
        g = gg;
        stack<int> st;
        st.push(start);
        while(!st.empty()){
            int v = st.top();
            if (!g[v].size()){
                ans.push_back(v);
                st.pop();
            } else {
                int kek = g[v].back();
                g[v].pop_back();
                st.push(kek);
            }        
        }
        string lol;
        reverse(ans.begin(), ans.end());
        for(int i : ans) lol += to_string(i) + "->";
        lol.pop_back();
        lol.pop_back();
        cout << lol << '\n';    
        return 0;
   }     
   return 0;
}