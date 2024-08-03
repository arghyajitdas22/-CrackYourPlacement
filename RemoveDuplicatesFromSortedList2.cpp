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
        map<int, int> mp;
        while(head) {
            mp[head->val]++;
            head = head->next;
        }

        ListNode* newHead = new ListNode();
        ListNode* temp = newHead;

        for(auto it: mp) {
            int val = it.first;
            int cnt = it.second;
            if(cnt == 1) {
                ListNode* newNode = new ListNode(val);
                temp->next = newNode;
                temp = temp->next;
            }
        }

        return newHead->next;
    }
};