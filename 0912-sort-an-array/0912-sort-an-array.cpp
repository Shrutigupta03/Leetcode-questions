class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> res;
        
        for(auto it : nums){
            res.push(it);
        }
        
        for(int i=0; i<nums.size(); i++){
            nums[i] = res.top();
            res.pop();
        }
        
        return nums;
    }
};