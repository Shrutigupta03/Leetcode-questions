class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n = matrix.size();
        int m = matrix[0].size();
        // cout<<m<<" "<<n<<endl;
        for(int i=0; i<n; i++){
            if(target>=matrix[i][0] && target<=matrix[i][m-1]){
                for(int j=0; j<m; j++){
                    // cout<<matrix[i][j]<<endl;
                    if(matrix[i][j]==target)
                        return true;
                }
            }
        }
        return false;
    }
};