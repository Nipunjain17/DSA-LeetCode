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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* curr = head;
        int cnt = 0;
        while(curr != NULL){
            cnt++;
            curr = curr->next;
        }
        if(cnt == 1){
            head = NULL;
            return head;
        }
        int mid;
        if(cnt%2 == 0) mid = cnt/2 + 1;
        else mid = (cnt + 1)/2;

        cnt = 0;
        ListNode* prev = NULL;
        curr = head;
        while(cnt < mid-1){
            cnt++;
            prev = curr;
            curr = curr->next;
        }
        if(curr == NULL){
            prev->next = NULL;
        }
        else{
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }    
        return head;
    }
};