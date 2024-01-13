class Solution {
public:
    int minSteps(string s, string t) {
        int res = 0;
        
        map<char, int> mp;
        
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        
        for(auto it : mp){
            if(it.second>0){
                res+=it.second;
            }
        }
        return res;
    }
};