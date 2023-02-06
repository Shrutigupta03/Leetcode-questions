class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int a=n;
        for(int i=0; i<n; i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[a]);
            a++;
        }
        return ans;
    }
};