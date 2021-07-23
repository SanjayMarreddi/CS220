#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll>	vl;
typedef vector<pi>	vpi;
typedef vector<pl>	vpl;
typedef vector<vi>	vvi;
typedef vector<vl>	vvl;
typedef priority_queue<ll> prq;  // Max priority Queue.
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define sz(x) (ll)(x).size()
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define decimal(x) cout << fixed << setprecision(x)
#define fr(i,a,b) for(ll (i)=(a) ; (i) <= (b) ; ++(i))
#define frr(i,a,b) for(ll (i)=(a) ; (i) >= (b) ; --(i))
#define trav(ele,container) for(auto (ele): (container)) // Just gives a copy of the elements.
#define tra(ele,container) for(auto& (ele): (container)) // Gives the reference to the elements.
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << " = " << x << "  ,  " << #y << "=" << y << "  ,  " << #z << "=" << z << endl
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
template <typename T> using min_prq = priority_queue<T, vector<T>, greater<T>>;   // Min priority queue
template <typename T> T mpow(T x, T n) {
    T res = 1;
    for(; n; n >>= 1, x *= x)
        if(n & 1) res *= x;
    return res;
}

inline ll pmod(ll i, ll n) { return (i % n + n) % n; }
const int mod = 1e9 + 7;
const long long INF = 1e18;

//------------------------------------------------------------------------------------------------------------------------------------//


/*
Find the longest increasing subsequence in an array of n elements. 
This is a maximum-length sequence of array elements that goes from left to right,
and each element in the sequence is larger than the previous element. 
*/


/*

1. Subproblem :  Max Length of Longest incre. Subs till Index i --> PREFIXES          // No of subproblems = O(n) 
2. Guess :                       --
3,4. Recurrence & Impl is below
5. Original Problem :  Max Length of Longest incre. Subs till Index n-1       

*/
ll getBestCandiate(map<ll,ll> &candidates, ll val){
  // We need to take the greatest value which is less than `val`.
  // So If we take the `lower_bound`, we get the smallest value which is  >= `val`, It we move tothe previous element of this, we get req.
  
  auto itr = candidates.lower_bound(val);
  if (itr != candidates.begin()){
     itr--;
     return (itr->second); // Returning the advantage. 
  }
  else{
      // No suitable candidate.
      return 0;
  } 
}

void insertCand(map<ll,ll> &candidates, ll val, ll adv){

    // If there is already same candidate with >= adv.
    if (candidates[val] >= adv){
        return;
    }

    candidates[val] = adv;

    // Get its position
    auto itr = candidates.find(val);
    
    // Remove any unnecessary candidates. (Elements with value > val but <= advantage)
    itr++;
    while (itr != candidates.end() && itr->second <= adv){
      auto temp = itr;
      itr++;
      candidates.erase(temp);
    }

}

// O(nlogn) solution.
void solve() {
  ll n; cin >> n; 
  vl v(n); fr(i,0,n-1) cin >> v[i];
  vl dp(n,0);
  
  // dp[i] indicates the length of the longest subsequence that ends at index i.
  dp[0] = 1;

  // This map stores the length a value can contribute to the indexes preceeding it. i.e. Length it will be increased upon adding to it.
  map<ll,ll> candidates;
  candidates[v[0]] = dp[0];

  fr(i,1,n-1){

    // Choose which subseq to extend.
    dp[i] = 1 + getBestCandiate(candidates, v[i]);
    insertCand( candidates, v[i], dp[i] );
  }
  
  cout << *max_element(all(dp));
}
 
signed main() {
 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    fastIO;
    int t = 1;
 
   // cin >>  t;  // Comment this line if only 1 testcase exists.
 
    fr(T,1,t){
 
        //cout << "Case #" << T << ": ";
 
        solve();
        cout << "\n";
    }
    return 0;
}

// Ref: https://youtu.be/66w10xKzbRM


// // O(n^2) solution.
// void solve() {
//   ll n; cin >> n; 
//   vl v(n); fr(i,0,n-1) cin >> v[i];
//   vl dp(n,0);
  
//   // dp[i] indicates the length of the longest subsequence that ends at index i.
//   dp[0] = 1;

//   fr(i,1,n-1){

//     // Try all the possible & valid subsequences before ith index & check which to extend.
//     ll ans = 1;   // If no valid index is found, we can start a subseq from the current index itself.

//     fr(j,0,i-1){
//         if (v[j] < v[i]){
//             ans = max(ans, 1 + dp[j]);
//         }
//     }

//     dp[i] = ans;
//   }

//   cout << *max_element(all(dp));