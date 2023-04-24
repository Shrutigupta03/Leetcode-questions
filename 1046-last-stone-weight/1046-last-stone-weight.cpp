class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n = stones.size();
        for(int i=0; i<n; i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            if(f != s){
                pq.push(abs(f-s));
            }
        }
        return pq.size()?pq.top():0;
    }
};