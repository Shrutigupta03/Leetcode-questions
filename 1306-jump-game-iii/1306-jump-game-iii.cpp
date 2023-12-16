class Solution {
public:
    bool canReach(vector<int>& arr, int cur) {
        if(cur < 0 || cur >= size(arr) || arr[cur] < 0) return false;                  // out of bounds OR already visited ? return false
        arr[cur] *= -1;       // mark as visited by making -ve
        return !arr[cur] || canReach(arr, cur + arr[cur]) || canReach(arr, cur - arr[cur]);  // return true if A[cur] == 0 or recurse for both possible jumps
    }
};