class Solution {
public:
    int findLHS(vector<int>& nums) {
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            int temp1 = 1, temp2=1;
            bool found1=0, found2=0;
            for(int j=i+1; j<nums.size(); j++){
                if(nums[j]==nums[i]) temp1++, temp2++;
                
                if(nums[i]-1==nums[j]){
                    found1=1;
                    temp1++;
                } 
                
                if(nums[i]+1==nums[j]){
                    found2=1;
                    temp2++;
                } 
            }
            if(found1==0) temp1=0;
            if(found2==0) temp2=0;
            cnt = max(cnt, max(temp1, temp2));
        }
        return cnt;
    }
};