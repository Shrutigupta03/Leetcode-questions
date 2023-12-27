class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
        int res = 0;
        int n = s.size();
        for(int i = 1; i < n; i++)
        {
            if(s[i] == s[i - 1])
            {
                res += min(neededTime[i], neededTime[i - 1]); 
                neededTime[i] = max(neededTime[i], neededTime[i - 1]); 
            }     
        }
        
        return res;
    }
};