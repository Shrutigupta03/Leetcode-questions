class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        map<string, multiset<int>> mp;
        for(auto it : access_times){
            mp[it[0]].insert(stoi(it[1]));
        }
        
        vector<string> res;
        
        for(auto it : mp){
            auto s = it.second;
            if(s.size()>=3){
                for(auto x = s.begin(); x != s.end(); x++){
                    if(x==s.begin() || x==s.end()){
                        cout<<*x<<endl;
                        continue;
                    } 
                    if(*x-*prev(x)<100 && *next(x)-*x<100 && *x-*prev(x)>=0 && *next(x)-*x>=0 && *next(x)-*prev(x)<100 && *next(x)-*prev(x)>=0){
                        cout<<*prev(x)<<" "<<*x<<" "<<*next(x)<<endl;
                        res.push_back(it.first);
                        break;
                    }
                }
            }
        }
        return res;
    }
};