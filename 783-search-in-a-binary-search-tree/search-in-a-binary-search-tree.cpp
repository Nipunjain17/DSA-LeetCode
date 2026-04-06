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
    TreeNode* search(TreeNode* root, int val){
        if(root == NULL){
            return NULL;
        }

        if(root->val == val){
            return root;
        }

        if(val < root->val){
            TreeNode* temp = search(root->left, val);
            return temp;
        }
        else{
            TreeNode* temp = search(root->right, val);
            return temp;
        }
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* find = search(root, val);

        return find;
    }
};