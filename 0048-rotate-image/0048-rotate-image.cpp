class Solution {
public:
    void transpose(vector<vector<int>>& m)
    {
        int n=m.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j>i)
                {
                    swap(m[i][j],m[j][i]);
                }
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        int n=matrix.size();
        int i=0,j=n-1;
        while(i<j)
        {
            for(int k=0;k<n;k++)
            {
                swap(matrix[k][i],matrix[k][j]);
            }
            i++;
            j--;
        }
        
    }
};