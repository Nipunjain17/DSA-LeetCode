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
    ListNode* midLL(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* right){
        ListNode* prev = NULL;
        ListNode* curr = right;
        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head->next == NULL) return true;
        ListNode* mid = midLL(head);

        ListNode* left = head;
        ListNode* right = mid->next;
        // Breaking LL into two parts
        mid->next = NULL;

        // reverse the right part of LL
        right = reverse(right);

        while(left != NULL && right != NULL){
            if(left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};