class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<int, vector<int>> mp;
        vector<vector<int>> res;
        for(auto it : points){
            long long distance = it[0]*it[0] + it[1]*it[1];
            mp.insert(pair<int, vector<int>>(distance, it));
        }
        
        for(auto it: mp){
            res.push_back(it.second);
            k--;
            if(k==0) break;
        }
        
        return res;
    }
};