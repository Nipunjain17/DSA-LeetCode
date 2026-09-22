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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head)return NULL;

        ListNode* dummy = new ListNode(0);
        dummy->next = head; 
        
        unordered_map<int, ListNode*> hmap;
        hmap[0] = dummy;
        int sum = 0;
        while(head != NULL){
            sum += head->val;

            if(hmap.find(sum) != hmap.end()){
                // found it
                ListNode* prev = hmap[sum];
                ListNode* start = prev;

                int p = sum;
                while(prev != head){
                    prev = prev->next;
                    p += prev->val;
                    if(prev != head)hmap.erase(p);
                }
                start->next = head->next;
            }
            else{
                hmap[sum] = head;
            }
            head = head->next;
        }
        return dummy->next;
    }
};