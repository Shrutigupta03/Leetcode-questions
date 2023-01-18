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
    TreeNode* invert(TreeNode* root){
        if (!root) { return nullptr; }
        TreeNode* left_tree = invert(root->left);
        TreeNode* right_tree = invert(root->right);
        root->left = right_tree;
        root->right = left_tree;
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
};