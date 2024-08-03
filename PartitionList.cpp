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
    ListNode* partition(ListNode* head, int x) {
        vector<int> arr1, arr2;
        ListNode* temp = head;
        while(temp) {
            if(temp->val < x) arr1.push_back(temp->val);
            else arr2.push_back(temp->val);
            temp = temp->next;
        }

        temp = head;
        int i=0, n = arr1.size(), m = arr2.size();
        while(temp) {
            if(i < n) temp->val = arr1[i];
            else temp->val = arr2[i-n];
            temp = temp->next;
            i++;
        }

        return head;
    }
};