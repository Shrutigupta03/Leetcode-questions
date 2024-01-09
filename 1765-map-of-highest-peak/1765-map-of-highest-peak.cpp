class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<pair<int, int>, int> > q;
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> res(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(isWater[i][j] == 1){
                    res[i][j] = 0;
                    q.push({{i, j}, 0});
                }
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first.first, col = it.first.second, height =                       it.second;
            // up
            if(row-1 >= 0 && res[row-1][col] == -1){
                res[row-1][col] = height+1;
                q.push({{row-1, col}, height+1});
            }
            // left
            if(col-1 >= 0 && res[row][col-1] == -1){
                res[row][col-1] = height+1;
                q.push({{row, col-1}, height+1});
            }
            // down
            if(row+1 < n && res[row+1][col] == -1){
                res[row+1][col] = height+1;
                q.push({{row+1, col}, height+1});
            }
            // right
            if(col+1 < m && res[row][col+1] == -1){
                res[row][col+1] = height+1;
                q.push({{row, col+1}, height+1});
            }
        }
        return res;
    }
};