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
#include <bits/stdc++.h>

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
    
    for(int i=0; i<inorder.size()-1; i++){
        int x = k - inorder[i];
        if(find(inorder.begin()+i+1, inorder.end(), x) != inorder.end())
            return true;
    }
    
    return false;
}
};