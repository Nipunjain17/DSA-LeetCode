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
    TreeNode* buildBST(TreeNode* root, int data){
        if(root == NULL){
            TreeNode* temp = new TreeNode(data);
            return temp;
        }

        if(root->val > data){
            root->left = buildBST(root->left, data);
            return root;
        }
        else{
            root->right = buildBST(root->right, data);
            return root;
        }
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1; i<preorder.size(); i++){
            root = buildBST(root, preorder[i]);
        }

        return root;
    }
};