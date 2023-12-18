class Solution {
public:
    int check(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid){
        if(i>=grid.size() || j>=grid[0].size() || vis[i][j] || grid[i][j]==0) return 0;
        
        vis[i][j]=1;
        return 1+check(i, j+1, vis, grid)+
            check(i, j-1, vis, grid)+
            check(i+1, j, vis, grid)+
            check(i-1, j, vis, grid);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    res = max(res, check(i, j, vis, grid));
                }
            }
        }
        return res;
    }
};