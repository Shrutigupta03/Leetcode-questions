class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, level = 0, water = 0;
        vector<int> res;
        
        while (l < r) {
            
            int lower = height[height[l] < height[r] ? l++ : r--]; 
            if(lower>=level && water){
                res.push_back(water);
                water = 0;
                level = lower;
            }
            else if(lower>=level && water==0){
                level = lower;
            }
            water += level - lower;
        }
        if(water) res.push_back(water);
        
        
        return accumulate(res.begin(), res.end(), 0);
    }
};