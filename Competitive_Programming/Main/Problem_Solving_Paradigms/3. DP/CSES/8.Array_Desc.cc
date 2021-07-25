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

ll poss_arrays(vl &arr, ll n, ll m){

     vvl dp(n, vl(m+1, 0));  // dp[index][Value]
     // dp[i][v] = number of ways to fill the array up to index i, if x[i] = v.

     if (arr[0] == 0){
        fr(i,0,m){ dp[0][i] = 1;}
     }
     else{
         dp[0][arr[0]] = 1;
         // Rest all are zeroes.
     }
      
      fr(i,1,n-1){
            
            if (arr[i] == 0){
                // try all the possible values for element.
                fr(j,1,m){

                       for (int k : {j-1,j,j+1}) {

                           // Dont forget to check this condition.
                            if (k >= 1 && k <= m) {
                                    
                                    // Should perform Modulo for every operation.
                                    (dp[i][j] += dp[i-1][k]) %= M;
                            }
                        } 

                    }
            }
            else{
                    for (int k : {arr[i]-1,arr[i],arr[i]+1}) {

                             if (k >= 1 && k <= m) {
                                    (dp[i][arr[i]] += dp[i-1][k]) %= M;
                            }
                        }   
            }
      }

    
    ll ans = 0;
    fr(i,1,m){
        ans = ( ans + dp[n-1][i]) %M;
    }

    return ans;
}

void solve() {
  ll n, m ; cin >> n >> m;
  vl v(n); fr(i,0,n-1) cin >> v[i];
  cout << poss_arrays(v,n,m);
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