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
   vector<int> numbers;//declare it globally, it contains the inorder traversal of BST

void inorderpush(TreeNode* root){
    if(root==nullptr){
        return;
    }
    inorderpush(root->left);
    numbers.push_back(root->val);//inserts the element in array
    inorderpush(root->right);
}

bool isValidBST(TreeNode* root) {
    inorderpush(root);

    for(int i=0;i<numbers.size()-1;i++){
        if(numbers[i+1]<=numbers[i]){
            return false;//if array is not strictly increasing
        }
    }
    return true; //if array is strictly increasing   
    }
};