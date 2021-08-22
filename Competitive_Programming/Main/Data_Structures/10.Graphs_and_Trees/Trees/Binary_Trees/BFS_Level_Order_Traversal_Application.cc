/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    
 // OJ: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
 // A simple BFS level order traversal would be suffice.
 // A BFS approach will allow us to keep track of every level. 
 // Start by populating the next pointers of the nodes present in that level until the last node of that level.

public:
    
    Node* connect(Node* root) {
        
            if(!root)
                return NULL;
        
            queue<Node*>q;
            q.push(root);
        
            while(!q.empty()){
                
                int size = q.size();
                
                // This while loop makes it BFS LEVEL ORDER traversal. It helps us in traversing all elements at current level once.
                while(size--){
                    
                    Node* temp = q.front(); q.pop();
                    
                    // This helps in connecting as per the question given.
                    if(size!=0)temp->next = q.front();
                    else temp->next=NULL;
                    
                    // The below 4 lines are same as LEVEL ORDER TRAVERSAL.
                    if(temp->left)
                        q.push(temp->left);
                    if(temp->right)
                        q.push(temp->right);

                }

            }
        
            return root;
    }
};