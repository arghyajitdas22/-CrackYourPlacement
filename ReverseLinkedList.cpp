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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;

        ListNode* ans = head;
        ListNode* curr = head->next; 
        ans->next = NULL;

        while(curr) {
            ListNode* temp = curr;
            curr = curr->next;
            temp->next = ans;
            ans = temp;
        }

        return ans;
    }
};