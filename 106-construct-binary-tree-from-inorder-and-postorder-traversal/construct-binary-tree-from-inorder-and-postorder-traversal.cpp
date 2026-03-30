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
    void mapping (vector<int>inorder, int n, map<int, int>& nodeToIndex){
        for(int i=0; i<n; i++){
            nodeToIndex[inorder[i]] = i;
        }
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& index, int indexStart, int indexEnd, map<int, int>&nodeToIndex){
        if(index < 0 || indexStart > indexEnd){
            return NULL;
        }

        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int pos = nodeToIndex[element];

        // for right 
        root->right = solve(inorder, postorder, index, pos+1, indexEnd, nodeToIndex);

        // for left
        root->left = solve(inorder, postorder, index, indexStart, pos-1, nodeToIndex);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int index = n -1;

        map<int, int> nodeToIndex;
        mapping(inorder, n, nodeToIndex);
        TreeNode* ans = solve(inorder, postorder, index, 0, n-1, nodeToIndex);
        return ans;
    }
};