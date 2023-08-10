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
        if(s.size()==1){
            ans.push_back('1');
            ans.push_back(s[0]);
        }
        else{
            for(int i=0; i<s.size(); i++){
                int x=1;
                if(i<=s.size()-2 && s[i]==s[i+1]){
                    while(s[i]==s[i+1]){
                        i++;
                        x++;
                    }
                }
                
                ans += to_string(x);
                if(x==1){
                    // cout<<"last if x "<<x<<endl;
                    ans.push_back(s[i]);
                }
                else{
                    // cout<<"last else x "<<x<<endl;
                    ans.push_back(s[i-1]);
                }
            }
        }
     return ans;
    }
   
};