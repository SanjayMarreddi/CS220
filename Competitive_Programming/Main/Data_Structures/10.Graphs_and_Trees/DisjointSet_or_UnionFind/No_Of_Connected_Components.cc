#include <bits/stdc++.h>
using namespace std;

/*
You are given N nodes labeled from 0 to N - 1 and an array of E undirected edges
(each edge is a pair of nodes), write a program to find the number of connected components
in the undirected graph.

Note: You can assume that no duplicate edges will appear in edges. 
All edges are undirected, 0 1 is the same as 1 0 and thus will not appear together in edges.
*/

int n = 5*(1e3) + 5;
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
    int e;
    cin >> n >> e; int a,b;
    for(int i=1; i<=e;i++){
        cin >> a >> b;
        edges.push_back({a,b});
    }

    iota(link.begin(), link.begin()+n, 0);

    int ans = 0;
    for(auto e : edges){
        if (comp_find(e[0]) != comp_find(e[1])){
            unite(e[0], e[1]);
        }
    }

    // Counting number of representatives is same as counting number of sets/components
    for(int i=0; i<n; i++){
        ans += (  link[i] == i ? 1 : 0);
    } 

    cout << ans;
}