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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        
        queue<TreeNode*> q;
        vector<vector<int>> out;
            
        q.push(root);  
        int level = 0;
        
        while (!q.empty()) {
            
            int count = q.size();  
            vector<int> curr(count); 
            
            for (int i = 0; i < count; i++) {
                
                TreeNode* temp = q.front();
                q.pop();
                
                if (level == 0) {
                    curr[i] = temp->val; 
                } else {
                    curr[count - i - 1] = temp->val; 
                }
                
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            out.push_back(curr);
            level = !level;
        }
         return out;
    }
};