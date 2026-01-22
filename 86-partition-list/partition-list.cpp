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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* curr = head;
        if(curr->val < x){
            curr->next = partition(curr->next, x);
            return curr;
        }
        else{
            head = partition(curr->next, x);
            
            if(head == NULL){
                curr->next = NULL;
                return curr;
            }
            
            // Find the last node with value < x
            ListNode* temp = head;
            ListNode* prev = NULL;
            while(temp != NULL && temp->val < x){
                prev = temp;
                temp = temp->next;
            }
            
            // Insert current node after the last node < x
            if(prev == NULL){
                // All nodes are >= x, insert at beginning
                curr->next = head;
                return curr;
            }
            else{
                curr->next = prev->next;
                prev->next = curr;
                return head;
            }
        }
    }
};