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
const int M = 1e9 + 7;
const ll INF = 1e18;
template <typename T> using min_prq = priority_queue<T, vector<T>, greater<T>>;   // Min priority queue
template <typename T> T pw(T a,T p=M-2,T MOD=M){
	int result = 1;
	while (p > 0) {
		if (p & 1)
			result = a * result % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return result;
}

void solve() {
  ll n = 1e6; 
  vvl dp(n+2, vl(2,0));

  // dp[i][j] : Indicates the number of ways to fill  positions from i till n if at the (i-1)th position, we have `j`.
  // `j` = 1 : If at the (i-1)th position we had a tile of width  2.
  // `j` = 0 : If at the (i-1)th position we had 2 tiles of width 1.

  dp[n+1][0] = 1;
  dp[n+1][1] = 1;

  frr(i, n, 2){
    
     // First, lets evaluate dp[i][0]. We have 3 cases:

    // 1. We are not extending any of the previous tile. So, we have 2 options, either we can keep type `0` or `1`.
    // So we add number of ways to fill the tower from i+1 till n in both cases of having (0/1) at current position.
    ll op1 = ( dp[i+1][1] + dp[i+1][0] )% M;

    // 2. Extend both 
    ll op2 = ( dp[i+1][0] )% M;
    
    // 3. Extend one of the tiles. (Symmetric in both cases)
    ll op3 =  ( 2*dp[i+1][0] )% M;
  
    dp[i][0] = ( (op1 + op2)%M + op3 )% M;

    
    // Now, lets evaluate dp[i][1]. We have 2 cases:
    
    // 1. We are not extending any of the previous tile. It is same as `op1`.

    // 2. Extending both of these.
    ll op4 = dp[i+1][1];

    dp[i][1] = (op1 + op4)%M;
  }
  

  // Precomputing & printing.
  ll t ; cin >> t;
  while(t--){
    ll q; cin >> q; 
    
    // If there is no precomputing the actual answer is dp[2][0] +  dp[2][1].

    // Actually, we need to print no of ways to fill postitions from 2 till q, While at 1, It can be 0/1.
    cout << ( dp[1e6 - q +2][0] + dp[1e6 - q + 2][1] )%M <<  endl; 
  }
}

signed main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;

    //cin >>  t;  // Comment this line if only 1 testcase exists.

    fr(T,1,t){

        //cout << "Case #" << T << ": ";

        solve();
        cout << "\n";
    }
    return 0;
}

// Ref: https://youtu.be/pMEYMYTX-r0