class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;
        
        for(int i=0; i<n; i++){
            long long temp = 0;
            for(int j=0; j<n; j++){
                temp += abs(nums[j]-nums[i]);
                // cout<<temp<<" ";
            }
            // cout<<endl;
            // temp=abs(temp);
            res=res<temp?res:temp;
        }
        return res;
    }
};