class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string ans;
        int n = paths.size();
        vector<int> vis(n, 0);
        queue<string> q;
        q.push(paths[0][1]);
        vis[0]=1;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            for(int i=1; i<n; i++){
                if(vis[i]==0 && paths[i][0]==temp){
                    q.push(paths[i][1]);
                    vis[i]=1;
                }
            }
            ans = temp;
        }
        return ans;
    }
};