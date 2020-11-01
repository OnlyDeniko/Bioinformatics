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
typedef long double ldd;
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
const ldd EPS = 1e-12;
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

vector<char> letters = {'A', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K', 'L', 'M',
                        'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'Y'};
const int sz = letters.size();
vvi a;
int dp[5000][5000];

int fi(char aa, char b){
  int ind1 = 0;
  forn(i, sz) if (letters[i] == aa){
    ind1 = i;
    break;
  }
  int ind2 = 0;
  forn(i, sz) if (letters[i] == b){
    ind2 = i;
    break;
  }
  return a[ind1][ind2];
}

int calc(int ind1, int ind2, const string &s, const string &t){
  if (dp[ind1][ind2] != -1) return dp[ind1][ind2];
  int &ans = dp[ind1][ind2];
  
  if (ind1 == 0 && ind2 == 0){
    ans = 0;
    return ans;
  }
  if (ind1 == 0){
    ans = calc(ind1, ind2 - 1, s, t);
    ans -= 5;
    return ans;
  }
  if (ind2 == 0){
    ans = calc(ind1 - 1, ind2, s, t);
    ans -= 5;
    return ans;
  }
  ans = calc(ind1 - 1, ind2, s, t) - 5;
  uax(ans, calc(ind1, ind2 - 1, s, t) - 5);
  uax(ans, calc(ind1 - 1, ind2 - 1, s, t) + fi(s[ind1 - 1], t[ind2 - 1]));
  uax(ans, 0ll);
  if (ind1 == s.size() && ind2 == t.size()){
    forn(i, ind1 + 1) forn(j, ind2 + 1){
      if (!i && !j) cont;
      int nq = ind1 - i;
      int nw = ind2 - j;
      uax(ans, calc(nq, nw, s, t));
    }
  }
  return ans;
}

void make_ans(int ind1, int ind2, const string &s, const string &t, string &q, string &w){
  if (ind1 == s.size() && ind2 == t.size()){
    forn(i, ind1 + 1) forn(j, ind2 + 1){
      if (i == ind1 && j == ind2) cont;
      if (dp[i][j] == dp[ind1][ind2]){
        make_ans(i, j, s, t , q, w);
        return;
      }
    }
  }
  if (dp[ind1][ind2] == 0){
    return;
  }
  if (ind1 == 0){
    q += '-';
    w += t[ind2 - 1];
    make_ans(ind1, ind2 - 1, s, t, q, w);
    return;
  }
  if (ind2 == 0){
    q += s[ind1 - 1];
    w += '-';
    make_ans(ind1 - 1, ind2, s, t, q, w);
    return;
  }
  if (dp[ind1][ind2] == dp[ind1 - 1][ind2] - 5){
    q += s[ind1 - 1];
    w += '-';
    make_ans(ind1 - 1, ind2, s, t, q, w);
    return;
  }
  if (dp[ind1][ind2] == dp[ind1][ind2 - 1] - 5){
    w += t[ind2 - 1];
    q += '-';
    make_ans(ind1, ind2 - 1, s, t, q, w);
    return;
  }
  q += s[ind1 - 1];
  w += t[ind2 - 1];
  make_ans(ind1 - 1, ind2 - 1, s, t, q, w);

}

void solve(){
  memset(dp, -1, sizeof(dp));
  a.resize(sz, vi(sz));
  cin >> a;
  string s, t;
  cin >> s >> t;
  cout << calc(s.size(), t.size(), s, t) << '\n';
  string q, w;
  make_ans(s.size(), t.size(), s, t, q, w);
  reverse(all(q));
  reverse(all(w));
  cout << q << '\n' << w << '\n';
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
//g++ -std=c++17 -Wall -Wextra -Weffc++ -O3 -DKULA=1 -o a test.cpp