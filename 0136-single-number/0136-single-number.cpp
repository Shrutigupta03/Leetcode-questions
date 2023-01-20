class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> mp;
        for(auto& it : nums){
            mp[it]++;
        }
        for(auto& x : mp){
            if(x.second==1){
                return x.first;
            }
        }
        return 0;
    }
};