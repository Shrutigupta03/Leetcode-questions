class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;       
        vector<int> curr;        
        sort(nums.begin(),nums.end());       
        helper(nums,ans,curr,0);       
        return ans;
        
    }
    
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int idx){
        ans.push_back(curr);       
        for(int i=idx;i<nums.size();i++){    
            if(i>idx && nums[i]==nums[i-1]) 
                continue;      
            curr.push_back(nums[i]);     
            helper(nums,ans,curr,i+1); 
            curr.pop_back();         
        }
    }  
};