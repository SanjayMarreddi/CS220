/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    // We are performing PREORDER traversal along with Null, which means we also have LEVEL order info,
    // which is sifficient to reconstruct BT.
    string serialize(TreeNode* root) {
        
        if (root == NULL) return "null";
        
        // Here, we are keeping "," between left and right becoz,  becoz We need to keep track of Null nodes in BT
        // If left & right nodes are empty, String becomes "valnullnull".
        // So, In BT, we need extra comma between left & right to make it "val,null,null".
        
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        if (data == "null") return NULL;
        stringstream s(data);
        return makeDeserialize(s);
    }
    
    TreeNode* makeDeserialize(stringstream& s) {
        string str;
        getline(s, str, ',');
        if (str == "null") {
            return NULL;
        } else {
            TreeNode* root = new TreeNode(stoi(str));
            root->left = makeDeserialize(s);
            root->right = makeDeserialize(s);
            return root;
        }
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

