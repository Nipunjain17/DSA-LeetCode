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
    void post(TreeNode* root, vector<int>&arr){
        if(root == NULL) return;
        post(root->left, arr);
        post(root->right, arr);
        arr.push_back(root->val);
        return;
    }    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        post(root, result);
        return result;
    }
};