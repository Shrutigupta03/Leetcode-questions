class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int cnt = 0, i=0;
        string res;
        for(i=0; i<s.size(); i++){
            if(i==spaces[cnt]){
                res+=' ';
                cnt++;
            }
            res+=s[i];
            if(cnt==spaces.size()) break;
        }
        for(i++; i<s.size(); i++){
            res+=s[i];
        }
        return res;
    }
};