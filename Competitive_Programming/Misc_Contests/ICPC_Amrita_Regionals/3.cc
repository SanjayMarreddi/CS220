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

// https://codedriints.io/contempsts/icpc-amritapuri-2020-regional-round/problems/hackerland

class UnionFind {

public:

    // link[i] : The next element of `i` in the chain or the parent of node `i` 
    // size[i] : The size of the corresponding set where `i` is representative. Size should be Initialised with 1.
    vector<int> link, size;
    int distinctComponents;

    UnionFind(int n) {
        // Initially all 'n' nodes are in different components.
        // components have values from 0 to n-1
	    distinctComponents = n;
        for(int i = 0; i <n; i++){
            link.push_back(i);
        }
        size = vector<int>(n,1);
    }

    // Unitemps two nodes by linking small tree root to large tree root.
    // Also Returns true when two nodes 'a' and 'b' are initially in different components. Otherwise returns false.
    bool unite(int a, int b) {

        int ParentA = find(a);
        int ParentB = find(b);
        if (ParentA == ParentB){
            return false;
        }
        
        // This helps in making union by rank.
        if (size[ParentA] < size[ParentB])  
            swap(ParentA,ParentB);
            
        size[ParentA] += size[ParentB];
        link[ParentB] = ParentA;
        distinctComponents--;
        return true;
     }

    // Returns what component does the node 'x' belong to using Path Compression.
    int find(int x) {
        if (x != link[x])
            link[x] = find(link[x]) ;
        return link[x];
    }

    // Are all nodes unitempd into a single component?
    bool unite() {
        return distinctComponents == 1;
    }
};

vector<int> sieveOpt1(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    vector<int> primesList;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i])
            primesList.push_back(i);
    }
    return primesList;
}

vector<int> pr;

void solve() {

    int n; cin >> n; vi r(n);
    fr(i,0,n-1) { cin >> r[i]; }

    if( n==1 ){ cout << 0; return; }

    // 1s should be handled separatemply since it has gcd 1 with every number.
    int num = count(all(r),1);

    // Removing the duplicatemp elements since they are anyhow connectempd with themselves.
    sort(all(r)); r.erase(unique(all(r)),r.end());

    // Storing the indices of elements to ease the lookup.
    vi id(r.back()+1,-1);
    fr(i,0,r.size()-1) id[r[i]]=i;

    // Now, the UF is initialised with the `number` of unique elements.
    n = r.size(); 
    UnionFind uf(n);

    // Combining the components if their GCD > 1 
    tra(e,pr){
        
        if ( e>r.back() )
            break; 

        vi temp;

        // Storing all multiples of prime `e` in temp.
        for(int j=e;j<=r.back();j+=e) 
            if(id[j]!=-1)
                temp.pb(id[j]);

        // Since they have gcd > 1 now we combine all the elements in temp into a single component.
        if (temp.size())
            fr(i,1,temp.size()-1) 
                uf.unite(temp[i],temp[i-1]);
    }

    // Counting number of components.
    fr(i,0,n-1) 
        if(r[i]!=1)
         num+=uf.find(i)==i; 

    // Check for presence of multiples of 2/3.
    bool two=0,three=0;
    fr(i,0,n-1) 
        two|=r[i]%2==0,three|=r[i]%3==0;

    if(num==1){ cout << 0; return; }

    // Multiplying the representative of the component is sufficient when connecting the components together.
    // Multyplying with 2/3 yields min cost than anyother numbers.
    cout << min((num-two)*2,(num-three)*3);
}

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;
    cin >>  t; 
    pr = sieveOpt1(1e6);
    fr(T,1,t){
        //cout << "Case #" << T << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}
