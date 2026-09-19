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
    long mini = LONG_MAX, mini2 = LONG_MAX;
    void inorder(TreeNode* root){
        if(!root) return;

        inorder(root->left);
        
        if(root->val < mini){
            mini2 = mini;
            mini = root->val;
        }
        else if(root->val > mini && root->val <  mini2){
            mini2 = root->val;
        }
        inorder(root->right);
        return;
    }
    int findSecondMinimumValue(TreeNode* root) {
        inorder(root);
        return (mini2 == LONG_MAX)?-1 : mini2;
    }
};