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
    vector<vector<int>> points;
    int a,b;
    for(int i=1; i<=n;i++){
        cin >> a >> b;
        points.push_back({a,b});
    }

    // We insert all the possible edges first & then Standard Kruskal's algorithm needs to be implemented to find MST cost.

    vector<vector<int>> edges;          // All edges. Each point to every other point.

    for (int i=0; i<n-1; i++) {         // Point 1
        for (int j=i+1; j<n; j++) {     // Point 2
                                        
            int dist = abs(points[i][0]-points[j][0])
                        + abs(points[i][1]-points[j][1]);  // Manhattan distance.

            edges.push_back({dist, i, j});                 // Add the edge with manhattan dist. as weight.
        }
    }
    
    // Note: Unfortunately sorting, priority_queue gives TLE.
    // Min heap for heap sort.
    make_heap(edges.begin(), edges.end(), greater<>());  

    UnionFind uf(n);   // Very important to have this data structure ready.

    int cost = 0;      // Stores the cost.

    while(!edges.empty() && !uf.united()) { // Until the forest is not a single component.
        
        // This moves the smallest element to the back.
        pop_heap(edges.begin(), edges.end(), greater<>()); 
        auto edge = edges.back(); // Minimum cost edge.
        edges.pop_back();         // Remove the lowest cost edge.
        int p1 = edge[1];         // Point 1
        int p2 = edge[2];         // Point 2
        if (uf.unite(p1, p2)) {   // Merge two components.
            cost += edge[0];      // Add the cost if they were not already merged.
        }
    }
    cout << cost; 
}