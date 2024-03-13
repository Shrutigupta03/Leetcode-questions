class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size()==1) return 0;
        sort(nums.begin(), nums.end());
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
             int initial=0, next=0, temp=0;
            bool found = 0;
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]==nums[j]){
                    initial++;
                    temp = j;
                } 
                if(nums[j]==nums[i]+1){
                    found = 1;
                    next++;
                }
            }
            if(temp>0)i = temp;
            if(found==1){
                cnt = max(cnt, initial+next+1);
            }
        }
        return cnt;
    }
};