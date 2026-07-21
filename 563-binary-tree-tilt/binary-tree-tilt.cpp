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
    int solve(TreeNode* root, int &curr){
        if(root == NULL) return 0;

        int lefty = solve(root->left, curr);
        int righty = solve(root->right, curr);

        curr += abs(lefty - righty);
        return (root->val + lefty + righty);

    }
    int findTilt(TreeNode* root) {
        int curr = 0;
        int data = solve(root, curr);
        
        return curr;
    }
};