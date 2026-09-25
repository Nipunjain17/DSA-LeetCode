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
    int cnt = 0;
    
    void solve(TreeNode* root, long long  target){
        if(root == NULL) return;

        target = target - root->val;
        if(target == 0){
            cnt++;
        }
        solve(root->left, target);
        solve(root->right, target);
        return;
    }
    void helper(TreeNode* root, long long target){
        if(root == NULL) return;

        solve(root, target);

        helper(root->left, target);
        helper(root->right, target);
        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        helper(root, (long long)targetSum);
        return cnt;
    }
};