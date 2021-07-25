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

//------------------------------------------------------------------------------------------------------------------------------------//

/*
Given a list of weights [w1,w2,...,wn], determine all sums that can be constructed using the weights.
*/


/*
1. Subproblem :  Check if we can construct a sum x using the first k weights  --> possible(x,k)  // No of subproblems = O(n*Max_Sum) 
2. Guess :  --
3,4. Recurrence & Impl is below
5. Original Problem :  possible(x,n) tells us whether we can construct a sum x using all weights.

Time Complexity = O(n*Max_Sum) -> Psuedo Polynomial

Note that, Max_Sum = Sum of all the given weights.

*/

void solve() {
    ll n; cin >> n;
    vl weights(n) ;
    fr(i,0,n-1){ cin >> weights[i];}

    ll size = weights.size();
    
    ll sum = 0;
    fr(i,0,size-1){
        sum += (weights[i]);
    }

    // possible(x,k) = true if we can construct a sum x using the first k weights,
    vvl possible(sum+1, vl(size+1, 0));

    // Base Case
    possible[0][0] = 1;

    // Notice the Topological Sorting order.
    fr(x,0, sum){
        fr(k, 1, size){
        
            // If a weight is less than or equal to a sum we are constructing, then only that weight may be used.
            if (x - weights[k-1]  >= 0){
                
                // Is is possible to make sum if we include the value at `k-1` ?
                possible[x][k] |= possible[x-weights[k-1]][k-1];
            }

            // Is is possible to make sum if we ignore the value at `k-1` ?
            possible[x][k] |= possible[x][k-1];

        }
    }

    set<ll> res;
    fr(sums, 0, sum){
        if ( possible[sums][n]){
            if (sums != 0) res.insert(sums);
        }
    }

    cout << res.size() << endl;
    trav(e,res){
        cout << e << " ";
    } 



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