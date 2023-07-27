class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> v;
        int x=0;
        bool one = false;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                one = true;
                x++;
            }
            else{
                one = false;
            }
            if(one == false){
                v.push_back(x);
                x=0;
            }
        }
        v.push_back(x);
        int z = *max_element(v.begin(), v.end());
        return z;
    }
};