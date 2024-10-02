class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v = arr;
        sort(v.begin(),v.end());
        unordered_map<int,int> m;
        int rank = 1;
        for(int i=0;i<arr.size();i++){
            while(i+1 < arr.size() && v[i] == v[i+1]){
                i++;
            }
            m[v[i]] = rank;
            rank++;
        }
        for(int i=0;i<arr.size();i++){
            v[i] = m[arr[i]];
        }
        return v;
    }
};