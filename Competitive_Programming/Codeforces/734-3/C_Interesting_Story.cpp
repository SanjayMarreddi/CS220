#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long                                  
#define pb push_back
#define pob pop_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define decimal(x) cout << fixed << setprecision(x)
#define fr(i,a,b) for(int (i)=(a) ; (i) <= (b) ; ++(i))
#define frr(i,a,b) for(int (i)=(a) ; (i) >= (b) ; --(i))
#define trav(ele,container) for(auto (ele): (container)) // Just gives a copy of the elements.
#define tra(ele,container) for(auto& (ele): (container)) // Gives the reference to the elements.
#define lbd(a,x) lower_bound(all((a)),(x)) - (a).begin()
#define ubd(a,x) upper_bound(all((a)),(x)) - (a).begin()
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<pi>	vpi;
typedef vector<int> vi;
typedef vector<vi>	vvi;
typedef priority_queue<int> prq;                          
const int M = 1e9 + 7;
const int INF = 1e18;
//-------------------------------------------------------- DebugHelp--------------------------------------------------
vector<string> vec_splitter(string s) {s += ','; vector<string> res; while(!s.empty()) { res.push_back(s.substr(0, s.find(','))); s = s.substr(s.find(',') + 1);} return res;}
void debug_out( vector<string> __attribute__ ((unused)) args, __attribute__ ((unused)) int idx,  __attribute__ ((unused)) int LINE_NUM) { cout << endl; } 
template <typename Head, typename... Tail> void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) { if(idx > 0) cout << ", "; else cout << "Line(" << LINE_NUM << ") ";stringstream ss; ss << H;cout << args[idx] << " = " << ss.str();debug_out(args, idx + 1, LINE_NUM, T...); }
#define dbg(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
//-------------------------------------------------------- OperatorOverload --------------------------------------------------
template <typename T> using min_prq = priority_queue<T, vector<T>, greater<T>>;   
template <typename T> ostream& operator<< (ostream& os, const vector<T>& v) 
{ os << "[ "; for (int i = 0; i < v.size(); ++i) { os << v[i]; if (i != v.size() - 1) os << ", "; } os << " ]\n"; return os; } 
template <typename T> ostream& operator<< (ostream& os, const set<T>& v) 
{ os << "[ "; for (auto it : v) { os << it; if (it != *v.rbegin()) os << ", "; } os << " ]\n"; return os; } 
template <typename T> ostream& operator<< (ostream& os, const multiset<T>& v) 
{ os << "[ "; for (auto it : v) os << it << ", "; os << " ]\n"; return os; }
template <typename T, typename S> ostream& operator<< (ostream& os, const map<T, S>& v) 
{ os << "{ "; for (auto it : v) os << it.first << " : " << it.second << ", "; os << " }\n"; return os; }
template <typename T, typename S> ostream& operator<< (ostream& os, const multimap<T, S>& v) 
{ os << "{ "; for (auto it : v) os << it.first << " : " << it.second << ", "; os << " }\n"; return os; }
template <typename T, typename S> ostream& operator<< (ostream& os, const pair<T, S>& v) 
{ os << "("; os << v.first << ", " << v.second << ")"; return os; }
template <typename T> ostream& operator<< (ostream& os, priority_queue<T> p)
{ os << "[ "; while(!p.empty()){ os << p.top() << " ,"; p.pop(); } os << " ]\n"; return os; }
//-------------------------------------------------------- Basic Number Theory --------------------------------------------------
namespace number_theory{
    int gcd(int a, int b)   { int c;  while (b){c = b; b = a % b; a = c;} return a; }
    int lcm(int a, int b)   { return (a*(b/gcd(a,b)));}
    int modpow(int a, int p = M-2, int MOD = M )   { int result = 1; while (p > 0) { if (p & 1) { result = a * result % MOD; } a = a * a % MOD; p >>= 1; } return result; }
    int ncr (int n,int k)    { int ans = 1; if (k>n-k) {k=n-k;} fr(i,1,k) {ans*=(n-i+1); ans/=i; } return ans; }
}
using namespace number_theory;
// ----------------------------------------------------------------------------------------------------------------------//
// int dp[n][n]; 

