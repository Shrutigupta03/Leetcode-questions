class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        
        for(auto it: s){
            if(!st.empty() && ((it =='B' && st.top()=='A') || (it=='D' && st.top()=='C'))) st.pop();
               
            else st.push(it);
        }
        
        int res = 0;
        
        while(!st.empty()){
            res++;
            st.pop();
        }
        
        return res;
    }
};