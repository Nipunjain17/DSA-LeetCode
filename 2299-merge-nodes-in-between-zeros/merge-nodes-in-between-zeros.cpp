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

        ListNode* curr = head->next; // skips 1st zero
        ListNode* prev = head; // yaha se LL likhenge!!
        int total = 0;

        while(curr != NULL){
            if(curr->val == 0){
                prev->next = curr;
                prev = prev->next;
                prev->val = total;
                total = 0;
            }
            else{
                total += curr->val;
            }
            curr = curr->next;
        }
        prev->next = NULL;
        return head->next;
    }
};