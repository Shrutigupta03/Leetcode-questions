class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        char curr=colors[0];
        int res=0, len = colors.size();
        multiset<int> s;
        s.insert(neededTime[0]);
        for(int i=1; i<len; i++){
            if(colors[i]==curr){
                s.insert(neededTime[i]);
            }
            else{
                if(s.size()>1){
                    int sz = s.size(), x=0;
                    for(auto it : s){
                        if(x==sz-1) continue;
                        res+=it;
                        x++;
                    }
                }
                s.clear();
                curr=colors[i];
                s.insert(neededTime[i]);
            }
        }
        
        if(s.size()>1){
            int sz = s.size(), x=0;
            for(auto it : s){
                if(x==sz-1) continue;
                res+=it;
                x++;
            }
        }
        return res;
    }
};