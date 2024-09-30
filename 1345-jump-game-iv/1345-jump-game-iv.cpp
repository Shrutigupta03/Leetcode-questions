class Solution {
public:
    int minJumps(vector<int>& a) {
        
        unordered_map<int , vector<int>> mp;
        int n  = a.size();
        
        for(int i=0;i<n;i++)
        {
            mp[a[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        vector<bool> vis(n,false);
        vis[0] = true;
        int ans = 0;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                int ind = q.front();
                if(ind==n-1) return ans;
                int val = a[ind];
                q.pop();
                vector<int> v = mp[val];
                vis[ind] = true;
                v.push_back(ind+1);
                v.push_back(ind-1);
                for(auto i : v)
                {
                    if(i>=n || i<0 || vis[i]) continue;
                    q.push(i);
                }
                mp[val].clear();
            }
            ans++;
        }
        return ans;
    }
};