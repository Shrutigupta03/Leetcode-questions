class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.size() < 10) return ans;
        map<string, int> mp;
        string tmp;
        for(int i=0; i<s.size() and i<10; i++) tmp.push_back(s[i]);
        mp[tmp]++;
        for(int i=10; i<s.size(); i++) {
            tmp.erase(0, 1);
            tmp.push_back(s[i]);
            mp[tmp]++;
        }
        for(auto x: mp) {
            if(x.second > 1) ans.push_back(x.first);
        }
        return ans;
    }
};