class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int val) {
        set<long long>s ;
        
       for(int i=0;i<nums.size();i++){
           if(i>k && i-k-1<nums.size()) 
               s.erase(nums[i-k-1]);
           
           auto it = s.lower_bound((long long)nums[i]-val);
           
           if(it!=s.end()&&*it-nums[i]<=val) return true ;
           
           s.insert(nums[i]);
       }
       return false;
    }
};