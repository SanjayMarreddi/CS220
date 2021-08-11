#include <bits/stdc++.h>
using namespace std;

int n = 100, m = 100;
vector< vector <int> > edgeList;
vector<int> link(n+1), size(n+1,1); // Size should be Initialised with 1.

bool comp( vector<int>i, vector<int> j){
    return (i[2] < j[2]);
}


int find(int x) {
    while (x != link[x])
        x = link[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (size[a] < size[b]) 
        swap(a,b);

    size[a] += size[b];
    link[b] = a;
}

void MST_Kruskal(){

    // All the included edges are in this mst.
    vector<vector<int>> mst;

    for(int i = 0; i < m; i++){
        auto curr = edgeList[i]; int a = curr[0], b = curr[1];
        if (!same(a, b)){
            mst.push_back(curr);
            unite(a,b);
        }
    }
    cout << "\nThe Edges included in MST: \n";
    for(int i = 0; i < mst.size(); i++){
        cout << mst[i][0] << " "  << mst[i][1] << " " << mst[i][2] << "\n" ;
    }

}

int main(){
    cin >> n >> m ; 
    int no_of_edges = m;
    while(no_of_edges--){
        int start, end, w = 1;
        cin >> start >> end ; cin >> w;
        edgeList.push_back( { start, end, w } ); 
        // Note: Most of the algos that use the Edge List representation even directed or undirected,
        // we will treat it like Directed & add the edges to the list only once.
    }

    sort(edgeList.begin(), edgeList.end(), comp);

    for (int i = 1; i <= n; i++) 
        link[i] = i;

    MST_Kruskal();

    /*
    Sample Input from CP Book:
    6 8
    1 2 3
    1 5 5
    2 5 6
    2 3 5
    5 6 2
    3 6 3
    3 4 9
    6 4 7
    */

}