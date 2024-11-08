class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> prfx(n);
        prfx[0] = nums[0];

        for(int i = 1; i < n; i++)
            prfx[i] = prfx[i-1] ^ nums[i];

        vector<int> ans(n);
        int x = (1 << maximumBit) - 1;

        for (int i = 0; i < n; i++) {
            int curr = prfx[n - 1 - i];
            ans[i] = curr ^ x;
        }
        return ans;
    }
};