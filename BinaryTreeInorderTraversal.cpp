/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void Traversal(TreeNode* root, vector<int>& inorder) {
        if(!root) return;

        Traversal(root->left, inorder);
        inorder.push_back(root->val);
        Traversal(root->right, inorder);

        return;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        Traversal(root, inorder);
        return inorder;
    }
};