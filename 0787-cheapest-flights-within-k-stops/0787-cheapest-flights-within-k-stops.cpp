class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        vector<int> dist(n, -1);
        queue<pair<int, int>> pq;
        pq.push({src, 0});
        ++k;
        
        while(!pq.empty()){
            if(!k) break;
            int len = pq.size();
            
            for(int i = 0; i < len; i++) {
                
                auto cur = pq.front(); 
                pq.pop();
                
                for(auto it: adj[cur.first]) {
                    
                    int price = cur.second + it.second; 
                    
                    if(dist[it.first] == -1 || price < dist[it.first]) {
                        dist[it.first] = price;
                        pq.push({it.first, price});
                    }
                }
                
            }
            k--;
        }
        
        return dist[dst];
    }
};