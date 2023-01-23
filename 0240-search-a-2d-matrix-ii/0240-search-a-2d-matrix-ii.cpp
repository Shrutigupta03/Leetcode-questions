class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n= matrix.size();
        int m=matrix[0].size();
        if(n==1 && m==1){
            if( matrix[0][0]==target)
                return true;
            else
                return false;
        }
        for(int i=0; i<n; i++){
            if(matrix[i][0]<=target && matrix[i][m-1]>=target){
                for(auto& it : matrix[i]){
                    if(it==target)
                        return true;
                }
            }
        }
        return false;
    }
};