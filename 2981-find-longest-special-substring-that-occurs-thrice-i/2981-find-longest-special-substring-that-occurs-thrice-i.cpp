class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        unordered_map<string, int> mp;
        
        for(int i=0; i<n; i++){
            string temp;
            for(int j=i; j<n; j++){
                if(s[j]==s[i]){
                    temp+=s[j];
                    mp[temp]++;
                }
                else break;
            }
        }
        
        int maxi=0;
        for(auto it: mp){
            if(it.second>=3 && it.first.size()>maxi) maxi=it.first.size();
        }
        return maxi==0 ? -1 : maxi;
    }
};