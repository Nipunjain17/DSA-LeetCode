/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* createBST(ListNode* head){
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return new TreeNode(head->val);
        }

        ListNode* slow = head, *fast = head, *prev = NULL;
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;

        // Creation of Node
        TreeNode* root = new TreeNode(slow->val);

        // recurrsively built left and right Subtree
        root->left = createBST(head);
        root->right = createBST(slow->next);
        
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = createBST(head);
        return root;
    }
};