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
    void count(TreeNode* root, int& maxi){
        if(!root) return;
        if(root->val > maxi) maxi = root->val;
        if(root->right) count(root->right, maxi);
        if(root->left) count(root->left, maxi);
    }
    
    int height(int start , vector<vector<int>> v){
        queue<int> q;
        unordered_map<int,bool> seen;
        q.push(start);
        seen[start]=true;
        int time=0;
        for(;q.size();time++){
            int n= q.size();
            while(n--){
                auto node= q.front();  q.pop();
                for(auto i:v[node]){
                    if(!seen[i]){
                        q.push(i);
                        seen[i]=true;
                    }
                }
            }
        }   
        return time-1;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        int n = 0;
        count(root, n);
        
        vector<vector<int>> adj(n+1);
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
          
            if(temp->left){
                adj[temp->val].push_back(temp->left->val);
                adj[temp->left->val].push_back(temp->val);
                q.push(temp->left);
            } 
            if(temp->right){
                adj[temp->val].push_back(temp->right->val);
                adj[temp->right->val].push_back(temp->val);
                q.push(temp->right);
            }
        }
        
        int res = height(start, adj);
        return res;
    }
};