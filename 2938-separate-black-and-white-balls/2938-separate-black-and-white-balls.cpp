class Solution {
public:
    long long minimumSteps(string s) {
        int k=0;
        long long j=0;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0'){
                j+=i-k;
                k++;
            }
        }
        return j;
    }
};