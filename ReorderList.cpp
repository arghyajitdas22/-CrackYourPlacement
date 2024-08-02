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
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;
        while(temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int start = 0, end = arr.size() - 1;
        temp = head;
        while(start < end) {
            temp->val = arr[start++];
            temp = temp->next;
            temp->val = arr[end--];
            temp = temp->next;
        }
        if(start == end) temp->val = arr[start]; 
    }
};