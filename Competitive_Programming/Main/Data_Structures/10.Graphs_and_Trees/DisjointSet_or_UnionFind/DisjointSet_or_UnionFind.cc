#include <bits/stdc++.h>
using namespace std;

class UnionFind {

public:

    // link[i] : The next element of `i` in the chain or the parent of node `i` 
    // size[i] : The size of the corresponding set where `i` is representative. Size should be Initialised with 1.
    vector<int> link, size;
    int distinctComponents;

    UnionFind(int n) {
        // Initially all 'n' nodes are in different components.
        // components have values from 0 to n-1
	    distinctComponents = n;
        for(int i = 0; i <n; i++){
            link.push_back(i);
        }
        size = vector<int>(n,1);
    }

    // Unites two nodes by linking small tree root to large tree root.
    // Also Returns true when two nodes 'a' and 'b' are initially in different components. Otherwise returns false.
    bool unite(int a, int b) {

        int ParentA = find(a);
        int ParentB = find(b);
        if (ParentA == ParentB){
            return false;
        }
        
        // This helps in making union by rank.
        if (size[ParentA] < size[ParentB])  
            swap(ParentA,ParentB);
            
        size[ParentA] += size[ParentB];
        link[ParentB] = ParentA;
        distinctComponents--;
        return true;
     }

    // Returns what component does the node 'x' belong to using Path Compression.
    int find(int x) {
        if (x != link[x])
            link[x] = find(link[x]) ;
        return link[x];
    }

    // Are all nodes united into a single component?
    bool united() {
        return distinctComponents == 1;
    }
};

// Usage of Class with an example
int main(){

    // Input
    int n; cin >> n;
    vector<vector<int>> edges;
    int a,b;
    for(int i=1; i<=n;i++){
        cin >> a >> b;
        edges.push_back({a,b});
    }

    // Calling class.
    UnionFind uf(n);

    // Custom code
    for(auto e : edges){
        if (uf.find(e[0]) != uf.find(e[1])){
            uf.unite(e[0], e[1]);
        }
        else{
            // Do something.
        }
    }

    // Counting number of representatives is same as counting number of sets/components
    int comp = 0;
    for(int i=0; i<n; i++){
        comp += (  uf.link[i] == i ? 1 : 0);
    } 

    cout << comp;
}