class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<=i+k;j++){
                if(j>=nums.size()){
                    break;
                }
                if(nums[i]==nums[j]){
                    return true;
                }
            }
        }
        return false;
    }
};