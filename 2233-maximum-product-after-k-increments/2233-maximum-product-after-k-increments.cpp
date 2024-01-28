class Solution {
public:
    const int mod = 1e9+7;
    
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int mod = 1e9 + 7;
        for(auto it : nums) {
            pq.push(it);
        }

        while(k) { 
            int t = pq.top();
            pq.pop();
            t += 1;
            pq.push(t);
            k--;
        }   
        long long ans = 1;
        
        while(!pq.empty()) {
            ans = (ans * pq.top()) % mod;
            pq.pop();
        }
        
        return ans;
    }
};