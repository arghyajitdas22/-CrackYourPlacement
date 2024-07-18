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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        while(curr1 && curr2) {
            if(curr1->val <= curr2->val) {
                temp->next = curr1;
                curr1 = curr1->next;
                temp = temp->next;
            }
            else if(curr2->val < curr1->val) {
                temp->next = curr2;
                curr2 = curr2->next;
                temp = temp->next;
            }
        }

        while(curr1) {
            temp->next = curr1;
            curr1 = curr1->next;
            temp = temp->next;
        }

        while(curr2) {
            temp->next = curr2;
            curr2 = curr2->next;
            temp = temp->next;
        }

        head = head->next;
        return head;
    }
};