class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        set<int> s;
        map<int, int> mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        for(auto it : mp){
            s.insert(it.second);
        }
        return mp.size()==s.size();
    }
};