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

bool is_divisible(ll n, ll k, vl &v, vvl &dp){

     /*
    Basically, since we need to cover all the given numbers for sure,
    We start with the 1st number, Find the remainder upon dividing with
    k & put 1 in coresponding column.
    
    Then from the next number, We have two options,
    To add with previous number or subtract from previous number.
    We do the both cases & divide by k & put 1 at coreponding remainders in both cases & 
    repeat the same for all the numbers.
    
    */

   // dp[i][j] = 1 means that we can construct a sum using indices 0,1,2,.. i that has remainder of j when divided by k.

    dp[0][v[0]%k] = 1;

    // Iterating over all the positions
    fr(i, 1, n-1){

        // Checking what is the remainder till the prev position (i-1) by trying all possible remainders.
        fr(j, 0, k-1){

            // If the  ( (value of the expression till previous position) % k ) is `j` 
            if (dp[i-1][j] ){
                
                /* In C++, reminder in case of negative numbers
                is negative Ex: -15%4 == -3. To make it positive, we used abs().
                Also, after addding/subtracting the current reminder (v[i]%k) to 
                the earlier reminder, we need to take %k again to get actual 
                reminder that we get when we deal with actual expressions.
                */

                // Putting ones in both the possible remainders pos.
                dp[i][ ( j  + v[i] % k ) % k  ] = 1;          // We can add

                dp[i][ ( abs ( j - v[i] % k ) ) % k  ] = 1;   // We can subtract

            }

        }

    }

    // At the end, We check if the Remainder is `0` when divided by k
    return dp[n-1][0];
}

void solve() {
  ll n, k; cin >> n >> k;
  vvl dp(n+1, vl(k+1,0));  vl v(n); 
  fr(i,0,n-1) { cin >> v[i]; v[i] =  abs(v[i]); }
  is_divisible(n,k, v, dp) ? cout << "True" : cout << "False";
}

signed main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;

    cin >>  t;  // Comment this line if only 1 testcase exists.

    fr(T,1,t){

        //cout << "Case #" << T << ": ";

        solve();
        cout << "\n";
    }
    return 0;
}