// OJ : https://leetcode.com/problems/delete-duplicate-folders-in-system/
// Ref: https://leetcode.com/problems/delete-duplicate-folders-in-system/discuss/1360768/C%2B%2B-Tree-building-and-trimming

/* 
Idea:

Build Tree: Build a folder tree based on the paths. The process is similar to the Trie building process.
Dedupe: Use post-order traversal to visit all the nodes. If we've seen the subfolder structure before, mark the node as deleted.
Generate Paths: DFS to generate the output. We skip the nodes that have been deleted.
*/

struct Node {
    string name;
    
    // mapping from folder name to the corresponding child node.
    map<string, Node*> next;
    
    // whether this folder is deleted.
    bool del = false;        
    
    Node(string n = ""){ name = n; }
};

class Solution {
    
    // Given a path, add nodes to the folder tree. This is similar to the Trie build process.
    void addPath(Node *node, vector<string> &path) { 
        for (auto &s : path) {
            if (node->next.count(s) == 0) node->next[s] = new Node(s);
            node = node->next[s];
        }
    }
    
    // mapping from subfolder structure string to the first occurrence node.
    unordered_map<string, Node*> seen; 
    
    // post-order traversal to dedupe. If we've seen the subfolder structure before, mark it as deleted.
    string dedupe(Node *node) { 
        
        string subfolder;
        for (auto &[name, next] : node->next) {
            subfolder += dedupe(next);
        }
        
         // leaf nodes should be ignored
        if (subfolder.size()) {
            
            // if we've seen this subfolder structure before, mark them as deleted.
            if (seen.count(subfolder)) {
                seen[subfolder]->del = node->del = true;
            } 
            // otherwise, add the mapping
            else {
                seen[subfolder] = node; 
            }
        }
        
        // return the folder structure string of this node.
        return "(" + node->name + subfolder + ")"; 
    }
    
    
    vector<vector<string>> ans;
    
    // To store the path during DFS.
    vector<string> path;
    
    void getPath(Node *node) {
        
        // if the current node is deleted, skip it.
        if (node->del) return; 
        
        path.push_back(node->name);
        ans.push_back(path);
        
        for (auto &[name, next] : node->next) {
            getPath(next);
        }
        
        // Saving the paths is like `BackTracking` since we are doing DFS.
        path.pop_back();
    }
    
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node root;
        for (auto &path : paths) addPath(&root, path);
        dedupe(&root);
        for (auto &[name, next] : root.next) getPath(next);
        return ans;
    }
};