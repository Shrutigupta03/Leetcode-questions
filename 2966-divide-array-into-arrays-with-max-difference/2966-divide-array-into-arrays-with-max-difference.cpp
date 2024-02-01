class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n-1; i+=3){
            if(nums[i+1]-nums[i]>k || nums[i+2]-nums[i+1]>k || nums[i+2]-nums[i]>k){
                vector<vector<int>> opt;
              return opt;  
            } 
            vector<int> temp;
            temp.push_back(nums[i]);
            temp.push_back(nums[i+1]);
            temp.push_back(nums[i+2]);
            res.push_back(temp);  
        }
        return res;
    }
};