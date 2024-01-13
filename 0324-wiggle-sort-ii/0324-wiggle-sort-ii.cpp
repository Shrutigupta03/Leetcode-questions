class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size()==1) return;
        sort(nums.begin(), nums.end());
        vector<int> v = nums;
        
        int i=0, n=nums.size(), j=n%2?(n+1)/2:n/2;
        int x=1, y=n-1;
        
        while(j){
            nums[i]=v[j-1];
            j--;
            i+=2;
            
            nums[x]=v[y];
            y--;
            x+=2;
        }
    }
};