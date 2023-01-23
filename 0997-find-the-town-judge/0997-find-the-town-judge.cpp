class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0 && n==1){
            return 1;
        }
        vector<int> count(n+1, 0);
        for(auto& it : trust){
            count[it[0]]--;
            count[it[1]]++;
        }
        for(int i=0; i<count.size(); i++){
            if(count[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};