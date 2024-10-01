class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (auto i : arr) mp[(i % k + k) % k]++;
        
         for (auto i : arr) {
             int rem = (i % k + k) % k;
             
             if (rem == 0) {
                if (mp[rem] % 2 == 1) return false;
             }
             else if (mp[rem] != mp[k - rem])
                return false;
        }
        return true;
    }
};