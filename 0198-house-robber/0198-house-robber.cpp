class Solution {
public:
     int solve(int x, vector<int> nums, vector<int>& dp){
         if(x<0) return 0;
         if (dp[x] >= 0) {
            return dp[x];
         }   
         
         int result = max(nums[x]+solve(x-2, nums, dp), solve(x-1, nums, dp));
         dp[x] = result;
         return result;
     }
    
     int rob(vector<int>& nums) {
         vector<int> dp(nums.size()+1, -1);
         return solve(nums.size()-1, nums, dp);
     }
};
