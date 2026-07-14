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
    TreeNode* head = NULL;
    TreeNode* prev = NULL;

    void Inorder(TreeNode* root){
        if(!root) return;

        Inorder(root->left);
        
        root->left = NULL;
        if(prev == NULL){
            head = root;
        }
        else{
            prev->right = root;
        }
        prev = root;

        Inorder(root->right);
        return;
    }

    TreeNode* increasingBST(TreeNode* root) {
        Inorder(root);

        if(prev) prev->right = NULL;
        return head;
    }
};