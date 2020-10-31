#include <bits/stdc++.h>

using namespace std;
map<int, vector<int>> g;
map<int, int> deg;
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
				deg[from]++;
				deg[to]++;
			}			
			deg[last]--;
			deg[from]--;
			g[from].pop_back();
    }

    int start = 0;
    vector<int> can;
   	
    can.push_back(0);
		auto gg = g;
		auto qwe = deg;

		for(int start : can){
			g = gg;
			deg = qwe;
			stack<int> st;
			st.push(start);
			while(!st.empty()){
				int v = st.top();
				if (deg[v] == 0){
					ans.push_back(v);
					st.pop();
		 	
				} else if (g[v].size()){
					int kek = g[v].back();
					deg[kek]--;
					deg[v]--;
					g[v].pop_back();
					st.push(kek);
				} else break;
		 	
			}
			set<int> mda;
			for(auto i : ans) mda.insert(i);
			if (mda.size() != gg.size()) continue;
			string lol;
			reverse(ans.begin(), ans.end());
			for(int i : ans) lol += to_string(i) + "->";
			lol.pop_back();
			lol.pop_back();
			cout << lol << '\n';	
			return 0;
		}
		assert(0);
		return 0;
}