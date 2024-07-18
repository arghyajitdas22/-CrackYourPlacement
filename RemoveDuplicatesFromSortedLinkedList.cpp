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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        
        ListNode *curr1 = head;
        ListNode *curr2 = head;

        while(curr2) {
            if(curr1->val == curr2->val) {
                curr1->next = curr2->next;
                curr2 = curr2->next;
            }
            else curr1 = curr2;
        }

        return head;
    }
};