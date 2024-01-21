class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res=0;
        set<pair<int, int>> s;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[j]-nums[i]==k){
                    s.insert({nums[i], nums[j]});
                }
            }
        }
        return s.size();
    }
};