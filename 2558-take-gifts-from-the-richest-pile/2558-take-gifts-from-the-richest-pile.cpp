class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq;
        
        for(auto it : gifts) pq.push(it);
        
        while(k--){
            long long temp = pq.top();
            pq.pop();
            temp = (long long)sqrt(temp);
            pq.push(temp);
        }
        
        long long res = 0;
        
        while(!pq.empty()){
            res+=pq.top();
            pq.pop();
        }
        return res;
    }
};