#include <bits/stdc++.h>
using namespace std;

/*
You are given N nodes which are labeled from 1 to N and N directed edges.
Among the N edges, N-1 edges form a rooted tree excluding the remaining one directed edge.

A rooted tree is a directed graph such that, there is exactly one node (the root) 
for which all other nodes are descendants of this node, plus every node has exactly one parent,
except for the root node which has no parents.

Each edge u v represents a directed edge connecting nodes u and v, where u is a parent of child v.

Return an edge that should be removed so that the resulting graph is a rooted tree of N nodes.
If there are multiple answers, return the answer that occurs last in the given array.
*/

int n = 2*(1e5);
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

vector<int> ans;

// O(logn)
void unite(int a, int b) {
    
    // We slighlty modified this part of UnionFind DS.
    if (comp_find(a) == comp_find(b)){
        ans.push_back(a); 
        ans.push_back(b);
        return;
    }
    
    a = comp_find(a);
    b = comp_find(b);
    
    // This helps in making union by rank.
    if (size[a] < size[b])  
        swap(a,b);
        
    size[a] += size[b];
    link[b] = a;
}


void redundant_conn(){
    
    queue< pair<int,int> > q;
    vector<int> indegree(n+1);
    
    for(auto e : edges){
        indegree[e[1]]++;
    }
    
    for(auto e : edges){
        if (indegree[e[1]] > 1){
            q.push({e[0], e[1]});
        }
        else{
            unite(e[0], e[1]);
        }
    }

    while(!q.empty()){
        auto curr_edge = q.front(); q.pop();
        unite(curr_edge.first,curr_edge.second);
    }
}
 
int main(){
   cin >> n; int a,b;
   for(int i=1; i<=n;i++){
       cin >> a >> b;
       edges.push_back({a,b});
   }
   
   // Dont forget this step.
   iota(link.begin(), link.begin()+n, 0);
   redundant_conn();
   for(int i=0; i <ans.size(); i++){
       cout << ans[i] << " " ;
   }
}