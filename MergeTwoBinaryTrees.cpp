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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return NULL;

        TreeNode* root = new TreeNode();
        if(root1 && root2) {
            root->val = root1->val + root2->val;
            root->left = mergeTrees(root1->left, root2->left);
            root->right = mergeTrees(root1->right, root2->right); 
        }
        else if(!root1 && root2) {
            root->val = root2->val;
            root->left = mergeTrees(root1, root2->left);
            root->right = mergeTrees(root1, root2->right);
        }
        else {
            root->val = root1->val;
            root->left = mergeTrees(root1->left, root2);
            root->right = mergeTrees(root1->right, root2);
        }

        return root;
    }
};