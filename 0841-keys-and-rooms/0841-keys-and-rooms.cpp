class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visit(n);
        queue<int> q;
        visit[0]=1;
        for(auto it : rooms[0]){
            q.push(it);
            cout<<it<<endl;
            visit[it] = 1;
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto it : rooms[u]){
                if(visit[it]!=1){
                    q.push(it);
                    visit[it] = 1;
                }
            }
            
        }
        for(int i=0; i<n; i++){
            if(visit[i]!=1) return false;
        }
        return true;
    }
};