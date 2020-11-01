// Copyright 2020 Kulandin Denis
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#pragma optimize("jillzay, jillzay, paci, paci, gilzi, gilzi")
#pragma optimize("JARU SOSISONI")
 
using namespace __gnu_pbds;
using namespace std;
 
template <class T>
istream& operator >> (istream& in, vector<T>& v){ for(auto& e : v){ in >> e;} return in;}
template <class T>
istream& operator >> (istream& in, pair<T, T> &v){ in >> v.first >> v.second; return in;}
 
#define int long long
//#define int short int
#define pb push_back
#define mkp make_pair
#define X first
#define Y second
#define cont continue
#define For(i, a, b) for (int i = a; i < b;i++)
#define forn(i, a) for (int i = 0;i < a;i++)
#define ford(i, a, b) for (int i = b - 1;i >= a;i--)
#define fordn(i, a) for (int i = a - 1;i >= 0;i--)
#define forr(x, arr) for(auto &x: arr)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define makeunique(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
void debug_out(){ cout << '\n';}

template<typename head, typename... tail>
void debug_out(head H, tail... T){ cout << " " << H; debug_out(T...);}

#ifdef KULA
    #define deb(...) cout << "[" << #__VA_ARGS__ << "] :", debug_out(__VA_ARGS__)
    template <char d = ' ', class T>
    ostream& operator << (ostream& out, const vector<T>& v){ out << "[";for(int i = 0;i < v.size();i++){out << v[i];if (i != v.size() - 1) out << " ";} out << "]"; return out; }
    template <char d = ' ', class T>
    ostream& operator << (ostream& out, const pair<T, T>& v){ out << "[";out << v.first << ", " << v.second;out << "]"; return out;}
    template <char d = ' ', class T>
    ostream& operator << (ostream& out, const set<T>& v){out << "["; for(auto i = v.begin();i != v.end();i++){ out << *i; if (*i != *v.rbegin()) out << ", ";} out << "]"; return out;}
    template <char d = ' ', class T>
    ostream& operator << (ostream& out, const multiset<T>& v){out << "["; for(auto i = v.begin();i != v.end();i++){ out << *i; if (*i != *v.rbegin()) out << ", ";} out << "]"; return out;}
#else
    #define deb(...)
    template <char d = ' ', class T>
    ostream& operator << (ostream& out, const vector<T>& v){ for(auto& e : v){ out << e << d;} return out;}
    template <char d = ' ', class T>
    ostream& operator << (ostream& out, const pair<T, T> & v){ out << v.X << d << v.Y; return out;}
    template <char d = ' ', class T>
    ostream& operator << (ostream& out, const set<T>& v){ for(auto& e : v){ out << e << d;} return out;}
#endif
typedef long long ll;
typedef double ldd;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef set<int> si;
typedef set<pii> spii;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
template<typename T> T sqr(T a) {return a * a;}
mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
//const int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
//const int dy[8] = {1, -1, 1, 0, -1, 1, 0, -1};
//const int dx[8] = {-2, -2, 1, 1, -1, -1, 2, 2};
//const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
const ldd EPS = 1e-6;
const int MOD = 1e9 + 7;
const ldd PI = acos(-1.);
/*const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
    assert((mpos += n) <= MAX_MEM);
  return (void *)(mem + mpos - n);
}
inline void operator delete ( void * ) noexcept { }*/
int K, T;
vector<vector<ldd>> makeTable(const vs & s){
    map<int, map<char, int>> mp;
    forr(i, s){
        forn(j, i.size()){
            mp[j][i[j]]++;
        }
    }
    forn(i, s[0].size()){
        mp[i]['A']++;
        mp[i]['C']++;
        mp[i]['G']++;
        mp[i]['T']++;
    }
    vector<vector<ldd>> ans(4, vector<ldd>(K));
    forn(i, K){
        ldd gg = 1. / mp[i].size();
        forr(j, mp[i]){
            if (j.X == 'A') ans[0][i] = gg * j.Y;
            else if (j.X == 'C') ans[1][i] = gg * j.Y;
            else if (j.X == 'G') ans[2][i] = gg * j.Y;
            else ans[3][i] = gg * j.Y;
        }
    } 
    deb(ans);
    return ans;
}

int calc(vs & a){
    int ans = 0;
    forn(i, a[0].size()){
        int ma = -1;
        char ind;
        map<char, int> mp;
        forn(j, a.size()){
            mp[a[j][i]]++;
            if (uax(ma, mp[a[j][i]])) ind = a[j][i];            
        }
        ans += T - ma;
    }
    return ans;
}

ldd score(string & s, vector<vector<ldd>> & a){
    ldd ans = 1;
    forn(i, s.size()){
        if (s[i] == 'A') ans *= a[0][i];
        else if (s[i] == 'C') ans *= a[1][i];
        else if (s[i] == 'G') ans *= a[2][i];
        else ans *= a[3][i];
    }
    return ans;
}

void solve(){
    
    cin >> K >> T;
    vs a(T);
    cin >> a;
    vs ANS; 
    forn(i, T){
        ANS.pb(a[i].substr(0, K));
    }
    int ans = calc(ANS);
    forn(i, a[0].size() - K + 1){
        map<int, set<char>> mp;
        vs tmp; 
        string s = a[0].substr(i, K);
        tmp.pb(s);      
        For(j, 1, T){
            auto table = makeTable(tmp);
            string ind = a[j].substr(0, K);
            auto ma = score(ind, table);
    
            For(k, 1, a[j].size() - K + 1){
                string qwe = a[j].substr(k, K);
                auto sc = score(qwe, table);
                if (ma < sc - EPS){
                    ma = sc;
                    ind = qwe;
                }
                
            }
            tmp.pb(ind);
        }
        deb(tmp);
        deb(calc(tmp));
        
        int pog = calc(tmp);
        if (ans > pog){
            ans = pog;
            ANS = tmp;
        }


    }
    deb(ans);
    forr(i, ANS){
        cout << i << '\n';
    }
}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  #ifdef KULA
//            freopen("input.txt", "r", stdin);
//            freopen("output.txt", "w", stdout);
  #else
//            freopen("input.txt", "r", stdin);
//            freopen("output.txt", "w", stdout);
  #endif
  int t = 1;
//  cin >> t;
  forn(i, t) solve();
  return 0;
}