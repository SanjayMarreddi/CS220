// https://leetcode.com/problems/binary-tree-inorder-traversal/

// The below code gives an Idea of how to deal with memory allocation when we need to return them as answers.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void traverse(struct TreeNode* root, int* arr, int* returnSize){
    if (root){
        traverse(root->left,arr,returnSize);
        arr[(*returnSize)++] = root->val;
        traverse(root->right,arr,returnSize);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    
    // Dynamically allocating space sufficient for storing all the elements
    int* arr = malloc(100*sizeof(int));
    
    // In C, we cant use & and do pass by reference. We need to use double pointers.
    *returnSize = 0;
    traverse(root,arr,returnSize);
    
    // But we need to return the req. sized dynamically allocated array only.
    arr = realloc(arr,(*returnSize)*sizeof(int));
    
    return arr;
}