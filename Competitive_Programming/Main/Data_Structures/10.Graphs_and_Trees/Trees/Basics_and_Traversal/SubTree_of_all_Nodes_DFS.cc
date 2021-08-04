// Given n nodes of a tree and their connections, print Subtree nodes of every node. 
// Subtree of a node is defined as a tree which is a child of a node. 

#include<bits/stdc++.h>
using namespace std;

int start[100001];  // start[i] denotes the counter where DFS started processing the node `i`.
int endd[100001];   // endd[i] denotes the counter where DFS processing of the node `i` is finished.

vector<int> dfs_order;
vector<int> adj[100001];
int visited[100001];

// Recursive function for dfs traversal
void dfs(int a, int &counter){

	visited[a] = 1;
    dfs_order.push_back(a);

    // Started processing the node `a`
	counter++; start[a] = counter;

	for( auto child : adj[a]){
		if(!visited[child]){
			dfs(child, counter);
		}
	}

    // The node `a` is processed fully ( All the elements in its subtree are visited. )
	endd[a] = counter;
}

// Function to print the subtree nodes
void Print(int n){
	for(int i = 0; i < n; i++){
        
		// if node is leaf node, start[i] is equals to endd[i]
		if ( start[i] != endd[i] ){
            
            // For each node, we know the indices which indicate the index where the node is started processing (start[i]) & 
            // where the node is completely processed (end[i]). All the elements in this range in the DFS order are the elements 
            // that belong to subtree of node `i`.

			cout << "Subtree of node " << i << " is ";
			for( int j = start[i]; j <= endd[i]; j++ ){

                // Notice the (j-1) here since vectors are `0` indexed :)
				cout << dfs_order[j-1] << " ";
			}

			cout << endl;
		}
        else{
            cout << "Subtree of node " << i << " is " << i << " " << endl;
        }
	}
}

int main(){
	// No of nodes n = 10
	int n = 10, counter = 0;

    // Since Tree is an undirected graph
	adj[0] = {1,2,3};
	adj[1] = {4,5,0};
    adj[4] = {1,7,8};
    adj[2] = {6,0};
    adj[6] = {2,9};
    adj[3] = {0};
    adj[5] = {1};
    adj[7] = {4};
    adj[8] = {4};
    adj[9] = {6};
    
    // Rooting the tree at node 0 & performing DFS.
    // If we root the tree at different node, the answer adapts accordingly.
	dfs(0, counter);

	// Print Subtree nodes for each node.
	Print(n);
	return 0;
}
