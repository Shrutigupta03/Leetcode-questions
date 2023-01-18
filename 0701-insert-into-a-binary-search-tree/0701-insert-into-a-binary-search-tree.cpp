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
   TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val) ;

        TreeNode *temp = root ;

        while(true){
            if(temp->val <= val){
                if(temp->right != nullptr){
                    temp = temp->right ;
                }
                else{
                    temp->right = new TreeNode(val) ;
                    break ;
                }
            }
            else{
                if(temp->left != nullptr){
                    temp = temp->left ;
                }
                else{
                    temp->left = new TreeNode(val) ;
                    break ; 
                }
            }
        }
        
        return root;
    }
};