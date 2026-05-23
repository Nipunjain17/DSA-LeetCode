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
    pair<int, int> maximizingLoot(TreeNode* root){
        if(root == NULL){
            pair<int, int> p = make_pair(0,0);
            return p;
        }
        // for left 
        pair<int, int> lefty = maximizingLoot(root->left);
        // for right
        pair<int, int> righty = maximizingLoot(root->right);

        pair<int, int> ans;
        // Rob the current node
        ans.first = root->val + lefty.second +  righty.second;
        
        // Do NOT rob current node
        ans.second = max(lefty.first, lefty.second) +max(righty.first, righty.second);

        return ans;
    }
    int rob(TreeNode* root) {
        pair<int, int> ans = maximizingLoot(root);
        int loot = max(ans.first, ans.second);
        return loot;
    }
};