class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        if(nums.size()==k) return k;
        int max_cnt = 0;
        queue<int> q;
        for(int i=0; i<nums.size(); i++){
            cout<<i<<" ";
            int limit = k;
            int cnt = 0;
            int j = i;
            while(j<nums.size() && (limit>0 || nums[j]==1)){
               if(nums[j]==0){
                   // q.push(j);
                   limit--;
               }
                cnt++;
                j++;
            }
            cout<<"cnt "<<cnt<<endl;
            max_cnt = max(cnt, max_cnt);
            
            while(!q.empty()){
                int x = q.front();
                q.pop();
                if(q.front()-x>1){
                    i = x;
                    break;
                }
                else if(q.size()==1){
                    i = q.front();
                    break;
                }
            }
            while(!q.empty()){
                q.pop();
            }
            
            if(nums.size() - max_cnt <= i) break;
        }
        return max_cnt;
    }
};