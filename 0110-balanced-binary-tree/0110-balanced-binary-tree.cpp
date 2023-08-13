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
    int solve(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int left=1+solve(root->left);
        int right=1+solve(root->right);
        return max(left,right);
    }
    
    bool isBalanced(TreeNode* root) {
        int from_left=0;
        int from_right=0;
        if(root==NULL)
            return true;
        if(root->left!=NULL)
            from_left=solve(root->left);
        if(root->right!=NULL)
            from_right=solve(root->right);
        if(abs(from_left-from_right)>1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
