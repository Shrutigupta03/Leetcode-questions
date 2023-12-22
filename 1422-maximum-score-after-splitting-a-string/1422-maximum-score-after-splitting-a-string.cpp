class Solution {
public:
    int count(string s1, string s2){
        int res = 0;
        for(auto it : s1){
            if(it=='0') res++;
        }
        for(auto it : s2){
            if(it=='1') res++;
        }
        return res;
    }
    
    int maxScore(string s) {
        int n = s.size();
        int Max = 0;
        for(int i=1; i<n; i++){
            int res = count(s.substr(0, i), s.substr(i, n-i));
            // cout<<res<<endl;
            Max = max(Max, res);
        }
        return Max;
    }
};