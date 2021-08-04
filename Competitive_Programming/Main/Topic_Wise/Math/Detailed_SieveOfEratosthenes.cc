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
#define trav(ele,container) for(auto (ele): (container)) // Just gives a copy of the elements.
#define tra(ele,container) for(auto& (ele): (container)) // Gives the reference to the elements.
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

// Detailed Reference: https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html

// Generate the primes <= n in O(nlog(logn))
vector<int> sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
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

// Generate the primes <= n in O(nlog(logn)) by sieving till root(n) only.
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

// counts the number of primes smaller than or equal to n using block sieving in O(nlog(logn)) 
int count_primes(int n) {
    const int S = 10000;

    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 2, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    int result = 0;
    vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes) {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                result++;
        }
    }
    return result;
}

// find all prime numbers in a range [L,R]
// Time complexity of this approach is O( (R−L+1)loglog(R)+ (√R)log(log(√R)) ).
vector<int> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    // return isPrime;

    vector<int> primesList;
    for (int i = L; i <= R; i++) {
        // Note this difference.
        if (isPrime[i-1])
            primesList.push_back(i);
    }
    return primesList;
}

void solve() {
    int n = 25;
    cout << count_primes(n) << endl;
    cout << sieve(n);
    cout << sieveOpt1(n);
    cout << segmentedSieve(1,n);
}

// ----------------------------------------------------------------------------------------------------------------------//

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1; 
    fr(T,1,t){
        //cout << "Case #" << T << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}
