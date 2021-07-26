#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
typedef priority_queue<ll> prq;
#define vt vector
#define fr(i,a,b) for(ll (i)=(a) ; (i) <= (b) ; ++(i))
#define frr(i,a,b) for(ll (i)=(a) ; (i) >= (b) ; --(i))
#define trav(e,a) for(auto (e): (a))
#define tra(e,a) for(auto& (e): (a))
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define lbd(a,x) ll(lower_bound(all((a)),(x)) - (a).begin())
#define ubd(a,x) ll(upper_bound(all((a)),(x)) - (a).begin())
#define sz(x) (ll)(x).size()
#define IOS ios::sync_with_stdio(0);cin.tie(0) 
#define decimal(x) cout << fixed << setprecision(x)
#define dbg1(x9) cout << #x9 << " = " << x9 << endl
#define dbg2(x9, y9) cout << #x9 << " = " << x9 << "   " << #y9 << " = " << y9 << endl
#define dbg3(x9, y9, z9) cout << #x9 << " = " << x9 << "   " << #y9 << " = " << y9 << "  "<< #z9 <<" = "<< z9 << endl
#define dbg4(x9, y9, z9, w9) cout << #x9 << " = " << x9 << "   " << #y9 << " = " << y9 << "  "<< #z9 <<" = "<< z9 << "  " << #w9 <<" = "<< w9 << endl
#define get5(a9, b9, c9, d9, e9, ...) e9
#define DBG(...) get5(__VA_ARGS__, dbg4, dbg3, dbg2, dbg1)
#define dbg(...) DBG(__VA_ARGS__)(__VA_ARGS__)

template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T> istream &operator>> (istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream& operator<< (ostream& os, const vector<T>& v) 
{ os << "[ "; for (int i = 0; i < v.size(); ++i) { os << v[i]; if (i != v.size() - 1) os << ", "; } os << " ]\n"; return os; } 
template <typename T> ostream& operator<< (ostream& os, const set<T>& v) 
{ os << "[ "; for (auto it : v) { os << it; if (it != *v.rbegin()) os << ", "; } os << " ]\n"; return os; } 
template <typename T> ostream& operator<< (ostream& os, const multiset<T>& v) 
{ os << "[ "; for (auto it : v) os << it << ", "; os << " ]\n"; return os; }
template <typename T, typename S> ostream& operator<< (ostream& os, const map<T, S>& v) 
{ os << "{ "; for (auto it : v) os << it.first << " : " << it.second << ", "; os << " }\n"; return os; }
template <typename T, typename S> ostream& operator<< (ostream& os, const pair<T, S>& v) 
{ os << "("; os << v.first << ", " << v.second << ")"; return os; }
template <typename T> ostream& operator<< (ostream& os, queue<T> p)
{ os << "[ "; while(!p.empty()){ os << p.front() << " ,"; p.pop(); } os << " ]\n"; return os; }

const long long INF=1e18;
const ll mod=1e9+7;
inline ll pmod(ll i, ll n=mod) { return (i % n + n) % n; }
inline ll cdiv(ll a,ll b){ return (a+b-1)/b; }

const ll mxN = 1e6+1;
vl fac(mxN);
void init(){
    fac[0] = fac[1] = 1;
    fr(i,2,mxN-1) fac[i] = (fac[i-1] * i) % mod; 
}
ll powm(ll a,ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}
ll ncr(ll n,ll r){
    if(r > n) return 0;
    ll temp = (fac[r] * fac[n-r]) % mod;
    return (fac[n] * powm(temp,mod-2)) % mod;
}

// https://codedrills.io/contests/amrita-icpc-practice-session-7/problems/horse-and-barns

/*
If there was only one barn we could run a BFS from that source and fill the the values of distance for each cell.
But we could have many barns, so we push all the barns in the queue and consider all of them as sources. 
Then we can just run normal BFS and fill the the values of distance for each cell. This is called Multi-Source BFS or MBFS.
*/

void solve(){
    ll n,m,k; cin >> n >> m >> k;
    vt<vt<char>> a(n,vt<char>(m)); cin >> a;

    // dist[i][j] be the distance of the nearest barn for cell (i,j) because in BFS, we always reach a vertex from a given source
    // using the minimum number of edges.
    queue<pl> q; vvl dis(n,vl(m,INF));
    fr(i,0,n-1) fr(j,0,m-1) if(a[i][j]=='X') q.push({i,j}),dis[i][j]=0;

    while(sz(q)){
        pl p=q.front(); q.pop();

        // Take all valid moves
        fr(x,-2,2) fr(y,-2,2){ 

            if(!x || !y || abs(x)+abs(y)!=3 || p.fi+x>=n || p.fi+x<0 || p.se+y>=m || p.se+y<0) continue; 

            // If distance to the reachable cell is greater than current known path (1 + dis[p.fi][p.se]),
            // Update it and push into queue.
            if(dis[p.fi+x][p.se+y]>dis[p.fi][p.se]+1)
                { dis[p.fi+x][p.se+y]=dis[p.fi][p.se]+1;
                q.push({p.fi+x,p.se+y}); }
        }
    }

    // cnt[i][j] contains the frequency of `dis[i][j]` i.e, No of nodes with nearest distance to BARN as `dis[i][j]`
    vl cnt(n*m);

    ll ans=0;
    fr(i,0,n-1) fr(j,0,m-1) ++cnt[dis[i][j]];

    // At each iteration, we are doing prefix sum first & then
    // caculating no of ways to choose k positions such that we are placing the k horses such that max. distance travelled among all
    // horses is `i`, So the prefix is useful since it has count of no of grid positions with max.distance as i.

    // When we are considering the No of ways to choose k positions from cnt[i] grids, we subtract ncr(cnt[i-1], k),
    // Because, in ncr(cnt[i], k) ways, `ncr(cnt[i-1],r)` exactly represents the previous case where none of elements with `cnt[i]` are choosen. 
    fr(i,1,n*m-1) cnt[i]+=cnt[i-1],ans += pmod((ncr(cnt[i],k)-ncr(cnt[i-1],k)))*i,ans%=mod;

    // Expectation:   P1*x1 + P2*x2 +....   -> ( 1/deno )* (   cnt_possible_ways_1*x1 +  cnt_possible_ways_2*x2 + ....)
    // Numerator   : ans
    // Denominator : Total number of possibilities to keep k horses. ( nm^C_K )
    cout << ans*powm(ncr(n*m,k),mod-2)%mod;
}

int main(){
    IOS;
    int t = 1;
    cin >> t;
    init();
    for(int t1=1;t1<=t;++t1){
        solve();
        cout << '\n';
    }
}