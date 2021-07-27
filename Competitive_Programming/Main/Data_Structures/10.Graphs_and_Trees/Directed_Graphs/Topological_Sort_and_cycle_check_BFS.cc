/* 

This implementation of Toplogical Sort by few modifications of BFS is called Kahn's Algorithm.

Implement Kahn's Algorithm :
Given N vertices along with edges of a directed graph, write a program to implement topological sort using Kahn's algorithm.
Note: The algorithm should be applied on the original adjacency list order (left to right).

Input :
First line contains a single integer N.
Each of the next N lines contains space separated integers.
In each line, the first integer has an edge with all the following integers (if they exist) except last one. -1 at the end represents end of line.

Output :
Print space separated integers representing topological order. Print -1, if graph contains a cycle. 

*/

#include <bits/stdc++.h>
using namespace std;

// Similar to BFS
// This is MORE efficent when compared to DFS.
void topological_sort( vector< vector<int> > &graph, int n) {

    vector<int> in_degree(n+1, 0), result;

    // If we need Lexicographically Smallest Topological Order, 
    // We use a MIN HEAP Priority Queue. `priority_queue<int,vector<int>, greater<int>> queue;`

    vector<bool> visited(n+1, false);
    queue<int> queue;
    int cycle_check=0;

    // store indegree of every vertex
    for (int i=1; i<=n; i++) {
        for (auto u : graph[i]) {
            in_degree[u]++;
        }
    }

    // push vertices with indegree 0 to queue
    for (int i=1; i<=n; i++) {
        if (in_degree[i]==0) {
            queue.push(i);
            visited[i] = true;
        }
    }

    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();
        result.push_back(vertex);   // We need to insert all the `n` values into the `result` vector if no cycle exists.

        // remove edge
        for (auto i : graph[vertex]) {

            if (!visited[i]){

                if (--in_degree[i] == 0) {
                    queue.push(i);
                    visited[i] = true;
                }

            }
          
        }
        cycle_check++;
    }
    
    // We know, If any element is not processed, It means we have a Cycle.
    if (cycle_check != n) {
        cout << "-1";
        return;
    }

    for (auto i : result)
        cout << i << " ";
    return;
}

int main()
{
    int n, source, destination;
    cin >> n;

    // Adjancency List representation of the graph.
    vector< vector<int> > graph( n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> source;
        while (1)
        {
            cin >> destination;
            if (destination == -1)
                break;
            graph[source].push_back(destination);
        }
    }

    topological_sort(graph, n);
    return 0;
}