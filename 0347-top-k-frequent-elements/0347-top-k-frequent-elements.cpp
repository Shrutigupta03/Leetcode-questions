class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        vector<int> res;
        for(auto it : nums){
            mp[it]++;
        }
        priority_queue<pair<int,int>> pq;
            
        for(auto it: mp){
            pq.push({it.second, it.first});
        }
        
        while (!pq.empty() && k) {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return res;
    }
};