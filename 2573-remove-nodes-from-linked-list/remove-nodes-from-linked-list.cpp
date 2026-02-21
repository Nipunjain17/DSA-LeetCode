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
private:
    ListNode* ReverseTheLL(ListNode* head){
        // Reverse the list
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
public:
    ListNode* removeNodes(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        head = ReverseTheLL(head);
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr != NULL){
            if(prev->val <= curr->val){
                prev = curr;
            }
            else{
                prev->next = curr->next;
            }
            curr = curr->next;
        }
        head = ReverseTheLL(head);
        return head;
    }
};