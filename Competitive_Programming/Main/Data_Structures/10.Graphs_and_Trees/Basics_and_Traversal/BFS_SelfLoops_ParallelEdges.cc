class Solution {
    
    // https://leetcode.com/problems/shortest-path-with-alternating-colors/submissions/

   /* 
   A good graph model makes your life easier.
   
    Each node in the original graph breaks up into two nodes. And we color one with red and the other with blue.
    Red node: a red edge arrives at this node. Blue node: a blue edge arrives.
    Red node has only blue edges leaving it, and blue node the opposite
    
    Then we need to do two rounds of BFS: first start from red 0 node, second from blue 0 node.
   */ 
    
    vector<vector<int>> adjlist;
    vector<int> dist;
    
    void buildGraphEdges(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        adjlist.resize(2*n, vector<int>());
        
        // Red nodes are EVEN numbered & Blue nodes are ODD numbered.
        for (auto e: red_edges) {  // Red edges start from blue node & arrive to red node.
            adjlist[e[0] * 2 + 1].push_back(e[1] * 2 + 0);
        }
        for (auto e: blue_edges) { // Blue edges start from red node & arrive to blue node.
            adjlist[e[0] * 2 + 0].push_back(e[1] * 2 + 1);
        }
    }
     
    // Since there could be self-edges or parallel edges in the graph, We are using a slightly different BFS to deal with.
    // Ref: https://leetcode.com/problems/shortest-path-with-alternating-colors/discuss/340048/A-good-graph-model-makes-your-life-easier.
    
     void bfs(int n, int startNode) {
            queue<int> bfsQ;
            bfsQ.push(startNode);
            vector<bool> inQ(2*n, false);
            inQ[startNode] = true;
            int count = 0;
            while (!bfsQ.empty()) {
                int size = bfsQ.size();
                // We are iterating/using up all the CURRENT elements in the queue before incrementing `count`.
                for (int i = 0; i < size; ++i) {
                    int node = bfsQ.front(); bfsQ.pop();
                    dist[node/2] = min(dist[node/2], count);
                    for (auto next: adjlist[node]) {
                        if (!inQ[next]) {
                            bfsQ.push(next);
                            inQ[next] = true;
                        }
                    }
                }
                count ++;
            }
        }
    
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        buildGraphEdges(n, red_edges, blue_edges);
        dist.resize(n, INT_MAX);
        dist[0] = 0;
        bfs(n, 0); // Red colored start node  `0  -> 2*0 + 0` 
        bfs(n, 1); // Blue colored start node `0  -> 2*0 + 1` 
        for(int i = 0; i<n; i++){
            if (dist[i] == INT_MAX) dist[i] = -1;}
        return dist;
    }
};