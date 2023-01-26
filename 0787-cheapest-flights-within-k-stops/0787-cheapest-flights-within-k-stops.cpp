class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int,int>>>graph(n,vector<pair<int,int>>());

        for(auto it:flights)
        {
            graph[it[0]].push_back({it[1],it[2]});
        }       
        
        vector<int>min_stops(n,INT_MAX);

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,src,0});

        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();

            int dist=it[0];
            int node=it[1];
            int stops=it[2];

            if(stops>min_stops[node] || stops>k+1) continue;
            
            min_stops[node]=stops;
            if(node==dst) return dist;

            for(auto it:graph[node])
            {
                int neigh=it.first;
                int distance=it.second;
                pq.push({dist+distance,neigh,stops+1});        
            }
        }
        return -1;
    }
};