class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        unordered_map<int, int> mp;
        vector<int> keys;
        int max = 0;
        for(auto it : items){
            if(it[1]>max) max = it[1];
            if(!mp[it[0]]) keys.push_back(it[0]);
            mp[it[0]] = max;
        }
        
        vector<int> res;
        for(auto it : queries){
            
            auto x = upper_bound(keys.begin(), keys.end(), it);
            if(x-keys.begin()-1>=0 && mp[keys[x-keys.begin()-1]])
                res.push_back(mp[keys[x-keys.begin()-1]]);
            else
                res.push_back(0);
            
        }
        return res;
    }
};