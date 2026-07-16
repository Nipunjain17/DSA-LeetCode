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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == NULL) return root;
        if(depth == 1){
            TreeNode* value = new TreeNode(val);
            value->left = root;
            return value;
        }

        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            count++;
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(count +1 != depth){
                    if(curr->left){
                        q.push(curr->left);
                    }

                    if(curr->right){
                        q.push(curr->right);
                    }
                }
                else{
                    TreeNode* val1 = new TreeNode(val);
                    val1->left = curr->left;
                    curr->left = val1;

                    TreeNode* val2 = new TreeNode(val);
                    val2->right = curr->right;
                    curr->right = val2;
                }
            }
        }
        return root;
    }
};