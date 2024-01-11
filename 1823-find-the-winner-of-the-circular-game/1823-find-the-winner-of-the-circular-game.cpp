class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> vis(n+1, 0);
       
        int x=0;
        int cnt=0;            
        int res;
        
        for(int i=1; i<=n; i++){
            if(x==n){
                 break;
            }
            
            if(vis[i]==1){
                if(i==n) i=0;
                continue;
            }
            cnt++;
            if(cnt==k){
                cnt=0;
                vis[i]=1;
                res = i;
                x++; 
            }   
            if(i==n) i=0;
        }
       
        return res;
    }
};