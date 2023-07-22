class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());
        vector<int> temp;
        vector<vector<int>> res;
        int n = intervals.size();
        for(int i=0; i<n; i++){
            if((i<n-1) && (intervals[i][0]<=intervals[i+1][0]) && (intervals[i][1]>=intervals[i+1][0])                && (intervals[i][1]<=intervals[i+1][1])){
               intervals[i+1][0] = intervals[i][0];
            }
            else if((i<n-1) && (intervals[i][0]<=intervals[i+1][0]) && (intervals[i][1]>=intervals[i+1][0])                && (intervals[i][1]>=intervals[i+1][1])){
               intervals[i+1][0] = intervals[i][0];
               intervals[i+1][1] = intervals[i][1];
                
            }
            else{
                temp = intervals[i];
                res.push_back(temp);
            }
        }
        return res;
    }
};