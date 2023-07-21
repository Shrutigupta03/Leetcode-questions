class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        set<int> row;
        set<int> col;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto it=row.begin(); it!=row.end(); it++){
            for(int k = 0; k<m; k++){
                matrix[*it][k]=0;
            }
        }
        for(auto it=col.begin(); it!=col.end(); it++){
            for(int k = 0; k<n; k++){
                int x = *it;
                matrix[k][*it]=0;
            }
        }
    }
};