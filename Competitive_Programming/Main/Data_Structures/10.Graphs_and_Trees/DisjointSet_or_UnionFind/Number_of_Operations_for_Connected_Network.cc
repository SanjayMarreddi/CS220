#include <bits/stdc++.h>
using namespace std;

/*
There are N vertices numbered from 0 to N-1 connected by edges forming a network where connections[i] = [a, b]
represents a connection between vertices a and b. Make the graph strongly connected by using the edges forming cycles 
and and connect them to the isolated vertices.

Given an initial graph. You can extract certain edges between two directly connected vertices, and place them between 
any pair of disconnected vertices to make them directly connected. Return the minimum number of times you need to do this
in order to make all the vertices connected.

If it's not possible, return -1.

Note: There are no repeated connections. No two vertices are connected by more than one edge.
*/

int n = 1e5 + 5;
vector<int> link(n+1), size(n+1,1); 
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


int main(){ int k;
    cin >> n >> k; int a,b;
    for(int i=1; i<=k;i++){
        cin >> a >> b;
        edges.push_back({a,b});
    }

    // Dont forget this step. It is like an Initialisation step.
    // Becareful with the limits. If unsure, Just use naive for loops.
    iota(link.begin(), link.begin()+n, 0);
    
    if (k < n-1){
        cout << -1; return 0;
    }
    
    for(auto e : edges){
        if (comp_find(e[0]) != comp_find(e[1])){
            unite(e[0], e[1]);
        }
    }

    // Counting number of representatives is same as counting number of sets/components
    int comp = 0;
    for(int i=0; i<n; i++){
        comp += (  link[i] == i ? 1 : 0);
    }
    
    // Connecting `a` number of components require `a-1` edges ( similar to a tree of n nodes have n-1 edges )
    // Hence `a-1` operations are required.
    cout << comp-1;
}