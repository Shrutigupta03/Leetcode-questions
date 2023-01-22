class Solution {
public:
    bool check(string s, int start_idx, int last_idx){
        while(start_idx <= last_idx){
            if(s[start_idx] != s[last_idx])
                return false;
            start_idx++;
            last_idx--;
        }
        return true;
    }
    void palindromePartition(int index, vector<string>& ds, vector<vector<string>>& output,     string s){
        if(index == s.length()){
            output.push_back(ds);
            return;
        }
        for(int i = index; i < s.length(); i++){
            if(check(s, index, i)){
                ds.push_back(s.substr(index, i - index + 1));
                palindromePartition(i+1, ds, output, s);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> output;
        vector<string> ds;
        palindromePartition(0, ds, output, s);
        return output;
    }
};