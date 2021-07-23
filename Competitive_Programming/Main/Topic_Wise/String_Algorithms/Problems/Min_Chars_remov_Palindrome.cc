#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string pat, int m, vector<int> &lps){

	// length of the previous longest prefix suffix
	int len = 0;
	lps[0] = 0;

	int i = 1;
	while (i < m) {

		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if (len != 0) {
				len = lps[len - 1];
				// Note that we do not increment i here
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
}

signed main(){
    string s; cin >> s; int ans = 0; string rev = s; reverse(rev.begin(), rev.end());
    string updStr =  s + '*' + rev;
    vector<int> lps(updStr.size());
    computeLPSArray(updStr, updStr.size(), lps);
    cout << s.size() - lps[updStr.size()-1] ;
}