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
    int ans = 0;
    int maxi = -1;
    void solve(TreeNode* root, int depth){
        if(root == NULL){
            return ;
        }

        if(maxi < depth){
            ans = root->val;
            maxi = depth;
        }

        solve(root->left, depth+1);
        solve(root->right, depth+1);

    }
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL){
            return -1;
        }
        solve(root, 0);
        return ans;
    }
};