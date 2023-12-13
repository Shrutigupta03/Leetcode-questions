class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count=0, m=mat.size(), n=mat[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==1 && row[i]==1 && col[j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};