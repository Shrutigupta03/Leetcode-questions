class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> v;
        long long res=0;
        long long x = 1000000007;
        for(int i=0; i<nums.size(); i++){
            int temp = 0;
            for(int j=i; j<nums.size(); j++){
                temp += nums[j];
                v.emplace_back(temp);
            }
        }
        sort(v.begin(), v.end());
        for(int i=left-1; i<=right-1; i++){
            res = (res+v[i]) % x;
        }
        return res;
    }
};