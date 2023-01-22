class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       
        int n= matrix.size();
         vector<vector<int>> mat;
        for(int i=n-1; i>=0; i--){
            vector<int> v;
            for(int j=0; j<n; j++){
                int x;
                x = matrix[i][j];
                v.push_back(x);
            }
            mat.push_back(v);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
               matrix[i][j]=mat[j][i];
            }
        }
    }
};