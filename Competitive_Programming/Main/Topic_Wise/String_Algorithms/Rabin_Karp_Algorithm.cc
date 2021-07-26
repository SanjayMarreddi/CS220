/*
Given a text T and a Pattern P, We need to find the start indices of all the occurences of the pattern P in the text T. 
*/

#include <bits/stdc++.h>
using namespace std;


// The average and best-case running time of the Rabin-Karp algorithm is O(n+m), but its worst-case time is O(nm).
void RKsearch(string pat, string txt, int q){

    int d = 256;
    int m = pat.size(), n = txt.size();

    // This quantity is helpful in calculating the hash value for the next substring using the previous sustring.[ h = d^(m-1)%q ]
    int h = 1;  
    for(int i = 0; i <m-1; i++){
        h = (h*d)%q;
    }

    // Calculating Hash value for the pattern & the first substring of txt.
    int t = 0, p = 0;
    for (int i = 0; i <m; i++){
        p = (d*p + pat[i]) % q;
        t = (d*t + txt[i]) % q;
    }


    for (int i = 0; i <= n-m; i++){

        // If hash values match
        if (p == t){

              bool allMatch = 1;
              // Bruteforce check all the characters.
              for (int j = 0; j < m; j++){
                  if ( pat[j] != txt[i+j] ){
                      allMatch = 0;
                      break;
                  }
              }

              if (allMatch){
                  cout << "Found pattern at index " <<  i << endl;
              }
        }

        // Calculate hash values for the next window of the text. Remove leading digit, add trailing digit
        // Note that this way of updating Hash Values of substrings is known as ROLLING HASH.
        if (i < n-m ){

            t = ( d*( t - txt[i]*h ) + txt[i+m] ) % q;

            if (t < 0){
                t += q;
            }
        }
    }
}

int main(){
  int q = 101;
  string pat = "abc", txt = "abcabaabcabac";
  RKsearch(pat, txt, q);
  return 0;
}