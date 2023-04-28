class Solution {
public:
    bool check(const string &a,const string &b){
        int c = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]){
                c++;
                if(c>2)return false;
            }
        }
        return c == 0 || c == 2;
    }
    int numSimilarGroups(vector<string>& strs) {
        vector<vector<int>> adj(strs.size());
        for(int i = 0; i < strs.size(); i++){
            for(int j = i+1; j < strs.size(); j++){
                if(check(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int res = 0;
        vector<bool> visited(strs.size()+1);
        for(int i = 0; i < strs.size(); i++){
            if(!visited[i]){
                res++;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int cur = q.front();
                    q.pop();
                    visited[cur] = true;
                    for(int j = 0; j < adj[cur].size(); j++){
                        if(!visited[adj[cur][j]]){
                            visited[adj[cur][j]] = true;
                            q.push(adj[cur][j]);
                        }
                    }
                }
            }
        }
        return res;
    }
};