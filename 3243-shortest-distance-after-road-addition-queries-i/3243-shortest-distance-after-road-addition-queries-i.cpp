class Solution {
public:
    int dijkstra(vector<vector<int>>& adj, int n){
        vector<int> dp(n);
        dp[n - 1] = 0;

        for (int i=n-2; i>=0; i--) {
            int minDist = n;
            for (auto x : adj[i]) {
                minDist = min(minDist, dp[x] + 1);
            }
            dp[i] = minDist;
        }
        return dp[0];
    }
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n, vector<int>(0));
        vector<int> res;
        for(int i=0; i<n-1; i++) adj[i].push_back(i+1);
        
        for(auto it : queries){
            adj[it[0]].push_back(it[1]);
            res.push_back(dijkstra(adj, n));
        }
        return res;
    }
};