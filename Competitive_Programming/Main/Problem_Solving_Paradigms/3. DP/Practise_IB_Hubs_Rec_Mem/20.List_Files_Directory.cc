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


bool match(string s, string p){

    ll s_len = s.size();
    ll p_len =  p.size();

    vvl dp(p_len +1, vl(s_len+1, 0));  // dp[i][j] indicates if p[i:] and s[j:] matches.

    frr(i, p_len, 0 ){

        frr(j, s_len, 0){
            
            // Base case ( Empty strings match )
            if ( i == p_len and j == s_len){
                dp[i][j] = 1;
            }

            // If the current characters match, it depends on the previous state.
            else if ( p[i] == s[j] ){
                dp[i][j] = dp[i+1][j+1];
            }

            // wildcard 
            else if (p[i] == '*'){
                
                // Traverse the entire string & see if there is a match with p[i+1] from s[j] till end,
                // which means dp[i][j] = 1, since '*' can represent any number of any characters.
                fr(temp, j, s_len){

                    // Checking if there is a match earlier.
                    if (dp[i+1][temp]){
                        dp[i][j] = 1;
                        break;
                    }
                }

            }

            else{
                dp[i][j] =  0;
            }


        }
    }

    return dp[0][0];

}

void solve() {
  string p; cin >> p;
  ll n; cin >> n;
  vector<string> v(n+1); 
  ll flag = 0;
  fr(i,1, n) { 
      
      cin >> v[i]; 

      if (match(v[i], p)){
          cout << v[i] << " ";
          flag = 1;
      }
  }

  if (flag == 0){
      cout << -1 ;
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