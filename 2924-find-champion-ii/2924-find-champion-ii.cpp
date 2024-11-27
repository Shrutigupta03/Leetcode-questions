class Solution {
private:
    void solve(vector<int>& vis, int node, unordered_map<int,vector<int>>& adj){
        vis[node] = 1;
        for(auto child : adj[node]){
            if(vis[child]==0){
                solve(vis,child,adj);
            }
        }
    }
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        
        for(auto& val:edges){
            int u = val[0], v = val[1];
            adj[u].push_back(v);
        }

        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            solve(vis, i, adj);

            int cnt=0;
            for(auto& val : vis){
                if(val==1) cnt++;
            }
            if(cnt == n) return i;
        }

        return -1;
    }
};