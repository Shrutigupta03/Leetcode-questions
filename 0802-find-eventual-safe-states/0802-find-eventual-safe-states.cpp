class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<vector<int>> R(N);
        vector<int> outdegree(N), safe(N), ans;
        queue<int> q;
        for (int i = 0; i < N; i++) {
            for (int v : graph[i]) {
                R[v].push_back(i);
            }
            outdegree[i] = graph[i].size();
            if (outdegree[i] == 0) q.push(i);
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            safe[u] = 1;
            for (int v : R[u]) {
                if (--outdegree[v] == 0) q.push(v);
            }
        }
        for (int i = 0; i < N; ++i) {
            if (safe[i]) ans.push_back(i);
        }
        return ans;
    }
    
};