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
    ListNode* middleNode(ListNode* head) {
        ListNode* ans = head;
        if(head->next == NULL) return ans;

        ListNode* last = head->next->next;
        while(last) {
            ans = ans->next;
            if(!last->next) break;
            last = last->next->next;
        }

        if(!last) ans = ans->next;

        return ans;
    }
};