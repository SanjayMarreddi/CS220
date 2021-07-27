#include <bits/stdc++.h>
using namespace std;

// Performs Topological sort if no cycle exists, else reports the presence of cycle.

list<int> result ;

// We use DFS approach.
// This is LESS efficent when compared to BFS. Use BFS.
bool DFS(int vertex,   vector < vector<int> > graph, vector<bool> &visited, vector<bool> &recursion_stack)
{   
    // Processing then node.
    visited[vertex] = true;
    recursion_stack[vertex] = true;
    
    // For all the children of the vertex.
    for (auto i : graph[vertex])
    {   
        // If a node is not visited, We check whether a cycle exists from the current node by doing DFS again. 
        if (!visited[i] && DFS(i, graph, visited, recursion_stack))
        {
            return true;
        }
        
        // If the node is visited, We will check if it is on recursion stack.
        else if (recursion_stack[i])
            return true;
    }
    
    // vertex is removed from stack as in usual DFS since all its children are already visited.
    recursion_stack[vertex] = false;
    result.push_front(vertex);
    // If no such cycle is found, return false.
    return false;
}

string check_cycle(  vector < vector<int> > graph, int len)
{
    vector<bool> visited(len, false);
    vector<bool> recursion_stack(len, false);
    
    // This loop helps incase of Disconnected Graphs.
    for (int i = 1; i < len; i++)
    {   if (!visited[i]){
            if (DFS(i, graph, visited, recursion_stack))
            {
                return "Yes";
            }
        }   
    }
    return "No";
}


int main()
{
    int n, source, dest;
    cin >> n;

    vector < vector<int> > adj_list(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> source;
        while (1)
        {
            cin >> dest;
            if (dest == -1)
                break;
            adj_list[source].push_back(dest);
        }
    }

    auto res = check_cycle(adj_list, n+1);
    if (res == "No" ){
            
        for (auto itr = result.begin();  itr != result.end() ; itr++){
            cout << *itr << " ";
        }   
    }
    else{
        cout << -1;
        // Since Cycle is present, Toplogical sort cant be found.
    }
    return 0;
}