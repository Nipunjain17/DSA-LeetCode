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

    void reorderList(ListNode* head) {

        ListNode* mid = midLL(head);
        // dive the list into parts
        ListNode* left = head;
        ListNode* right = mid->next;

        mid->next = NULL;

        // Reverse the right part of LL
        right = reverse(right);

        while(left != NULL && right != NULL){
            ListNode* nextLeft = left->next;
            ListNode* nextRight = right->next;

            left->next = right;
            right->next = nextLeft;

            left = nextLeft;
            right = nextRight;
        }
        head = left;
    }
};