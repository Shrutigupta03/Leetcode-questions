class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int initialFresh=0, time=0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                }
                if(grid[i][j]==1) initialFresh++;
            }
        }
        if(q.empty() && initialFresh==0) return 0;
        
        while(!q.empty()){
	        int sz = q.size();
	        while(sz--){
	            int x = q.front().first;
                int y = q.front().second;
                q.pop();
                vector<vector<int>> dir = {{1,0}, {-1,0},{0,1}, {0,-1}};
	        for(int i=0; i<dir.size(); i++){
		        if(x+dir[i][0]>=0 && x+dir[i][0]<grid.size() && y+dir[i][1]>=0 &&  y+dir[i][1]<grid[0].size() && grid[x+dir[i][0]][y+dir[i][1]]==1 ){
                    q.push({x+dir[i][0],  y+dir[i][1]});
                    grid[x+dir[i][0]][ y+dir[i][1]]=2;
                    initialFresh--;
                } 
            }
        }
        time++;
    }
        if(initialFresh==0) return --time;
	    return -1;
        
    }
};
