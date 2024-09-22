class Solution {
public:
    string simplifyPath(string s) {
        vector<string> v;
        int i=0;
        while(i<s.size()){
            if(s[i]=='/'){
                while(s[i]=='/') i++;
            }
            else{
                string temp = "";
                while(i<s.size() && s[i]!='/'){
                    temp+=s[i];
                    i++;
                }
                if(!temp.empty()){
                   if(temp==".."){
                       if(v.size()) v.pop_back();
                       continue;
                   }
                   else if(temp==".") continue;
                   else v.push_back(temp);
                }
            }
            
        }
        
        string res = "/";
        
        for(int i=0; i<v.size(); i++){
            if(i!=0) res+="/";
            res+= v[i];
            cout<<v[i]<<" ";
        }
        cout<<endl;
        
        return res;
    }
};
