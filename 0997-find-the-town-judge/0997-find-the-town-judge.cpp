class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> vis(n, 0);
        for(int i=0; i<trust.size(); i++){
            vis[trust[i][0]-1]=1;
        }
        bool found = 0;
        int res;
        int j=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                found=1;
                res = i+1;
                j++;
            }
        }
        if(!found || j>1) return -1;
        
        j=0;
        for(int i=0; i<trust.size(); i++){
            if(trust[i][1]==res){
                j++;
            }
        }
        if(j>=n-1) return res;
        
        return -1;
    }
};