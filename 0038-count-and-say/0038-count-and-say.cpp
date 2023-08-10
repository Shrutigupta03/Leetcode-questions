class Solution {
public:
    string countAndSay(int n) {
        string s;
        if(n==1){
            s = "1";
            return s;
        }
        s = countAndSay(n-1);
        string ans;
        for(int i=0; i<s.size(); i++){
            int x=1;
            if(i<s.size()-1 && s[i]==s[i+1]){
                while(s[i]==s[i+1]){
                    i++;
                    x++;
                }
            }
            ans += to_string(x);
            ans.push_back(s[i]);
        }
        return ans;
    }
   
};