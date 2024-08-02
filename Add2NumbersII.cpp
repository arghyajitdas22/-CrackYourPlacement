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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> num1, num2;
        while(l1) {
            num1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            num2.push_back(l2->val);
            l2 = l2->next;
        }

        int p1 = num1.size() - 1, p2 = num2.size() - 1, carry = 0;
        stack<int> res;
        while(p1 >= 0 && p2 >= 0) {
            int add = num1[p1--] + num2[p2--] + carry;
            res.push(add % 10);
            carry = add / 10;
        }
        while(p1 >= 0) {
            int add = num1[p1--] + carry;
            res.push(add % 10);
            carry = add / 10;
        }
        while(p2 >= 0) {
            int add = num2[p2--] + carry;
            res.push(add % 10);
            carry = add / 10;
        }
        if(carry > 0) res.push(carry);

        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;
        while(!res.empty()) {
            ListNode* newNode = new ListNode(res.top());
            res.pop(); 
            temp->next = newNode;
            temp = temp->next;
        }

        return newHead->next;
    }
};