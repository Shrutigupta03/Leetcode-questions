class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int num : nums) {
            maxOr |= num;
        }
        
        return count(nums, 0, 0, maxOr);
    }
    
    int count(vector<int>& nums, int idx, int currOr, int maxOr){
    
        if(idx == nums.size()) {
            return (currOr == maxOr) ? 1 : 0;
        }
        
        int notPick = count(nums, idx+1, currOr, maxOr);
        int pick = count(nums, idx+1, currOr|nums[idx], maxOr);
        
        return pick + notPick;
    }
};