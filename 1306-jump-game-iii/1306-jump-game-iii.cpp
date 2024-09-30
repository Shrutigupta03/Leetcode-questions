class Solution {
public:
    void recurr(vector<int>& arr, int cur, vector<int>& vis, int& i){
        vis[cur]=1;
        if(arr[cur]!=0){
            if(cur+arr[cur]<arr.size() && vis[cur+arr[cur]]==0 && i==INT_MAX){
                recurr(arr, cur+arr[cur], vis, i);
            }
            if(cur-arr[cur]>=0 && vis[cur-arr[cur]]==0 && i==INT_MAX){
                recurr(arr, cur-arr[cur], vis, i);
            }
        }
        else i = cur;
    }
    
    bool canReach(vector<int>& arr, int cur) {
        vector<int> vis(arr.size(), 0);
        int i = INT_MAX;
        recurr(arr, cur, vis, i);
        if(i!=INT_MAX) return true;
        
        return false;
    }
};