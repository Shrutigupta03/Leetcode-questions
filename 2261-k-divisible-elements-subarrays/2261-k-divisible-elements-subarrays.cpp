class Solution {
public:
    bool check(vector<int>& nums, int i, int j, int p, int k){
        int cnt=0;
        for(int x=i; x<=j; x++){
            if(nums[x]%p==0) cnt++;
        }
        if(cnt>k) return false;
        return true;
    }
    
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> s;
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                if(check(nums, i, j, p, k)){
                    vector<int> temp;
                    for(int x=i; x<=j; x++){
                        temp.push_back(nums[x]);
                    }
                    s.insert(temp);
                    temp.clear();
                }
            }
        }
        return s.size();
    }
};