class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            if(st.empty() && (s[i]==']' or s[i]=='}' or s[i]==')') )
                return false;
            
            if(s[i]==')' && st.top()=='('){
                st.pop();
                continue;
            }
            if(s[i]=='}' && st.top()=='{'){
                st.pop();
                continue;
            }
            if(s[i]==']' && st.top()=='['){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        if(st.empty()){
            return true;
        }
        else
            return false;
        
    }
};