class Solution {
public:
    
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
       vector<pair<int,int>> v;
        for(int i=0;i<capital.size();i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        int i=0;
        priority_queue<int> q;
        while(k--){
            while(i<capital.size() && v[i].first<=w){
                q.push(v[i].second);
                i++;
            }
            if(q.empty()){
                break;
            }
            w += q.top();
            q.pop();
        }
        return w;
    }
};