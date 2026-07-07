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
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root || (!root->right && !root->left))return root;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            TreeNode* lefty = NULL, *righty = NULL;
            
            if(curr->left){
                q.push(curr->left);
                lefty = curr->left;
            }

            if(curr->right){
                q.push(curr->right);
                righty = curr->right;
            }

            curr->left = righty;
            curr->right = lefty;
        }

        return root;
    }
};