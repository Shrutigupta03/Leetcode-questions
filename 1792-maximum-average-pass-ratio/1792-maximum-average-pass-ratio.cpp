class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& c, int e) {
        priority_queue<pair<double,int>> pq;
        int n=c.size();
        for(int i=0;i<n;i++){
            double v=(c[i][1]-c[i][0])*1.0/(((c[i][1])*1.0)*(c[i][1]+1));
            if(v<1){
            pq.push({v,i});}
        }
        while(e!=0){
            auto p=pq.top();
            pq.pop();
            int id=p.second;
            c[id][0]++;
            c[id][1]++;
            double v=(c[id][1]-c[id][0])*1.0/(((c[id][1])*1.0)*(c[id][1]+1));
            if(v<1){
            pq.push({v,id});}
            e--;
            
        }
        double ans=0;
        for(int i=0;i<n;i++){
            ans+=((c[i][0]*1.0)/c[i][1]);
        }
        ans/=n;
        return ans;
    }
};