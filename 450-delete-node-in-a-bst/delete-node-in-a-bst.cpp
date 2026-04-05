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
    int minValue(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        // 0-child case
        if(root->val == key){
            // for 0-child cas
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }

            // for 1-child
            // for left 
            if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // for right 
            if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // for 2-child case
            if(root->left != NULL && root->right){
                int mini = minValue(root->right);
                root->val = mini;
                root->right = deleteNode(root->right,mini);
                return root;
            }
        }
        else if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};