class Solution {
public:
    string decodeString(string s) {
        
        string current;
        stack<string> result;
        stack<int> count;
        int cnt = 0;
        
        for(char ch : s){
            if(isdigit(ch)) {
                cnt = (cnt*10) + (ch-'0');
            }
            else if(ch=='['){
                count.push(cnt);
                result.push(current);
                
                current="";
                cnt = 0;
            }
            else if(ch==']'){
                int repeat = count.top();
                count.pop();
                string temp = result.top();
                result.pop();
                
                while(repeat--){
                    temp+=current;
                }
                current = temp;
            }
            else{
                current+=ch;
            }
        }
        
        return current;
    }
};