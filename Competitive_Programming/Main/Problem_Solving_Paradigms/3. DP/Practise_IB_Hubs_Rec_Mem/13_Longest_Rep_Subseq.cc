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
This problem is just the modification of Longest Common Subsequence problem. 
The idea is to find the LCS(str, str) where str is the input string with the 
restriction that when both the characters are same, they shouldn’t be on the same index in the two strings.
*/

int common_subseq(string str, vvl &dp)
{
    int n = str.length();
    
    // dp[i][j]  contains length of LCS of str[0..i-1] and str[0..j-1] with the condition that when both the characters are same, they shouldn’t be on the same index in the two strings.

    // Fill dp table (similar to LCS loops)
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            // If characters match and indexes are
            // not same
            if (str[i-1] == str[j-1] && i != j)
                dp[i][j] =  1 + dp[i-1][j-1];         
                       
            // If characters do not match
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][n];
}


string construct_subseq(string str, vvl &dp)
{
    string res = "";
    ll n = str.size();
    ll i = n, j = n;
    while (i > 0 && j > 0)
    {
        // Same element but diff indices.
        if (dp[i][j] == dp[i - 1][j - 1] + 1)
        {
            res = res + str[i-1];
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
        return "-1";
    return res;
}


int main()
{   string str;
    cin >> str; ll n = str.size();
    vvl dp(n+1 , vl(n+1 , 0));
    
    ll len = common_subseq(str, dp);
    cout << construct_subseq(str, dp);
    return 0;
}


