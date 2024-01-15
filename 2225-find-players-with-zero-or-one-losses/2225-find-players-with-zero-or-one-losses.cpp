class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mp;
        vector<vector<int>> res(2);
        
        
        for(auto it : matches){
            if(mp[it[0]]>=0)
                mp[it[0]]++;
            if(mp[it[1]]>0) mp[it[1]]=0;
            mp[it[1]]--;
        }
        
        for(auto it : mp){
            if(it.second>0) res[0].push_back(it.first);
            if(it.second==-1) res[1].push_back(it.first);
        }
        
        return res;
    }
};