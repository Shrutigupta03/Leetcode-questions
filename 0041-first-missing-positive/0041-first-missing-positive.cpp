class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int j = 1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==j){
                j++;
            }
            if(nums[i]<j){
                continue;
            }
        }
        
        return j;
        
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