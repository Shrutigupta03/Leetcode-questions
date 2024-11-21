class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<int>> grid(m, vector<int> (n, 0));
        for(int i=0; i<g.size(); i++){
            grid[g[i][0]][g[i][1]]=2;
        }
		
        for(int i=0; i<w.size(); i++){
            grid[w[i][0]][w[i][1]]=-2;
        }
        
        for(int i=0; i<g.size(); i++){
            int cx = g[i][0];
            int cy = g[i][1];
            for(int i=cx+1; i<m; i++){
                if(grid[i][cy]==2 || grid[i][cy]==-2) break;
                grid[i][cy]=1;
            }
            for(int i=cx-1; i>=0; i--){
                if(grid[i][cy]==2 || grid[i][cy]==-2) break;
                grid[i][cy]=1;
            }
            for(int j=cy+1; j<n; j++){
                if(grid[cx][j]==2 || grid[cx][j]==-2) break;
                grid[cx][j]=1;
            }
            for(int j=cy-1; j>=0; j--){
                if(grid[cx][j]==2 || grid[cx][j]==-2) break;
                grid[cx][j]=1;
            }
        }
        
        int ct=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0) ct++;
            }
        }
        
        return ct;
    }
};