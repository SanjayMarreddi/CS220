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
Given two sequences, find the length of longest subsequence present in both of them.
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 
For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.
*/
string longest_common_subseq(string a, string b, vvl &dp)
{
    ll n = a.size(); ll m = b.size();

    // dp[i][j]  contains length of LCS of a[0..i-1] and b[0..j-1]
     
    // Fill dp table
    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=m; j++)
        {
            // If characters match
            if (a[i-1] == b[j-1])
                dp[i][j] =  1 + dp[i-1][j-1];         
                       
            // If characters do not match
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }


    string res = "";
    ll i = n, j = m;
    while (i > 0 && j > 0)
    {
        // Same element.
        if (dp[i][j] == dp[i - 1][j - 1] + 1)
        {
            res = res + a[i-1];
            i--;
            j--;
        }

        else if (dp[i][j] == dp[i - 1][j])
            i--;
        else
            j--;
    }

    reverse(res.begin(), res.end());

    if (res.size() == 0)
        return "";
    return res;
}



int main()
{   string a,b;
    cin >> a >> b;  ll n = a.size(); ll m = b.size();
    vvl dp(n+1 , vl(m+1 , 0));

    // If no common subs, it prints -1.
    cout << longest_common_subseq(a, b, dp);
    return 0;
}


