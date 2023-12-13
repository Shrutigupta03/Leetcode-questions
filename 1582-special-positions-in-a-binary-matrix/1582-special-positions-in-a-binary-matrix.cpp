class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count=0;
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==1){
                    bool yes = true;
                    for(int x=0; x<m; x++){
                        if(x!=i && mat[x][j] == 1){
                            yes = false;
                        }
                    }
                    for(int y=0; y<n; y++){
                        if(y!=j && mat[i][y] == 1) yes = false;
                    }
                    
                    if(yes){
                        count++;
                       
                    }
                }
            }
        }
        return count;
    }
};