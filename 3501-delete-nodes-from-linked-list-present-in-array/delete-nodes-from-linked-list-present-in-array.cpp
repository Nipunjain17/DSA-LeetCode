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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        // Store the element of nums in unordered_set 
        unordered_set<int> freq(nums.begin(), nums.end());

        ListNode* dummy = new ListNode (-99999);
        dummy->next = head;

        ListNode* curr = dummy;

        while(curr->next != NULL){
            if(freq.count(curr->next->val)){
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};