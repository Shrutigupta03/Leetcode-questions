class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0 || s.size()==1) return s.size();
        int start = 0, end=1;
        unordered_map<char, int> mp;
        mp[s[start]]++;
        int cnt = 1;
        int temp = 1;
        while(end<s.size() && start<s.size()){
            if(!mp[s[end]]){
                mp[s[end]]++;
                temp++;
                end++;
                cnt = max(cnt, temp);
            }
            else{
                mp[s[start]]--;
                start++;
                temp--;
            }
        }
        
        return cnt;
    }
};