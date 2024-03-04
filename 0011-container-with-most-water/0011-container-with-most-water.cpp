
class Solution {
public:
    int maxArea(vector<int>& height) {
        int x = height.size();
        int maxWater=0;
        
        int i=0, j=x-1, dist=x-1;
        
        while(i<j){
            maxWater = max(maxWater, dist*(min(height[i], height[j])));
            if(height[i]<=height[j]){
                i++;
            }
            else j--;
            
            dist--;
        }
        return maxWater;
    }
};