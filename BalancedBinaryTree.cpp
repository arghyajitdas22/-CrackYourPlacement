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
    int solve(TreeNode* root, bool &ans) {
        if(!root) return 0;

        int left = 1 + solve(root->left, ans);
        int right = 1 + solve(root-> right, ans);

        int res = left - right;
        if(res<-1 || res>1) ans = false;
        return max(left, right); 
    }

    bool isBalanced(TreeNode* root) {
        bool ans = true;
        int x = solve(root, ans);
        return ans;
    }
};