/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    void solve(Node* &head, Node* &last) {
        if(!head) return;
        if(!head->next && !head->child) {
            last = head;
            return;
        }

        if(head->child) {
            solve(head->child, last);
            if(head->next) head->next->prev = last;
            last->next = head->next;
            head->next = head->child;
            head->child->prev = head;
            head->child = NULL;
            solve(last->next, last);
        } 
        else solve(head->next, last);
    }
public:
    Node* flatten(Node* head) {
        Node* lastNode = NULL;
        solve(head, lastNode);
        return head;
    }
};