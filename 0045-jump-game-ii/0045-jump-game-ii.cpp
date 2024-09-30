class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> v(nums.size(),0);
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]+j>=i){
                    if(v[i]==0){
                        v[i] = v[j]+1;
                    }else{
                        v[i] = min(v[i],v[j]+1);
                    }
                }
            }
        }
        return v[nums.size()-1];
    }
};