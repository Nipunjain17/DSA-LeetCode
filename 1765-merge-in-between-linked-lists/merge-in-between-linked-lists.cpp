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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev = list1;
        ListNode* curr = list1;
        for(int i=0; i<a; i++){
            prev = curr;
            curr = curr->next;
        }
        prev->next = list2;
        while(list2->next != NULL){
            list2 = list2->next;
        }
        
        for(int i=0; i<=b-a; i++){
            curr = curr->next;
        }
        list2->next = curr;

        return list1;
    }
};