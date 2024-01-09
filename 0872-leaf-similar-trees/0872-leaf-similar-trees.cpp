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
    bool isLeaf(TreeNode* root){
        if(!root->left && !root->right) return true;
        
        return false;
    }
    
    void getleaf(TreeNode* root, vector<int>& v){
        if(!root) return;
        if(isLeaf(root)){
            v.push_back(root->val);
        } 
        
        getleaf(root->left, v);
        getleaf(root->right, v);
        return;
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        getleaf(root1, l1);
        getleaf(root2, l2);

        if(l1.size()!=l2.size()) return false;
        else{
            for(int i=0; i<l1.size(); i++){
                if(l1[i]!=l2[i]) return false;
            }
            return true;
        }
    }
};