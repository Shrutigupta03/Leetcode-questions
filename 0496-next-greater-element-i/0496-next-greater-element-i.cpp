class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         int n = nums1.size();
        vector<int> res(n, -1);
        stack<int> s;
        unordered_map<int, int> m;

        for (int num : nums2) {
            while (!s.empty() && s.top() < num) {
                m[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        
        for (int i = 0; i < n; i++)
            if(m[nums1[i]])
                res[i] = m[nums1[i]];
        return res;
    }
};