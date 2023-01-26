class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> mp;
        map<string, char> mp2;
        vector<string> vs;
        int j=0;
        int i=1;
        for(i=1; i<s.size(); i++){
            if(isspace(s[i])){
                string sub = s.substr(j,i-j);
                vs.push_back(sub);
                j = i+1;
            }
            else{
                continue;
            } 
        }
        vs.push_back(s.substr(j, i-j));
         
        if(pattern.size()!=vs.size())
            return false;
        for(int k=0; k<pattern.size(); k++){
           if(mp.find(pattern[k])!=mp.end() || mp2.find(vs[k])!=mp2.end()){
               if(mp[pattern[k]]!=vs[k] || mp2[vs[k]]!=pattern[k]){
                   return false;
               }
           }
            mp2[vs[k]]=pattern[k];
            mp[pattern[k]]=vs[k];
        }
        return true;
    }
};