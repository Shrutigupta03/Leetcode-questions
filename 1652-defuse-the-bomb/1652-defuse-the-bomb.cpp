class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> res(code.size(), 0);
        if(k==0) return res;
        
        if(k>0){
            for(int i=0; i<code.size(); i++){
                int x = k, j=i;
                while(x--){
                    if(j+1>=code.size()) j=-1;
                    j++;
                    res[i]+=code[j];
                }
            }
        }
        else{
            for(int i=0; i<code.size(); i++){
                int x = k, j=i;
                while(x++){
                    if(j-1<0) j=code.size();
                    j--;
                    res[i]+=code[j];
                }
            }
        }
        return res;
    }
};