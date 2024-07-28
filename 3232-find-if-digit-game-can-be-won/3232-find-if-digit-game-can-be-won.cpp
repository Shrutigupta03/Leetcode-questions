class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single_cnt = 0;
        int double_cnt = 0;
        
        for(auto it: nums){
            if(it<10) single_cnt+=it;
            else double_cnt+=it;
        }
        
        if(double_cnt == single_cnt) return false;
        return true;
    }
};