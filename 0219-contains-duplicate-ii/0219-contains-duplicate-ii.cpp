class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;
        if(nums.size()<=k){
            for(int i=0; i<nums.size(); i++){
                s.insert(nums[i]);
            }
            if(s.size()<nums.size()) return true;
            else return false;
        }
        
        for(int i=0; i<=k; i++){
            s.insert(nums[i]);
        }
        cout<<s.size();
        if(s.size()<k+1) return true;
        
        int x=0;
        for(int i=k+1; i<nums.size(); i++){
            s.erase(nums[x]);
            x++;
            s.insert(nums[i]);
            if(s.size()<k+1) return true;
        }
        
        return false;
    }

};