class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int Result=0;
        vector<unordered_map<long,int>> dp(n);
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                long Diff=static_cast<long>(nums[j])-nums[i];
                dp[i][Diff]+=1;
                if(dp[j].count(Diff)){
                    dp[i][Diff]+=dp[j][Diff];
                    Result+=dp[j][Diff];
                }
            }
        }
        return Result;
    }
};