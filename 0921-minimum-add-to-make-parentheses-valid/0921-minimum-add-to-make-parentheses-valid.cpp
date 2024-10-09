class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<char> st;
        
        for(int i=0; i<s.size(); i++){
            if(!st.empty() && st.top()=='(' && s[i]==')'){
                st.pop();
                n-=2;
            }
            else if(s[i] == '(') st.push(s[i]);
        }
        return n;
    }
};