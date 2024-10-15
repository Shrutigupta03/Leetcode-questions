class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0, n=nums.size(), j=n-1;

        for(int k=0; k<n; k++){
            if(k>i && nums[k]==0){
                swap(nums[k], nums[i]);
                k--;
                i++;
            }
            if(k<j && nums[k]==2){
                swap(nums[k], nums[j]);
                k--;
                j--;
            }
        }
    }
};