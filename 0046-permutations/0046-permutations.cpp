class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        int fact = 1;
        while(n>0){
            fact = fact*n;
            n -= 1;
        }
        // cout<<fact<<endl;
        while(fact--){
            next_permutation(nums.begin(), nums.end());
            res.push_back(nums);
        }
        return res;
    }
};