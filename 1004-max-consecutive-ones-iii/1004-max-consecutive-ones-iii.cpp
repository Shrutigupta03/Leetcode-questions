class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        if(nums.size()==k) return k;
        int max_cnt = 0;
        for(int i=0; i<nums.size(); i++){
            int limit = k;
            int cnt = 0;
            int j = i;
            while(j<nums.size() && (limit>0 || nums[j]==1)){
               if(nums[j]==0){
                   limit--;
               }
                cnt++;
                j++;
            }
            max_cnt = max(cnt, max_cnt);
            
            if(nums.size() - max_cnt <= i) break;
        }
        return max_cnt;
    }
};