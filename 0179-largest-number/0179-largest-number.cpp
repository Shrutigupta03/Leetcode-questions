class Solution {
public:
    static bool comp(const string s1, const string s2){
        return s1+s2>s2+s1;
    }
    
    string largestNumber(vector<int>& nums) {
        string res;
        vector<string> s;
        
        for(int i=0; i<nums.size(); i++) s.push_back(to_string(nums[i]));
        
        sort(s.begin(), s.end(), comp);
        
        for(int i=0; i<nums.size(); i++){
            res += s[i];
        }
        
        if(s.size()>0 && res[0]=='0'){
            res = "0";
            return res;
        }
        
        return res;
    }
};