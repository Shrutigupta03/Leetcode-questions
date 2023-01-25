class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    int j = INT_MAX, k = INT_MAX;
    for (int i : nums) {
        if (i <= j) {
            j = i;           
        } else if (i <= k) {
            k = i;           
        } else {              
            return true;      // the increasing subsequence of 3 elements exists
        }
    }
    return false;
    }
};