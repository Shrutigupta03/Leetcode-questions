class Solution {
public:
    int majorityElement(vector<int>& nums) {
       map<int, int> m;
        int n = nums.size();
        int target;
        for(auto it : nums){
            m[it]++;
        }
        cout<<n/2<<endl;
        for(auto it : m){
            // cout<<it.first<<"---"<<it.second<<endl;
            
            if(n/2!=0){
                if(it.second > n/2 ){
                    target = it.first;
                }
            }
            else{
                if(it.second>=n/2){
                    target = it.first;
                }
            }
        }
        return target;
    }
};