class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size(), m=box[0].size();
        vector<vector<char>> newBox(m, vector<char>(n));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                newBox[j][i] = box[i][j];
            }
        }
        
        for(auto &it: newBox){
            reverse(it.begin(), it.end());
        }
        
        for(int i=0; i<n; i++){
            int spc=0, lf=0, btm=m-1;
            for(int j=m-1; j>=0; j--){
                if(newBox[j][i]=='.') spc++;
                else if(newBox[j][i]=='#') lf++;
                else{
                    if(lf!=0 && spc!=0){
                        int temp = lf;
                        for(int x=btm; x>btm-lf-spc; x--){
                            if(temp){
                                newBox[x][i] = '#';
                                temp--;
                            }
                            else{
                                newBox[x][i] = '.';
                            }
                            
                        }
                    }
                    btm=j-1;
                    lf=0;
                    spc=0;
                }
            }
            if(lf!=0 && spc!=0){
                int temp = lf;
                for(int x=btm; x>btm-lf-spc; x--){
                    if(temp){
                        newBox[x][i] = '#';
                        temp--;
                    }
                    else{
                        newBox[x][i] = '.';
                    }

                }
            }
            
        }
        
        return newBox;
    }
};