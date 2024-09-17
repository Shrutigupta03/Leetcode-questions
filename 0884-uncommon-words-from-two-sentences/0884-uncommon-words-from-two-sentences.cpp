class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> mp;
        vector<string> res;
        string temp;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]==' '){
                mp[temp]++;
                temp = "";
                continue;
            } 
            else{
                temp+=s1[i];
            }
        }
        mp[temp]++;
        temp = "";
        for(int i=0; i<s2.size(); i++){
            if(s2[i]==' '){
                mp[temp]++;
                temp = "";
                continue;
            } 
            else{
                temp+=s2[i];
            }
        }
        mp[temp]++;
        temp = "";
        
        for(auto it: mp){
            if(it.second == 1) res.push_back(it.first);
        }
        
        return res;
    }
};