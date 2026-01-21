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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev; 
    }
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        ListNode* dummy = new ListNode(0);
        ListNode* result = dummy;
        int carry = 0;
        while(head != NULL){
            int total = head->val * 2 + carry;
            result->next = new ListNode(total % 10);
            carry = total / 10;
            result = result->next;
            head = head->next;
        }

        if(carry){
            result->next = new ListNode(carry);
        }

        head = reverseList(dummy->next);

        return head;
    }
};