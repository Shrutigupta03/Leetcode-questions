class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i = 1;
        bool flag = false;
        int zeroCnt = count(begin(nums), end(nums), 0);
        if(zeroCnt > 1) return vector<int>(size(nums));   
        for(auto it : nums){
            if(it==0){
                flag=true;
                continue;
            }
            else{
                i = it*i;
            }
        }
        int s = nums.size();
        vector<int> answer;
        for(int j=0; j<s; j++){
            if(flag==true){
                if(nums[j]==0){
                    answer.push_back(i);
                }
                else{
                    answer.push_back(0);
                }
            }
            else{
                int x = i/nums[j];
                answer.push_back(x);
           }
         }
        return answer;
    }
};