class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long currSum=0, maxSum=0;
        unordered_map<int, int> mp;
        
        for(int i=0; i<k; i++){
            mp[nums[i]]++; 
            currSum += nums[i];
        }
        
        if(mp.size()==k) maxSum = currSum;
        
        for(int i=0; i<nums.size()-k; i++){
            if(mp[nums[i]]>1){
                mp[nums[i]]--;
            }
            else mp.erase(nums[i]);
            currSum -= nums[i];
            
            mp[nums[i+k]]++;
            currSum += nums[i+k];
           
            if(mp.size()==k) maxSum = currSum>maxSum ? currSum : maxSum;
        }
        
        return maxSum;
    }
};