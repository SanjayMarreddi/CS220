#include <bits/stdc++.h>
using namespace std;

/*
You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added.
The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.
The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge 
between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. 
If there are multiple answers, return the answer that occurs last in the input.
*/

int n = 1e3 + 5;
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
   cin >> n; int a,b;
   for(int i=1; i<=n;i++){
       cin >> a >> b;
       edges.push_back({a,b});
   }
   
    // Dont forget this step.
    iota(link.begin(), link.begin()+n+1, 0);
    vector<int> ans;
    for(auto e : edges){
        if (comp_find(e[0]) != comp_find(e[1])){
            unite(e[0], e[1]);
        }
        else{
           ans.push_back(e[0]);
           ans.push_back(e[1]);
        }
    }
    cout << ans[0] << " " << ans[1] ;
}