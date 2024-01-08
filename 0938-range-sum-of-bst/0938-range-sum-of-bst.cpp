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
    int traverse(TreeNode* root, int low, int high, int& sum){
        if(!root) return sum;
        
        if(root->val<=high && root->val>=low){
            sum += root->val;    
        }
        traverse(root->right, low, high, sum);
        traverse(root->left, low, high, sum);
        return sum;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        int res = traverse(root, low, high, sum);
        return res;
    }
};