class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int res=0, res2=0;
        
        //start with 0
        for(int i=0; i<n; i++){
            if(i%2==0 && s[i]=='1')
                res++;
            
            if(i%2!=0 && s[i]=='0')
                res++;
        }
        
        //start with 1
        for(int i=0; i<n; i++){
            if(i%2==0 && s[i]=='0')
                res2++;
            
            if(i%2!=0 && s[i]=='1')
                res2++;
        }
        
        return min(res, res2);
    }
};