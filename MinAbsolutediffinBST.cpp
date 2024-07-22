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
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        if(!root) return;

        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);

        return;
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        int ans = INT_MAX;
        for(int i=0; i<inorder.size()-1; i++) {
            ans = min(ans, inorder[i+1] - inorder[i]);
        }
        return ans;
    }
};