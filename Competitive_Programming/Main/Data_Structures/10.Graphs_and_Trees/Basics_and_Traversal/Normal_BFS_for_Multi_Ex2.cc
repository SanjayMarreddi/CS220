/*
You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). 
You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the 
cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, 
and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance.
An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/submissions/

*/

class Solution {
public:
    
     bool is_valid(int i, int j, int m, int n){
            return ( i >= 0 and i < m and j >=0 and j < n);
    }

    vector<int> answers;

    void BFS( int m, int n, int x, int y, vector<vector<char>>& maze  ){
        
        vector<vector<int>> shortest(m+1, vector<int>(n+1, INT_MAX));
        queue<vector<int>> q;
        q.push({x,y});
        shortest[x][y] = 0;
    
        while(!q.empty()){
            
            int currx = q.front()[0], curry = q.front()[1]; q.pop();
            
             // If we reached the border (i.e EXIT )
            if ( currx == 0 or currx == m-1 or curry == 0 or curry == n-1 ) {
                if (shortest[currx][curry]) // This avoids the case where exit & entrance are same.
                    answers.push_back(shortest[currx][curry]);
            }

            if ( is_valid(currx+1,curry, m, n) and maze[currx+1][curry] != '+'  ){
                
                if (shortest[currx+1][curry] > shortest[currx][curry] + 1){
                      shortest[currx+1][curry] = shortest[currx][curry] + 1;
                      q.push({ currx+1, curry});
                }
                
            }
            
               if ( is_valid(currx,curry+1, m, n) and maze[currx][curry+1] != '+'  ){
                   
                      if (shortest[currx][curry+1] > shortest[currx][curry] + 1){
                        shortest[currx][curry+1] = shortest[currx][curry] + 1;
                        q.push({ currx, curry+1 });
                      }
                }
            
               if ( is_valid(currx-1,curry, m, n) and maze[currx-1][curry] != '+'  ){
                   
                      if (shortest[currx-1][curry] > shortest[currx][curry] + 1){
                          shortest[currx-1][curry] = shortest[currx][curry] + 1;
                            q.push({ currx-1, curry });
                      }
            }
            
               if ( is_valid(currx,curry-1, m, n) and maze[currx][curry-1] != '+' ){
                   
                      if (shortest[currx][curry-1] > shortest[currx][curry] + 1){
                          shortest[currx][curry-1] = shortest[currx][curry] + 1;
                          q.push({ currx, curry-1 });
                      }
            }
            
 
        }
                
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(); int n = maze[0].size();
        int x = entrance[0]; int y =  entrance[1];
        BFS(m, n, x, y, maze);
        sort(answers.begin(), answers.end());
        if (answers.size() == 0){ return -1;}
        else {return answers[0];} 
    }
    
};