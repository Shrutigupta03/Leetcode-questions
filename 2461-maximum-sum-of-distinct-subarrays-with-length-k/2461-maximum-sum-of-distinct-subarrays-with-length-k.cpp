class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long currSum=0, maxSum=0;
        unordered_map<int, int> mp;
        int i=0, j=0;
        
        while(j<nums.size()){
            int currNum = nums[j];
            int lastOcc = mp.count(currNum) ? mp[currNum] : -1;
            
            while(i<=lastOcc || j-i+1>k){
                currSum -= nums[i];
                i++;
            }
            
            mp[currNum] = j;
            currSum += nums[j];
            if(j-i+1==k) maxSum=max(maxSum, currSum);
            j++;
        }
        
        return maxSum;
    }
};