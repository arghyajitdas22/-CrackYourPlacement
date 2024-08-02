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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;

        while(temp != NULL) {
            temp = temp->next;
            count++;
        }     
        
        if(n == count) {
            head = head->next;
        }
        else {
            int nodeNumber = 1;
            temp = head;

            while(nodeNumber != (count - n)) {
                temp = temp->next;
                nodeNumber++;
            }

            temp->next = temp->next->next;
        }

        return head;
    }
};