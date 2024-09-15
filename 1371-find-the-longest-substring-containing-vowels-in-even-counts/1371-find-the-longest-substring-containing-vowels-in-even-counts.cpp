class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        map<char, int> vow;
        vow['a'] = 1;
        vow['e'] = 2; 
        vow['i'] = 4; 
        vow['o'] = 8; 
        vow['u'] = 16; 
        
        int pref = 0;
        int maxi = 0;
        
        map<int, int> mp;
        mp[0] = -1; 
        
        for (int i = 0; i < n; i++) {
            if (vow.find(s[i]) != vow.end()) {
                pref = pref^vow[s[i]];
            }
            
            if (mp.find(pref) != mp.end()) {
                maxi = max(maxi, i - mp[pref]);
            } else {
                mp[pref] = i;
            }
        }
        
        return maxi;
    }
};