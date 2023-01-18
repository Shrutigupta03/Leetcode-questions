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
   void storeInorder(TreeNode* root, vector<int> &inorder){
    if(root == NULL)
        return;
    
    storeInorder(root->left , inorder);
    inorder.push_back(root->val);
    storeInorder(root->right,inorder);
    
}
bool findTarget(TreeNode* root, int k) {
    vector<int> inorder;
    
    storeInorder(root,inorder);
    
    int s = 0 , e = inorder.size() -1;
    
    while( s < e ){
        if( inorder[s] + inorder[e] == k ){
            return true;
        }
        else if( inorder[s] + inorder[e] < k ){
            s++;
        }
        else{
            e--;
        }
    }
    
    return false;
}
};