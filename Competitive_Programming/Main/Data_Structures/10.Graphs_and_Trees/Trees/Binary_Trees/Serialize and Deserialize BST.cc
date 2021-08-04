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
    string serialize(TreeNode* root) {
        return encode(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        // We just take values separated by ',' and insert them into BST in the same order.
        stringstream ss(data);
        string item;
        TreeNode* root = NULL;
        
        while (getline (ss, item, ',')) 
            root = insert(root, stoi(item));

        return root;
    }
    
private:
    
    // The Idea is that, 
    // we need to encode BST in PRE ORDER traversal, so that when we are inserting 
    // elements in the same order, we get exactly the same BST.
    string encode(TreeNode* root) {

        if (root == NULL) return "";
        
        // We are using comma(,) to separate the node values in Preorder traversal string.
        
        // Here, we are not keeping "," between left and right becoz,  We need not keep track of Null
        // nodes in BST since we can reconstruct BST by just the order in which elements are inserted. If elements are present anyhow they will be separated by ",".
        // If left & right nodes are empty, String becomes "val" in BST, But in BT it becomes "valnullnull".
        // So, In BT, we need extra comma between left & right to make it "val,null,null".
        
        return to_string(root->val) + "," + encode(root->left) + encode(root->right);
    }
    
    // This is exactly same as Insert used in BST.
    TreeNode* insert(TreeNode* root, int val) {
        if (root == NULL) {
			TreeNode* temp=new TreeNode(val);
			return temp;
		}
    
		if (val<=root->val)
			root->left=insert(root->left,val);
    
		else
			root->right=insert(root->right,val);
    
		return root;
    }
};
    

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;