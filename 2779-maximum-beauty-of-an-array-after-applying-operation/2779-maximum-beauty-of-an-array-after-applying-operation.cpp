class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i=0,j=1;
        int res = 1;
        k*=2;
        while(j<nums.size()){
            if(nums[j]-nums[i]<=k){
                if((j-i+1)>res) res = j-i+1;
                j++;
            }
            else i++;
        }
        
        return res;
    }
};