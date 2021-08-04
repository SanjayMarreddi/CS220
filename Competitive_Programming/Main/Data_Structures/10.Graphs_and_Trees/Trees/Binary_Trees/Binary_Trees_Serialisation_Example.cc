/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// https://leetcode.com/problems/find-duplicate-subtrees/

class Solution {
    
    // Ref: https://leetcode.com/problems/find-duplicate-subtrees/discuss/106055/C%2B%2B-Java-Clean-Code-with-Explanation
    
    string serialise(TreeNode* root, unordered_map<string, vector<TreeNode*>>  &store){
        string s = "";
        if (!root) return s;
        s = '(' + serialise(root->left, store) + to_string(root->val) + serialise(root->right, store) + ')';
        store[s].push_back(root);
        return s; 
    }
    
    
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector<TreeNode*> ans;
        // store has mapping from each unique serialisation (string) of subtrees to 
        // all the nodes that have this string for their subtree. 
        
        unordered_map<string, vector<TreeNode*>> store;
        
        serialise(root, store);
        for(auto each : store){
            // If it appears more than once, push the root.
            if (each.second.size() > 1){ 
                ans.push_back(each.second[0]);
            }
        }
        return ans;
    }
};