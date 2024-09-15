class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        vector<vector<string>> res;
        
        for(auto it : strs){
            string temp = it;
            sort(temp.begin(), temp.end());
            
            if(!mp[temp]){
                vector<string> tempstr;
                tempstr.push_back(it);
                res.push_back(tempstr);
                mp[temp] = mp.size();
            }
            
            else res[mp[temp]-1].push_back(it);
        }
        return res;
    }
};