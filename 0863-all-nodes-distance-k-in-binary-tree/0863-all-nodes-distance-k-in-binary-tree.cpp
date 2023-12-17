/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int count(TreeNode* root){
        if(!root) return 0;
        return 1+count(root->left)+count(root->right);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        
        if(!root) return ans;
        if(!root->left && !root->right){
            if(target->val==root->val && k==0){
                ans.emplace_back(root->val);
            }
            return ans;
        }
        int n = count(root);
        vector<vector<int>> adj(n);
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            int n = temp->val;
            if(temp->left){
                int l = temp->left->val;
                adj[n].emplace_back(l);
                adj[l].emplace_back(n);
                q.push(temp->left);
            }
            if(temp->right){
                int r = temp->right->val;
                adj[n].emplace_back(r);
                adj[r].emplace_back(n);
                q.push(temp->right);
            }
        }
        
        queue<int> q1;
        q1.push(target->val);
        vector<bool> vis(n, 0);
        vis[target->val] = 1;
        int x = 1;
        while(!q.empty() || k--){
            int a=0;
            while(x--){
                int temp = q1.front();
                q1.pop();
                for(int it : adj[temp]){
                    if(!vis[it]){
                        q1.push(it);
                        vis[it]=1;
                        a++;
                    }
                }
            }
            x=a;
        }
        
        while(!q1.empty()){
            ans.emplace_back(q1.front());
            q1.pop();
        }
        return ans;
    }
};