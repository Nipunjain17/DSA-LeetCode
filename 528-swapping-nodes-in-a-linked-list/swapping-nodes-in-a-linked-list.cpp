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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* prev = head;
        int n = 0;
        while(prev != NULL && prev->next != NULL){
            prev = prev->next;
            n++;
        }

        prev = head;
        for(int i=1; i<k; i++){
            prev = prev->next;
        }

        ListNode* curr = head;
        for(int i=0; i<n-k+1; i++){
            curr = curr->next;
        }

        swap(prev->val,curr->val);
        return head;
    }
};