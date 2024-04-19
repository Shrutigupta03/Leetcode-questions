class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(abs(nums[i]-nums[j]) <= min(nums[i], nums[j]) && (nums[i]^nums[j])>res)
                   res=nums[i]^nums[j];
            }
        }
        return res;
    }
};