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
    int getDecimalValue(ListNode* head) {
       vector<int> num;
       while(head) {
        num.push_back(head->val);
        head = head-> next;
       }

       int n = num.size(), ans = 0;
       for(int i=n-1; i>=0; i--) {
        ans += num[i] * int(pow(2, n-1-i));
       }

       return ans;
    }
};