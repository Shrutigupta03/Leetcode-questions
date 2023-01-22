class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n , vector<int> (n , 0));
        int tracker  = 1;
        int rowStart = 0 , rowEnd = n-1 , colStart = 0 , colEnd = n-1;
        while(rowStart <= rowEnd && colStart <= colEnd){
            for(int j=colStart ; rowStart <= rowEnd && colStart <= colEnd && j<=colEnd ; j++){
                ans[rowStart][j] = tracker++;
            }
            rowStart++;
            for(int i=rowStart ; rowStart <= rowEnd && colStart <= colEnd && i<=rowEnd ; i++){
                ans[i][colEnd] = tracker++;
            }
            colEnd--;
            for(int j=colEnd ; rowStart <= rowEnd && colStart <= colEnd && j>=colStart ; j--){
                ans[rowEnd][j] = tracker++;
            }
            rowEnd--;
            for(int i=rowEnd ; rowStart <= rowEnd && colStart <= colEnd && i>=rowStart ; i--){
                ans[i][colStart] = tracker++;
            }
            colStart++;
        }
        return ans;
    }
};