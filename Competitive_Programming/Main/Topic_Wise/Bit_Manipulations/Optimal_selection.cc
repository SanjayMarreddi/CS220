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

inline ll pmod(ll i, ll n) { return (i % n + n) % n; }
const int mod = 1e9 + 7;
const long long INF = 1e18;

/*
We are given the prices of k products over n days, and we want to buy each product exactly once. 
However, we are allowed to buy at most one product in a day. What is the minimum total price?
*/

void solve() {

    // k = 3 products, n = 8 days.
    vvl price = { {6, 9 ,5, 2, 8, 9, 1, 6 },
                  {8, 2 ,6 ,2, 7, 5, 7 ,2 },
                  {5, 3, 9 ,7, 3, 5, 1, 4 }
                };

    ll n = 8; ll k= 3;

    // dp[i][j] ->Indicates the minimum price to buy subset i by jth day.
    vvl dp((1<<k) , vl(n, 0));

    // Base Cases. 
    // If j = 0, By 1st day, we can just buy one product with the price on that day only.
    fr(i,0,k-1){

        //  `1<<i` Implies ith product is chosen.
        dp[1 << i][0] = price[i][0];
    }


    fr(d,1,n-1){
        ll maxy = (1<<k) -1;
        fr(s, 0, maxy){

            dp[s][d] = dp[s][d-1];

            fr(x, 0,k-1){

                // Check if the element is present in the current subset
                if ( s &  (1 << x) ){
                        dp[s][d] = min( dp[s][d],  dp[(s^(1 << x))][d-1]  + price[x][d]);

                }
            }

            //deb3(s,d,dp[s][d]);
        }
    }

    cout << dp[(1 << k)-1][n-1];
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