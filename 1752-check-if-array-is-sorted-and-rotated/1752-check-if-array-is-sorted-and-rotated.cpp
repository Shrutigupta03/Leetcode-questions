class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        bool rev=false;
        for(int i=1; i<n; i++){
            if(rev){
                if(nums[i]<nums[i-1] || nums[i]>nums[0]) return false;
            }   
            if(nums[i]<nums[i-1] && nums[i]<=nums[0]){
                rev=true;
            }
            if(!rev){
                if(nums[i]<nums[i-1]) return false;
            }
        }
        return true;
    }
};