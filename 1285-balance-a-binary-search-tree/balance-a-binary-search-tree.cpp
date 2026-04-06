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
    void InorderTraversal(TreeNode* root, vector<int>& in){
        if(root == NULL){
            return ;
        }

        InorderTraversal(root->left, in);
        in.push_back(root->val);
        InorderTraversal(root->right, in);

        return;
    }
    TreeNode* balanced(vector<int>& in, int left, int right){
        if(left > right){
            return NULL;
        }
        int mid = left + (right - left)/2;
        TreeNode* root = new TreeNode(in[mid]);
        root->left = balanced(in, left, mid-1);
        root->right = balanced(in, mid+1, right);

        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        InorderTraversal(root, in);

        return balanced(in, 0, in.size()-1);
    }
};