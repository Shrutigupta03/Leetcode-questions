class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int z;
        for(auto x : mp){
            if(x.second>1){
                z = x.first;
                break;
            }
        }
        return z;
    }
};