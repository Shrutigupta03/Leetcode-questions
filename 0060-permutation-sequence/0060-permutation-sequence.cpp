class Solution {
public:
    string getPermutation(int n, int k) {
        string ans="";
        int fact = 1;
        vector<int> nums;
        for(int i=1; i<n; i++){
            fact *= i;
            nums.push_back(i);
        }
        k = k-1;
        nums.push_back(n);
        while(true){
            ans += to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0){
                break;
            }
            k = k%fact;
            fact = fact/nums.size();
        }
        return ans;
    }
};