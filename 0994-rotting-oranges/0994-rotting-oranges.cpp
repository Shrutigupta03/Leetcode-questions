class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(q.empty() && fresh == 0){
            return 0;
        }
        
        int m = 0;
        vector<vector<int>> d = {{1, 0},{-1, 0},{0, -1},{0, 1}};
        
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto p = q.front();
                int i = p.first;
                int j = p.second;
                q.pop();
                for(int xi=0;xi<d.size();xi++){
                    int ri = i + d[xi][0];
                    int rj = j + d[xi][1];
                    if(ri>=0 && ri<grid.size() && rj<grid[0].size() && rj>=0 && grid[ri][rj]== 1){
                        grid[ri][rj] = 2;
                        fresh--;
                        q.push({ri,rj});
                    }
                }
            }
            m++;
        }
        if(fresh==0) return --m;
        
        return -1;
    }
};