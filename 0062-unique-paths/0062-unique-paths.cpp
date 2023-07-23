class Solution {
public:
    int uniquePaths(int m, int n, int i = 0, int j = 0) {
        int N = n+m-2;
        int r = min(n,m) - 1; 
        double res = 1;
        for(int i=1; i<=r; ++i, N--){   
            res = res * (N) / i;
        } 
        return (int)res;
    }
};