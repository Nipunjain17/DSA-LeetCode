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
class Solution {
public:
    int pairSum(ListNode* head) {
    
        // find the half fo LL
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = NULL;
        // reverse the second half of the linked list
        while(slow != NULL){
            ListNode* forward = slow->next;
            slow->next = prev;
            prev = slow;
            slow = forward;  
        }
        int max_val = INT_MIN;
        while(prev != NULL){
            int val = head->val + prev->val;
            max_val = max(val,max_val);

            head = head->next;
            prev = prev->next;
        }
        return max_val;
    }
};