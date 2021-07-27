/*
Topological Sort on DAG using DFS :
Given N vertices along with edges of a directed acyclic graph, write a program to implement topological sort using DFS.
Note: Iterate over the adjacency list similar to standard DFS (retain the input order and iterate left to right within it).
Input:
First line contains a single integer N.
Each of the next N lines contains space separated integers.
In each line, the first integer has an edge with all the following integers (if they exist) except last one. -1 at the end represents end of line.
Output:
Print space separated integers representing topological order.
*/

#include <bits/stdc++.h>
using namespace std;

list<int> result ;

// We need Stack Functionality
// This is LESS efficent when compared to BFS. Use BFS.
void DFS(int vertex, vector< vector<int> > adj_list , vector<bool> &visited, list<int> &result)
{
    visited[vertex] = true;
    for (auto i : adj_list[vertex])
    {
        if (!visited[i])
        {
            DFS(i, adj_list, visited, result);
        }
    }

    // Notice that we are pushing the nodes after completion of processing.
    result.push_front(vertex);
}



void topological_sort_DFS(   vector< vector<int> > &adj_list, vector<bool> &visited){
   
    for (int i = 1; i < visited.size() ; i++){
        if (visited[i] == false){
            DFS(i, adj_list, visited, result);
        }
    }
}

int main()
{
    int n, source, destination;
    cin >> n;

    // Since the vertices values range from 1 to n, we need `n+1` array size
    vector< vector<int> > adj_list(n + 1); 

    for (int i = 0; i < n; i++)
    {
        cin >> source;
        while (1)
        {
            cin >> destination;
            if (destination == -1)
                break;
            adj_list[source].push_back(destination);
        }
    }
    
    // Creates a vector of size n+1 with all values defaulted as `false`.
    vector<bool> visited(n + 1, false);
    
    topological_sort_DFS(adj_list, visited);
    
    for (auto itr = result.begin();  itr != result.end() ; itr++){
        cout << *itr << " ";
    }
    
    return 0;
}