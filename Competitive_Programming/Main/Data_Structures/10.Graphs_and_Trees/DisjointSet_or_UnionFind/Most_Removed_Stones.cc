#include <bits/stdc++.h>
using namespace std;


/*
On a 2D plane, we place N stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length N where stones[i] = [xi, yi] represents the location of the ith stone, 
return the largest possible number of stones that can be removed.
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
    
    // Dont forget this step. It is like an Initialisation step.
    // Becareful with the limits. If unsure, Just use naive for loops.
    iota(link.begin(), link.begin()+n, 0);
    
    // Imagine each stone has an ID corresponding to its index in the input array.
    
    // Map each occupied row to a vector of all stone IDs in that row. Repeat for columns.
    unordered_map<int, vector<int>> rowmap, colmap;
	for(int i = 0; i < edges.size(); i++) {
		rowmap[edges[i][0]].push_back(i);
		colmap[edges[i][1]].push_back(i);
	}
    
    // Union each stone ID with all other stone IDs in the same row or in the same column.
	for(int i = 0; i < edges.size(); i++) {
		for(int j : rowmap[edges[i][0]]) unite(i, j);
		for(int j : colmap[edges[i][1]]) unite(i, j);
	}

    // Each connected group can have all but one stone removed. 
    // Thus, we count the number of unique groups and subtract
    // this from the total number of stones to get our answer.
    // Counting number of representatives is same as counting number of sets/components
    int ans = 0;
    for(int i=0; i<n; i++){
        if (  link[i] == i ){
            ans++;
        }
    }
    
    cout << n - ans;
}