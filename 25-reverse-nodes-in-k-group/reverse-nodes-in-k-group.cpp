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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;

        // step-1: Check if atleast k-node are present
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL && cnt < k){
            temp = temp->next;
            cnt++;
        }
        if (cnt < k) return head;

        // Step-2: Reverse first k node
        ListNode* forward = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        cnt = 0;
        while(curr != NULL && cnt < k){
            forward = curr->next;
            curr ->next = prev;
            prev = curr;
            curr = forward;
            cnt++;
        }

        // Step-3: Recurrsion can handle the rest problem 
        head->next = reverseKGroup(curr,k);

        return prev;
    }
};