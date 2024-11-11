class Solution {
public:
    unordered_map<int, bool> mp;
    bool check(int n){
        if(mp[n]) return mp[n];
        else{
            for (int i = 2; i <= sqrt(n); i++) {
                if (n % i == 0) {
                    mp[n] = 0;
                    return 0;
                }
            }
            mp[n] = 1;
            return 1;
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]>=nums[i+1]){
                int x = nums[i]-nums[i+1];
                bool gotUpdate = 0;
                
                for(int temp = x+1; temp<nums[i]; temp++){
                    if(temp==1) continue;
                    if(check(temp)){
                        gotUpdate = 1;
                        nums[i] -= temp;
                        break;
                    }
                }
                if(!gotUpdate) return false;
            }
        }
        return true;
    }
};