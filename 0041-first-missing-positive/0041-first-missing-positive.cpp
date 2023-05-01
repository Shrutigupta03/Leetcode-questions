class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i=0; i<nums.size(); ++i)
            while (nums[i]>0 && nums[i]<=nums.size() && nums[i]!=nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
        for (int i=0; i<nums.size(); ++i)
            if (nums[i] != i+1) return i+1;
        return nums.size()+1;  
        
    }
};
 // int ans=1,n=nums.size();
 //        sort(nums.begin(),nums.end());
 //        for(int i=0;i<n;i++){
 //            if(nums[i]==ans){
 //                ans++;
 //            }
 //            if(nums[i]<ans){
 //                continue;
 //            }
 //        }
 //        return ans;