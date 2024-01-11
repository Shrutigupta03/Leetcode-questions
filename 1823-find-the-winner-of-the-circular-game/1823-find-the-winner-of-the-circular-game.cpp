class Solution {
public:
    int findTheWinner(int n, int k) {
        // vector<int> v;
        vector<int> vis(n+1, 0);
        
        // for(int i=0; i<n; i++){
        //     v.push_back(i);
        // }
        int x=0;
        int cnt=0;
        for(int i=1; i<=n; i++){
            if(x==n-1){
                 break;
            }
            
            if(vis[i]==1){
                if(i==n) i=0;
                continue;
            }
            // cout<<i<<" ";
            cnt++;
            if(cnt==k){
                cnt=0;
                vis[i]=1;
                // cout<<i<<" ";
                x++; 
                // cout<<"   "<<x<<endl;
            }   
            if(i==n) i=0;
        }
        
        int res;
        for(int i=1; i<=n; i++){
            if(vis[i]==0){
                res = i;
            }
        }
        return res;
    }
};