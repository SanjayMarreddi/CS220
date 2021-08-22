/*
OJ : https://leetcode.com/problems/bricks-falling-when-hit/
Ref: https://leetcode.com/problems/bricks-falling-when-hit/discuss/1391613/C%2B%2B-DSU-Code-and-Explaination

Let n = r*c

Observations::
1) A brick is stable if it is part of a connected component which has atleast one element touching the top

Brute Force
- When we hit a brick. A chain process starts. Where bricks becoming unstable starts to fall 
    - For each hit. We run DFS or use DSU to find connected components (ones which have atleast one top row brick) 
    - It will take O(q*r*c) => 16 * 10^8 -> 1.6*19^9 =>TLE 


Note: We have to construct the DSU again & again, because going forward (i.e. hitting a brick), needs to remove element from connected components... but DSU only supports the Union operation

This gives us a hint. Going forward is removing operation ... so all operation from final state to initial state will be addition operations... so, can we do something with DSU and reverse traversal

Let's See:

    1) Remove all bricks which are in the hit array
    2) Construct DSU. Find stable bricks.
    3) For each hit point in reverse(hit array)
        1) Check if hit point is a stable position
        2) If hit point is not stable position, then it implies, when we come from forward ... there was no brick
        at hit position, thus no brick falls at this hit point
        3) If hit point is stable, then we check how many more bricks it will make stable from unstable. Let's say it  
        makes x number of bricks stable. Then going forward it will remove x+1 bricks.
            a) How to find, numbers of bricks which became stable.
                - We maintain a DSU, where some connected components will be stable... some unstable. We map a map of which connected components are unstable. 
                - for each hit point which is stable, we check its four neighbours, and if any of them is unstable we make
                it stable

*/



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

int n,m;
vector<int> dirs = {1,0,-1,0,1};

// The function `f` maps the (i,j) to a number that inturn makes us easy to represent each cell as Node in our Dijoint set data structure.
int f(int i, int j){return i*m+j;}    

bool is(int i, int j){ return i>=0 && j>=0 && i<n && j<m;}

class Solution {
public:
    
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        
        n = grid.size(), m = grid[0].size();
        int q = hits.size();
        
        UnionFind ds(n*m);
        unordered_map<int, bool> isstable;
        
        
        // Removing all erased bricks
        for(int i=0; i<q; ++i) 
            grid[hits[i][0]][hits[i][1]] -= 1; 
        
        
        // Now, we take the remaining grid after all erasures & update ds.
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                
                if ( grid[i][j]!=1 ) 
                    continue;
                
                // Finding all adjacent components with bricks.
                for(int it = 0; it<4; ++it){
                    int x = i+dirs[it], y=j+dirs[it+1];
                    if(is(x,y) && grid[x][y]==1) {
                        //generating connected components
                        ds.unite( f(i,j), f(x,y) );
                    } 
                }
            }
            
        }
        
        
        // All bricks in the top row (0) are stable. We mark the parent of those bricks as stable.
        for(int j=0; j<m; ++j){
            if(grid[0][j]==1) 
                isstable[ds.find(f(0,j))] = true; //marking stable components
        }
        
        vector<int> ans(q);
        
        // Itearting over each hit from end.
        for(int k=q-1; k>=0; --k){
            
            int i = hits[k][0], j = hits[k][1], flag = 0;
            
            // -1 indicates that initially there is no brick at the hit position, so number of bricks that fall is 0 (initialised already)
            if( grid[i][j]==-1 ) 
                continue;
            
            vector<int> unstable_neighbours;
            
            //checks whether hitting point is stable or not
            if ( i==0 )  // 1st row
                flag = 1;
            
            for(int it=0; it<4; ++it){  
                
                int x = i+dirs[it],y=j+dirs[it+1];
                
                //union the hitting point and its stable neighbour
                if(is(x,y) && (isstable.count(ds.find(f(x,y))))) {
                    flag = 1; 
                    ds.unite(f(x,y), f(i,j));
                }
                
                else if(is(x,y) && !(isstable.count(ds.find(f(x,y))))){
                    unstable_neighbours.push_back(f(x,y));
                }
            }
            
            
            //checking unstable neighbours
            int tans = 0;
            for(auto ngbh : unstable_neighbours){
                
                // Reconstructing the (x,y) coordinates that were mapped to int by function `f`.
                int x = ngbh/m, y = ngbh%m;
                
                // If these are not in same components.
                if (grid[x][y]==1 && ds.find(f(x,y))!=ds.find(f(i,j))){
                    
                    tans += ds.size[ds.find(f(x,y))];
                    
                    ds.unite(f(x,y),f(i,j)); 
                }
                
            }
            
            grid[i][j] = 1;
            
            // marking node as stable
            if(flag){
                ans[k] = tans;
                isstable[ds.find(f(i,j))] = true;
            }
            
        }
        
        return ans;
        
        
    }
};