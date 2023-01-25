class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size(); 
        int prefix[n]; 
        prefix[0] = arr[0]; 
        for(int i = 1; i < n; i++)
        {
            prefix[i] = arr[i] + prefix[i - 1];
        } 
        unordered_map<int,int> mp; 
        int ans = 0; 
        for(int i = 0; i < n; i++) 
        {
            if(prefix[i] == k)
                ans++;
            if(mp.find(prefix[i] - k) != mp.end())
                ans += mp[prefix[i] - k];
            mp[prefix[i]]++;
        }
        return ans; 
     }
};