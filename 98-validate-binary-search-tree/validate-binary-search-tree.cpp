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
private:
    bool BST(TreeNode* root, long mini, long maxi){
        if(root == NULL) return true;
        if(root->val > mini && root->val < maxi){
            
            bool left = BST(root->left, mini, root->val);

            bool right = BST(root->right, root->val, maxi);
            
            if(left && right) return true;
        }

        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return BST(root, LONG_MIN, LONG_MAX);
    }
};