void solve() {
  // memset(dp,-1, sizeof(dp));
  int n; cin >> n;
  vector<string> v(n); fr(i,0,n-1) { cin >> v[i]; }

  vector<int> result = {0};

  // Let ans giving character is `a`.
  vector<pair<int,int>> fre; // (fre,index)
  map<int,int> charcount;
  fr(i,0,n-1){
      int cnta = 0;
      fr(j,0, v[i].size()-1){
          if (v[i][j] == 'a'){ cnta++; }
      }
      charcount[i] =  cnta;
      int cnt_other = v[i].size() - cnta;
      int contr = cnta - cnt_other;
      fre.pb({contr,i});
  }
  sort(allr(fre));
  int ans = 0; int cnta = 0; int size = 0;
  trav(e, fre){
      size += ( v[e.se].size() -charcount[e.se] ); // no of other elements
      cnta += charcount[e.se];
      if (cnta <= size){
          break;
      }  
      ans++; 
  }
  result.pb(ans);


  // Let ans giving character is `b`.
  vector<pair<int,int>> freb; // (fre,index)
  map<int,int> charcountb;
  fr(i,0,n-1){
      int cntb = 0;
      fr(j,0, v[i].size()-1){
          if (v[i][j] == 'b'){ cntb++; }
      }
      charcountb[i] =  cntb;
      int cnt_other = v[i].size() - cntb;
      int contr = cntb - cnt_other;
      freb.pb({contr,i});
  }
  sort(allr(freb));
  int ansb = 0; int cntb = 0; int sizeb = 0;
  trav(e, freb){
      sizeb += ( v[e.se].size() -charcountb[e.se] ); // no of other elements
      cntb += charcountb[e.se];
      if (cntb <= sizeb){
          break;
      }  
      ansb++; 
  }
  result.pb(ansb);


    // Let ans giving character is `c`.
  vector<pair<int,int>> frec; // (fre,index)
  map<int,int> charcountc;
  fr(i,0,n-1){
      int cntc = 0;
      fr(j,0, v[i].size()-1){
          if (v[i][j] == 'c'){ cntc++; }
      }
      charcountc[i] =  cntc;
      int cnt_other = v[i].size() - cntc;
      int contr = cntc - cnt_other;
      frec.pb({contr,i});
  }
  sort(allr(frec));
  int ansc = 0; int cntc = 0; int sizec = 0;
  trav(e, frec){
       sizec += ( v[e.se].size() -charcountc[e.se] ); // no of other elements
      cntc += charcountc[e.se];
      if (cntc <= sizec){
          break;
      }  
      ansc++; 
  }
  result.pb(ansc);


  vector<pair<int,int>> fred; // (fre,index)
   map<int,int> charcountd;
  fr(i,0,n-1){
      int cntd = 0;
      fr(j,0, v[i].size()-1){
          if (v[i][j] == 'd'){ cntd++; }
      }
      charcountd[i] =  cntd;
      int cnt_other = v[i].size() - cntd;
      int contr = cntd - cnt_other;
      fred.pb({contr,i});
  }
  sort(allr(fred));
  int ansd = 0; int cntd = 0; int sized = 0;
  trav(e, fred){
     sized += ( v[e.se].size() -charcountd[e.se] ); // no of other elements
      cntd += charcountd[e.se];
      if (cntd <= sized){
          break;
      }  
      ansd++; 
  }
  result.pb(ansd);

  
  vector<pair<int,int>> free; // (fre,index)
   map<int,int> charcounte;
  fr(i,0,n-1){
      int cnte = 0;
      fr(j,0, v[i].size()-1){
          if (v[i][j] == 'e'){ cnte++; }
      }
     charcounte[i] =  cnte;
      int cnt_other = v[i].size() - cnte;
      int contr = cnte - cnt_other;
      free.pb({contr,i});
  }
  sort(allr(free));
  int anse = 0; int cnte = 0; int sizee = 0;
  trav(e, free){
       sizee += ( v[e.se].size() -charcounte[e.se] ); // no of other elements
      cnte += charcounte[e.se];
      if (cnte <= sizee){
          break;
      }  
      anse++; 
  }
  result.pb(anse);




  cout << *max_element(all(result)); 
}

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;
    cin >>  t; 
    fr(T,1,t){
        //cout << "Case #" << T << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}