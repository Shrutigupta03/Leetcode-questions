class Solution {
public:
    int largest(vector<int>& heights)
    {
        stack<int> st;
        int n = heights.size();
        int right_small[n], left_small[n];

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }

            if(st.empty()) left_small[i]=0;
            else left_small[i]=st.top()+1;

            st.push(i);
        }
        while(!st.empty())
          st.pop();

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }

            if(st.empty()) right_small[i]=n-1;
            else right_small[i]=st.top()-1;

            st.push(i);
        }

        int maxA=0;
        for(int i=0; i<n; i++){
            maxA = max(maxA, heights[i] * (right_small[i] - left_small[i] + 1));
        }
        return maxA;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {

        vector<vector<int>> mat(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        for (int j = 0; j < matrix[0].size(); j++){
            for (int i = 0; i < matrix.size(); i++){
                if (matrix[i][j] == '1'){
                    mat[i][j] = (i == 0) ? 1 : mat[i - 1][j] + 1;
                }
            }
        }

        int res = INT_MIN;
        for (auto mat1: mat){
            res = max(res, largest(mat1));
        }

        return res;
    }
};