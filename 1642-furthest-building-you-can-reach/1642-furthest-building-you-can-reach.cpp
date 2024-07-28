class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int cnt = 0;
        priority_queue<int> pq;
                
        for(int i =0; i<heights.size()-1; i++){
            if(heights[i]>=heights[i+1]) cnt++;
            else{
                int diff = heights[i+1]-heights[i];
                if(bricks >= diff){
                    bricks -= (diff);
                    pq.push(diff);
                    cnt++;
                }
                else if(pq.size()!=0 && ladders && diff<pq.top()){
                    bricks += pq.top();
                    bricks -= diff;
                    pq.pop();
                    pq.push(diff);
                    ladders--;
                    cnt++;
                }
                else if(ladders){
                    ladders--;
                    cnt++;
                }
                else if(ladders==0){
                    break;
                }
                
            }
        }
        return cnt;
    }
};