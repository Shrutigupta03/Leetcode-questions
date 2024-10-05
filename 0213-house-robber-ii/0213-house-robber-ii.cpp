class Solution {
public:
    int solve(vector<int> nums, vector<int>& dp, int startIdx, int idx, int n){
        if(idx>=n) return 0;
        
        if(dp[idx]>=0) return dp[idx];
        
         int result = max(nums[idx]+solve(nums, dp, startIdx, idx+2, n), solve(nums, dp, startIdx, idx+1, n));
         dp[idx] = result;
         return result;
        
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size()+1, -1);
        vector<int> dp2(nums.size()+1, -1);
        int n = nums.size();
        if(n==1) return nums[0];
        return max(solve(nums, dp1, 0, 0, n-1), solve(nums, dp2, 1, 1, n));
    }
};