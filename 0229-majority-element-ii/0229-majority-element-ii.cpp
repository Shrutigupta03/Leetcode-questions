class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count = nums.size()/3;
        unordered_map<int, int> mp;
        vector<int> res;
        for(auto num : nums){
            mp[num]++;
        }
        for(auto num : mp){
            if(num.second > count){
                res.push_back(num.first);
            }
        }
        return res;
    }
};