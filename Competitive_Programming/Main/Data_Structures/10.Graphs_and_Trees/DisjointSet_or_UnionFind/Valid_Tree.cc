#include <bits/stdc++.h>
using namespace std;

/*
You are given T sets of N nodes labelled from 0 to N-1 and M undirected edges (each edge is a pair of nodes). 
Write a program to check whether these edges make up a valid tree.
*/

int n = 1e4 + 5;
vector<int> link(n), size(n,1); 
// link[i] : The next element of `i` in the chain or the parent of node `i` 
// size[i] : The size of the corresponding set where `i` is representative. Size should be Initialised with 1.

vector<vector<int>> edges;

// O(logn)
int find(int x) {
    while (x != link[x])
        x = link[x];
    return x;
}

// Each node in the path is pointed directly towards the root.
// A bit efficient version of `find`
int comp_find(int x) {
    if (x != link[x])
        link[x] = comp_find(link[x]) ;
    return link[x];
}


// O(logn)
void unite(int a, int b) {
    
    a = comp_find(a);
    b = comp_find(b);
    
    // This helps in making union by rank.
    if (size[a] < size[b])  
        swap(a,b);
        
    size[a] += size[b];
    link[b] = a;
}


int main(){
    int t; cin >> t;
    while(t--){
        
            int m;
            cin >> n >> m; int a,b;
            
            // Tree of n nodes has exactly n-1 edges.
            if (m < n-1 or m > n-1) {
                cout << "NO "; continue;
            }
            
            for(int i=1; i<=m;i++){
                cin >> a >> b;
                edges.push_back({a,b});
            }
        
            iota(link.begin(), link.begin()+n, 0);
        
            int ans = 0;
            for(auto e : edges){
                if (comp_find(e[0]) != comp_find(e[1])){
                    unite(e[0], e[1]);
                }
                else{  
                    // If the parents are already matching for the current
                    // edge nodes, It means they are already connected & 
                    // current edge is a redundant edge. Since we have exactly 
                    // n-1 edges in which 1 edge is wasted and the current 
                    // edge if added to graph will form a cycle.
                    // So, we cant form a valid tree. 
                    ans++;
                    break;
                }
            }
            
            cout << (( ans == 1 ) ? "NO" : "YES" ) << " ";
            edges.clear();
            link = vector<int>(n);
            size = vector<int>(n,1);
    }
}