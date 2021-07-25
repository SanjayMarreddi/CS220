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

/*
For every interval (i, j) there is a fixed person who is going to be playing on that interval.

dp[i][j] stores the difference between the scores of the person who is playing on that interval 
and then person who plays next if they are only allowed to use that interval. Since the person 
playing can only take the ends of the intervals, only i and j are available.

Call the person taking currently A.

If he takes i, then the interval becomes (i + 1, j).
dp[i + 1][j] stores the value of B - A, so you subtract it from a[i] to get A + a[i] - B which is 
the value for the current segment if A takes i. It is very similar for if A takes j, and you compare them to get dp[i][j].
dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1])

Extra Ref: https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/
*/

void solve() {
 ll n; cin >> n; vl v(n);
 ll sum = 0;
 fr(i,0,n-1) { cin >> v[i]; sum += v[i]; }

  vvl dp(n, vl(n,0)); 
 
  // Left index
  frr(i,n-1,0){

      // Right Index
      fr(j,i,n-1){

          if (i == j ){ dp[i][j] = v[i];}
          else{
              // Think abt intution behind this recurrence.
              dp[i][j] = max(v[i] - dp[i+1][j], v[j] - dp[i][j-1] );
          }
      }
  }

  // We can reconstruct the score of player 1 as the mean of, the sum of all input values, and score1−score2.
  // since sum = score1 + score2;
  cout << ( sum + dp[0][n-1] )/2;
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