class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int repeatedNum=0, missing=0;
        int x=1, n=nums.size();
        set<int> s;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                repeatedNum=nums[i];
                break;
            }
        }
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        for(auto it : s){
            if(it!=x){
                missing = x;
                break;
            } 
            x++;
        }
        if(missing==0) missing=n;
        return {repeatedNum, missing};
    }
};