class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=0; i<intervals.size(); i++){
            
            if(res[res.size()-1][1]>=intervals[i][0]){
                
                res[res.size()-1][1] = max(intervals[i][1], res[res.size()-1][1]);
                
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }  
};