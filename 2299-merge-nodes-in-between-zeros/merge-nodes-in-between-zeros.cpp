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
    ListNode* mergeNodes(ListNode* head) {
        if(head == NULL) return head;

        while(head->val == 0){
            head = head->next;
        }

        ListNode* curr = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        int total = 0;
        while(curr != NULL){
            total += curr->val;
            if(curr->val == 0){
                curr->val = total;
                total = 0;
                prev->next = curr;
                prev = prev->next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};