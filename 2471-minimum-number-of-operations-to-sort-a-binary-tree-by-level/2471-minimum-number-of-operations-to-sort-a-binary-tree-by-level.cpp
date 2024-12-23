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
    int minSwap(vector<int>& temp, vector<int>& sorted)
    {
        int ans=0;
        unordered_map<int,int>m;
        for(int i=0;i<sorted.size();i++) 
            m[sorted[i]]=i;
        int i=0;
        while(i<temp.size())
        {
            if(i!=m[temp[i]])
            {
                ans++;
                swap(temp[i],temp[m[temp[i]]]);
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        //using bfs
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>temp,sorted;
            while(sz--)
            {
                TreeNode* node=q.front(); q.pop();
                temp.push_back(node->val);
                if(node->left) {q.push(node->left); }
                if(node->right){ q.push(node->right);}
            }

            sorted=temp;
            sort(sorted.begin(),sorted.end());
            ans+=minSwap(temp,sorted);   
        }
        return ans;
    }
};