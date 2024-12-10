class Solution {
public:
    int maximumLength(string s) {
        int x = s.size()-2;
        
        for(int i=x; i>=1; i--){
            unordered_map<string, int> mp;
            for(int j=0; j<s.size()-i+1; j++){
                string temp;
                bool valid = 1;
                for(int k=j; k<j+i; k++){
                    if(s[j]==s[k]) temp+=s[k];
                    else {
                        valid=0;
                        break;
                    }
                }
                if(valid){
                    if( mp[temp] == 2) return i;
                    mp[temp]++;
                }
            }
        }
        
        return -1;
    }
};