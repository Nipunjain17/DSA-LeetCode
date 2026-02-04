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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;

        while(head != NULL){
            arr.push_back(head->val);
            head = head->next;
        }

        int n = arr.size();
        stack<int> st;
        st.push(arr[n-1]);
        vector<int> ans(n,0);

        for(int i=n-2; i>=0; i--){
            int curr = arr[i];

            while(!st.empty() && curr >= st.top()) st.pop();

            if(st.empty()) ans[i] = 0;
            else ans[i] = st.top();

            st.push(curr);
        }
        return ans;
    }
};