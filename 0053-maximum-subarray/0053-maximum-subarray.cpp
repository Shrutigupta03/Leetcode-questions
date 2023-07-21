class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        int global_max=nums[0];
        for(int i=1; i<nums.size(); i++){
            if(sum+nums[i]<nums[i] && nums[i]>sum){
                    sum=nums[i];
            }
            else
                sum = sum+nums[i];
            global_max=max(global_max, sum);
        }
        return global_max;
    }
};