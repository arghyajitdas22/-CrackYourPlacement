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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftNode = head;
        ListNode* temp = head;
        vector<int> arr;

        int pos = 1;
        while(pos <= right) {
            if(pos == left) leftNode = temp;
            if(pos >= left) arr.push_back(temp->val);
            pos++;
            temp = temp->next;
        }

        reverse(arr.begin(), arr.end());
        temp = leftNode;
        for(int it: arr) {
            temp->val = it;
            temp = temp->next;
        }

        return head;
    }
};