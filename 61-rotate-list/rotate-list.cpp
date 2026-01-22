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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        int cnt = 1;

        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        
        k = k %cnt;

        if(k == 0){
            return head;
        }

        prev->next = NULL;
        curr->next = head; 


        head = rotateRight(curr,k-1);

        return head;
    }
};