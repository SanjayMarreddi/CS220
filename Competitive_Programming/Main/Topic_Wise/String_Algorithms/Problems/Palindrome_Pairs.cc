#include <bits/stdc++.h>
using namespace std;

 bool isPalindrome(string str){
     string rev = str;
     reverse(rev.begin(), rev.end());
     return (rev == str);
 }
// https://leetcode.com/problems/palindrome-pairs/discuss/79215/Easy-to-understand-AC-C%2B%2B-solution-O(n*k2)-using-map

 vector<vector<int>> palindromePairs(vector<string>& words) {
         unordered_map<string, int> dict;
         vector<vector<int>> ans;
         // build dictionary
         for(int i = 0; i < words.size(); i++) {
             string key = words[i];
             reverse(key.begin(), key.end());
             dict[key] = i;
         }
         // edge case: if empty string "" exists, find all palindromes to become pairs ("", self)
         if(dict.find("")!=dict.end()){
             for(int i = 0; i < words.size(); i++){
                 if(i == dict[""]) continue;
                 if(isPalindrome(words[i])) ans.push_back({dict[""], i}); // 1) if self is palindrome, here ans covers concatenate("", self) 
             }
         }

         for(int i = 0; i < words.size(); i++) { // O(n)
             for(int j = 0; j < words[i].size(); j++) { // O(k)
                 string left = words[i].substr(0, j);   // O(k) 
                 string right = words[i].substr(j, words[i].size() - j);

                 if(dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i) {
                     ans.push_back({i, dict[left]});     // 2) when j = 0, left = "", right = self, so here covers concatenate(self, "")
                 }

                 if(dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i) {
                     ans.push_back({dict[right], i});
                 }
             }
         }

         return ans;        
}


signed main(){
    int n; cin >> n;vector<string> v(n); for(int i =0; i<n; i++) { cin>>v[i];
    if (v[i] == "-1") v[i] = ""; }
    auto ans = palindromePairs(v);
    sort(ans.begin(), ans.end());
    for(auto e: ans){
        cout << e[0] << " " << e[1] << endl;
    }
}