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
#define trav(ele,container) for(auto (ele): (container))
#define tra(ele,container) for(auto& (ele): (container)) 
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

string  gen_random(int len) {
        string s;
        static const char alphanum[] =
            "abcdefghijklmnopqrstuvwxyz";

        for (int i = 0; i < len; ++i) {
            s+= alphanum[rand() % (sizeof(alphanum) - 1)];
             }

     return s;
}

void solve() {
  
//   fr(j,0,100){
//             string s = gen_random(4); 
            string s; cin >> s;
            int n = s.size();
            // int maxy = 1; char prev = s[0];int cnt = 1;
            // fr(i,1,n-1){
            //     if (prev == s[i]){
            //         cnt++;
            //         maxy = max(maxy, cnt);
            //     }
            //     else{
            //         maxy = max(maxy, cnt);
            //         cnt = 1;
            //         prev = s[i];
            //     }
            // }

            // // dbg(maxy);
            // maxy = s.size()-maxy;
            // dbg(maxy);

            fr(i, 1, n){
                
                string cpy1 = s;
                std::rotate(cpy1.begin(), cpy1.begin()+i, cpy1.end());
                int found = 1;
                fr(j,0,n-1){
                    if (cpy1[j] == s[j]){
                        found = 0; break;
                    }
                }

                if (found) { cout << cpy1;  return; }

            }
            
            fr(i, 1, n){

                string cpy2 = s;
                std::rotate(cpy2.begin(), cpy2.begin()+cpy2.size()-i, cpy2.end());
                int found = 1;
                fr(j,0,n-1){
                    if (cpy2[j] == s[j]){
                        found = 0; break;
                    }
                }

                if (found) { cout << cpy2;  return; }

            }

            cout << "IMPOSSIBLE";


            // if (found) { cout << cpy1;  return; }

            // 
            // found = 1;
            // fr(i,0,n-1){
            //     if (cpy2[i] == s[i]){
            //         found = 0; break;
            //     }
            // }

            // if (found) { cout << cpy2; }
            // else{
       
            //}

            // map<char,int> fre; string sr = s; reverse(all(sr));   
            // fr(i,0,n-1) { fre[s[i]]++; }
            // multimap<int, char, greater<int>> helper;
            // trav(e, fre){
            //     helper.insert({e.se, e.fi});
            // }

//             string ans = s, ansbru = s;
//             int found = 0;  
//             fr(i,0,n-1){
//                     trav(e, helper){
//                     if (e.se != ans[i] and fre[e.se] > 0 ){
//                         found++;
//                         ans[i] = e.se;
//                         fre[e.se]--;
//                         break;
//                     }
//                 }
//             }
            
//             dbg(ans);
//             if (found != n){
//                 //ans = "IMPOSSIBLE";
//                 cout << "IMPOSSIBLE";
//             }
//             else{
//                 cout << ans;
//             }
            
          
// //             int gotit = 0;
// //             string ori = ansbru, ori2 = ori;
// //             do{
                
// //                 int found2 = 1;
// //                 // dbg(ori, ansbru);
// //                 fr(i,0,n-1){
// //                     if (ori[i] == ansbru[i]){
// //                         found2 = 0;
// //                         break;
// //                     }
// //                 }

// //                 if (found2){
// //                     gotit = 1;
// //                     break;
// //                 }

// //             } while( next_permutation(all(ansbru)) );

// //             if (!gotit){
           
// //                 string prev = ori2;
// //                 do{
                    
// //                     int found2 = 1;
// //                     // dbg(ori2, prev);
// //                     fr(i,0,n-1){
// //                         if (ori2[i] == prev[i]){
// //                             found2 = 0;
// //                             break;
// //                         }
// //                     }

// //                     if (found2){
// //                         gotit = 1;
// //                         break;
// //                     }

// //                 } while( prev_permutation(all(prev)) );

// //                 if (!gotit){
// //                     ansbru = "IMPOSSIBLE";
// //                 }
// //                 else{
// //                     ansbru = prev;
// //                 }
            

// //             }
// //             else{
// //                 // nothing to do
// //             }

// //             // cout << ansbru;    
    
          

// //             if ( (ans ==  "IMPOSSIBLE" and ansbru != "IMPOSSIBLE" ) or (ans !=  "IMPOSSIBLE" and ansbru == "IMPOSSIBLE" ) ){
// //                 dbg( "WRONG", ans, ansbru, s);
// //                 exit(0);
// //             }
// //   }
}


signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;
    cin >>  t; 
    fr(T,1,t){
        cout << "Case #" << T << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}
