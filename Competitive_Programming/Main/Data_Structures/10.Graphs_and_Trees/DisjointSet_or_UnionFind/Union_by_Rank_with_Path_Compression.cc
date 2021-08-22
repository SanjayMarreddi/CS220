#include <bits/stdc++.h>
using namespace std;

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

    // Start custom code to unite as needed. 
  
    for(auto e : edges){
        if (comp_find(e[0]) != comp_find(e[1])){
            unite(e[0], e[1]);
        }
        else{
            // Do something.
        }
    }

    // Counting number of representatives is same as counting number of sets/components
    int comp = 0;
    for(int i=0; i<n; i++){
        comp += (  link[i] == i ? 1 : 0);
    } 
}