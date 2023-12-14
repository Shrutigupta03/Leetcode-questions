class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> onesrow(n, 0);
        vector<int> onescol(m, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    onesrow[i]++;;
                    onescol[j]++;
                }
            }
        }
        vector<vector<int>> diff(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                diff[i][j] = 2*onesrow[i] + 2*onescol[j] - n - m;
            }
        }
        return diff;
    }
};