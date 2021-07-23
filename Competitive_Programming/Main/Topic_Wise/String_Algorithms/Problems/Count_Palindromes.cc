#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    string s; cin >> s; int n = s.size();

    vector<vector<int>> dp(n+1, vector<int>(n+1)); // dp[i][j] -> #Palindromes of size >= 2 from s[i...j] 
    vector<vector<int>> isPalin(n+1, vector<int>(n+1));

    for(int i = 0; i < s.size(); i++){
        isPalin[i][i] = 1;
        dp[i][i] = 0;
    }

    for(int i = 0; i < s.size()-1; i++){
        if (s[i] == s[i+1]){
            isPalin[i][i+1] = 1;
            dp[i][i+1] = 1;
        }
    }

    // Toplogical sorting order. The plan is to find the answers by considering the substrings of smaller size -> larger size order. 
    for(int gap=2; gap <n; gap++){  // Checking the substrings of size `gap+1`     [i, i+gap] -> includes `i+gap-i+1` = `gap+1` elements
        for ( int i = 0; i < n-gap; i++){
            int j = i+gap;  

            if ( s[i] == s[j] and isPalin[i+1][j-1]){
                isPalin[i][j] = 1;
            }

            //Note that the dependency of DP calls. They always make calls to strings of size lower than the current string,
            if (isPalin[i][j]){
                
                // Finding the answer for the left & right substring after removing one character dp[i][j-1] and dp[i+1][j],
                // and then we are subtracting the count of common substring dp[i+1][j-1] since it is added twice.
                // `1` indicates the current substring `s(i...j)`
                dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1 - dp[i+1][j-1];
            }
            else{
                dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
            }

        }
    }


    cout << dp[0][n-1] + n ;
}