class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int x = 0;
        for(int i=0; i<str1.size(); i++){
            if(x==str2.size()) return true;
            if(str1[i]==str2[x] || str1[i]==str2[x]-1 || (str1[i]=='z' && str2[x]=='a')) x++; 
        }
        
        return x==str2.size();
    }
};