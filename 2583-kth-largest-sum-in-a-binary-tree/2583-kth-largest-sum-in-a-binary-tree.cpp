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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        priority_queue<long, vector<long>, greater<long>> pq;
        
        while(!q.empty()){
            int n = q.size();
            long long tempMax = 0;
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                tempMax += temp->val;
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            pq.push(tempMax);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        if(pq.size()<k) return -1;
        return pq.top();
    }
};