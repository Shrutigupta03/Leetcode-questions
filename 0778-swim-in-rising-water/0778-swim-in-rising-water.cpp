class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>visited(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        visited[0][0]=1;
        vector<int>delrow={-1,0,1,0};
        vector<int>delcol={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int dist=it.first;
            int row=it.second.first;
            int col=it.second.second;

            if(row==n-1 && col==n-1){
                return dist;
            }
            for(int i=0;i<4;i++){
                int newRow=row+delrow[i];
                int newCol=col+delcol[i];

                if(newRow>=0 && newRow<n && newCol >=0 && newCol<n && visited[newRow][newCol]==0){
                    visited[newRow][newCol]=1;
                    pq.push({max(dist,grid[newRow][newCol]),{newRow,newCol}});
                }
            }

            
        }
        return -1;
    }
};