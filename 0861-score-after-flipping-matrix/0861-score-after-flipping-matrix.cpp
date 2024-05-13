class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<m; i++){
            if(grid[i][0] == 0){
                for(int j=0; j<n; j++){
                    grid[i][j] = 1- grid[i][j];
                }
            }
        }
        
        for(int j = 1; j<n; j++){
            int countZero = 0;
            
            for(int i=0; i<m; i++){
                if(grid[i][j] == 0) {
                    countZero++;
                }
            }
            if(countZero > m - countZero){
                for(int i=0; i<m; i++){
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        
        int score = 0;
        for(int i=0; i<m; i++){
            for(int j=0;j<n; j++){
                int columnScore = grid[i][j] << (n-j-1);
                score += columnScore;
            }
        }
        
        return score;
    }
};