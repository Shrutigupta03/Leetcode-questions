class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
         int m=grid.size(), n=grid[0].size();
        vector<int> dir={0,1,0,-1,0};
        vector<vector<int>> dist(m, vector<int> (n,INT_MAX));
        dist[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            auto v=pq.top();
            pq.pop();
            int i=v.second.first, j=v.second.second, d=v.first;
            for(int k=0;k<4;k++)
            {
                int x=i+dir[k], y=j+dir[k+1];
                if(x<0 || x>=m || y<0 || y>=n) continue;
                int wt;
                if(grid[x][y]==1)
                {
                    wt=1;
                }
                else
                {
                    wt=0;
                }
                
                if(d+wt<dist[x][y])
                {
                    dist[x][y]=d+wt;
                    pq.push({dist[x][y],{x,y}});
                }
            }
        }
        return dist[m-1][n-1];  
    
    }
};