class Solution {
public:
    void findIsland(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid){
        if(i>=grid.size() || j>=grid[0].size() || vis[i][j] || grid[i][j]=='0') return;
        
        vis[i][j]=1;
        findIsland(i+1, j, vis, grid);
        findIsland(i-1, j, vis, grid);
        findIsland(i, j+1, vis, grid);
        findIsland(i, j-1, vis, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int res=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    res++;
                    findIsland(i, j, vis, grid);
                }
            }
        }
        return res;
    }
};