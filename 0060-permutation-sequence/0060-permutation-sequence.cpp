class Solution {
public:
    string getPermutation(int n, int k) {
        string ans="";
        vector<int> nums;
        for(int i=0; i<n; i++){
            nums.push_back(i+1);
        }
        while(k-1){
            next_permutation(nums.begin(), nums.end());
            k--;
        }
        for(int i=0; i<n; i++){
            ans += to_string(nums[i]);
        }
        return ans;
    }
};