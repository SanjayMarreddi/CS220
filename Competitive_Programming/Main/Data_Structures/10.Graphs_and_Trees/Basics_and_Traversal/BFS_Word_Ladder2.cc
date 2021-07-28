// https://leetcode.com/problems/word-ladder-ii/

// This has some tricky Implementation of BFS. We remove all the elements at the current level from the Queue before moving on to next level.
// It is some what similar to implemenatation in `\10.Graphs_and_Trees\Basics_and_Traversal\BFS_SelfLoops_ParallelEdges.cc`
// Just that we are using `level, minLevel` explicitly.

// Ref:
// https://leetcode.com/problems/word-ladder-ii/discuss/40434/C%2B%2B-solution-using-standard-BFS-method-no-DFS-or-backtracking
// https://leetcode.com/problems/word-ladder-ii/discuss/40434/C++-solution-using-standard-BFS-method-no-DFS-or-backtracking/812423

class Solution {

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        // Storing words in set makes it easy to searching and erasing.
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        if (wordSet.find(endWord) == wordSet.end())
            return {};
        
        //It can be solved with standard BFS. The tricky idea is doing BFS of paths instead of words!
        //Then the queue becomes a queue of paths.
        vector<vector<string>> ans;
        
        queue<vector<string>> paths;
        paths.push({beginWord});
        
        int level = 1;
        int minLevel = INT_MAX;
        
        //"visited" records all the visited nodes on this level
        //these words will never be visited again after this level 
        //and should be removed from wordSet. This is guaranteed
        // by the shortest path.
        unordered_set<string> visited; 
        
        while (!paths.empty()) {
            
            vector<string> path = paths.front();
            paths.pop();
            if (path.size() > level) {
                //reach a new level
                for (string w : visited) wordSet.erase(w);
                visited.clear();
                if (path.size() > minLevel)
                    break;
                else
                    level = path.size();
                
            }
            string last = path.back();
            
            //find next words in wordSet by changing
            //each element from 'a' to 'z'
            for (int i = 0; i < last.size(); ++i) {
                string news = last;
                for (char c = 'a'; c <= 'z'; ++c) {
                    news[i] = c;
                    if (wordSet.find(news) != wordSet.end()) {
                    //next word is in wordSet
                    //append this word to path
                    //path will be reused in the loop
                    //so copy a new path
                        vector<string> newpath = path;
                        newpath.push_back(news);
                        visited.insert(news);
                        if (news == endWord) {
                            minLevel = level;
                            ans.push_back(newpath);
                        }
                        else
                            paths.push(newpath);
                    }
                }
            }
        }
        return ans;
    }
};