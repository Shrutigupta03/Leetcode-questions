class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& A) {
      int n = A.size();
      for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i < j && j < n - 1 - i) {
                    A[i][j] = 0;
                }
                if (j < i && i < n - 1 - j) {
                    A[i][j] = 0;
                }
            }
        }
     
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += A[i][i];
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                A[i][j] += max({A[i - 1][j - 1], A[i - 1][j], (j + 1 < n) ? A[i - 1][j + 1] : 0});
            }
        }
       
        for (int j = 1; j < n; j++) {
            for (int i = j + 1; i < n; i++) {
                A[i][j] += max({A[i - 1][j - 1], A[i][j - 1], (i + 1 < n) ? A[i + 1][j - 1] : 0});
            }
        }
        return res + A[n - 1][n - 2] + A[n - 2][n - 1];;
    }
};