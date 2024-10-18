class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        for(auto it : nums) mp[it]++;
        
        int res = 0;
        for(auto it : mp){
            mp[it.first] = mp[it.first - 1] ?  mp[it.first - 1] +1 : 1;
            res = max(res, mp[it.first]);
        }
        return res;
    }
};