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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m,vector<int>(n,-1));
        ListNode* curr = head;
        int total = n*m;
        int count = 0;

        int startingCol = 0, endingCol = n-1;
        int startingRow = 0, endingRow = m-1;
        while(curr != NULL && count < total){
            // Print Starting Row
            for(int index=startingCol; curr != NULL && count < total && index<=endingCol; index++){
                matrix[startingRow][index] = curr->val;
                curr = curr->next;
                count++;
            }
            startingRow++;
            
            // Printing Ending Column
            for(int index=startingRow; curr != NULL && count < total && index<=endingRow; index++){
                matrix[index][endingCol] = curr->val;
                curr = curr->next;
                count++;
            }
            endingCol--;
            
            // Printing Ending Row
            for(int index=endingCol; curr != NULL && count < total && index>=startingCol; index--){
                matrix[endingRow][index] = curr->val;
                curr = curr->next;
                count++;
            }
            endingRow--;
            
            //Print Starting Column
            for(int index=endingRow; curr != NULL && count < total && index>=startingRow; index--){
                matrix[index][startingCol] = curr->val;
                curr = curr->next;
                count++;
            }
            startingCol++;
        } 
        return matrix;
    }
};