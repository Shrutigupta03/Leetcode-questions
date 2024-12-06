class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int res = 0, curr=0;
        unordered_set<int> s;
        for(auto it : banned){
            if(it<=n) s.insert(it);
        } 
        
        for(int i=1; i<=n; i++){
            if(curr+i<=maxSum){
                if(s.find(i)==s.end()){
                    curr+=i;
                    res++;
                }
            }
            else return res;
        }
        return res;
    }
};