class Solution {
public:
 
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> p;
        vector<string> ans;
        for(int i=0; i<names.size(); i++){
            pair<int, string> temp;
            temp.first = heights[i];
            temp.second = names[i];
            p.push_back(temp);
        }
        
        sort(p.begin(), p.end());
        
        for(auto it: p){
            ans.push_back(it.second);
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};