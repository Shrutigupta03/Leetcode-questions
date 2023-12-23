class Solution {
public:
    bool isPathCrossing(string path) {
        int n = path.size();
        map<pair<int, int>, int> mp;
        pair<int, int> p(0, 0);
        mp[p]++;
        for(int i=0; i<n; i++){
            if(path[i]=='N') p.first++;
            if(path[i]=='E') p.second++;
            if(path[i]=='S') p.first--;
            if(path[i]=='W') p.second--;
            
            if(mp[p]==1) return true;
            mp[p]++;
        }
        return false;
    }
};