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
    ListNode* sortList(ListNode* head) {
        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;

        vector<int> arr;
        while(head) {
            arr.push_back(head->val);
            head = head->next;
        }

        sort(arr.begin(), arr.end());

        for(int i=0; i<arr.size(); i++) {
            ListNode* newNode = new ListNode(arr[i]);
            temp->next = newNode;
            temp = temp->next;
        }

        newHead = newHead->next;
        return newHead;
    }
};