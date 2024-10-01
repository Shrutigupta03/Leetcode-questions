class Solution {
public:
    bool solve(string &s,string &p,int i,int j,vector<vector<int>>&dp){
        
        if (j == p.length()) return i == s.length();

        if(dp[i][j]!=-1) return dp[i][j];

        bool firstMatch = (i < s.length() && (s[i] == p[j] || p[j] == '.'));
        
        if (j + 1 < p.length() && p[j + 1] == '*') 
          dp[i][j] = solve(s, p, i, j + 2, dp) || (firstMatch && solve(s, p, i + 1, j, dp));
        
        else 
            dp[i][j] = firstMatch && solve(s, p, i + 1, j + 1, dp);

        return dp[i][j];
    }
    
    bool isMatch(string s, string p) {

        vector<vector<int>>v(s.length()+1,vector<int>(p.length()+1,-1));
        return solve(s,p,0,0,v);
            
    }
};