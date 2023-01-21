class Solution {
public:
    bool check(string s){
        int n=s.size();

        int x=stoi(s);
        if((n>1 && s[0]=='0') || x>255){
            return false;
        }
        
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> vs;
         if(s.size()>12){
             return vs;
         }
        int n=s.size();
        for(int i=1; i<=3; i++){
            for(int j=1; j<=3; j++){
                for(int k=1; k<=3; k++){
                    if(i+j+k<n && i+j+k+3>=n){
                        string a = s.substr(0, i);
                        string b = s.substr(i, j);
                        string c = s.substr(i+j, k);
                        string d = s.substr(i+j+k, n);
                        
                        if(check(a) && check(b) && check(c) && check(d)){
                            vs.push_back(a+"."+b+"."+c+"."+d);
                        }
                    }
                }
            }
        }
        return vs;
    }
};