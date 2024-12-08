class Solution {
public:
     bool isValid(int mid, vector<int>& nums, int maxOperations){
        int count = 0;
        for(int num:nums){
            count += (int)ceil(num/(double) mid)-1;
            if(count>maxOperations) return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 0, right = *max_element(nums.begin(), nums.end());
        int ans = right;
        if(right == 1){
            return 1;
        }
        while(left<=right){
            int mid = (left+right)/2;
            if(isValid(mid, nums, maxOperations)){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};