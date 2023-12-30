class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char, int> mp;
        int n = words.size();
        for(int i=0; i<n; i++){
            for(auto it : words[i]){
                mp[it]++;
            }
        }
        for(auto it : mp){
            if(it.second%n) return false;
        }
        return true;
    }
};