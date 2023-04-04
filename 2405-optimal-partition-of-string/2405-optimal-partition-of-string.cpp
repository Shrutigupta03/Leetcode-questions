class Solution {
public:
    int partitionString(string s) {
        int count=0;
        map<char, int> mp;
        for(int i=0; i<s.size(); i++){
            if(mp[s[i]]==0){
                mp[s[i]]++;
            }
            else{
                count++;
                mp.clear();
                mp[s[i]]++;
            }
        }
        count++;
        return count;
    }
};