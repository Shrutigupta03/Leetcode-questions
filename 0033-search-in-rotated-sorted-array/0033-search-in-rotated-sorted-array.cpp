class Solution {
public:
    int bst(int i, int n, vector<int> nums, int target){
        
        cout<<i<<" "<<n<<endl;
        if(i<0 || n>=nums.size()) return -1;
        
        if(nums[i]==target) return i;
        if(nums[n]==target) return n;
        
        if(i==n || n-i==1) return -1;
        
        int mid = (n+i)/2;
        if(nums[mid]==target) return mid;
        
        int res=-1;
        
        if(nums[i]<nums[mid] && nums[mid]>target && nums[i]<target){
            res = bst(i, mid, nums, target); 
        }
        
        if(res==-1 && nums[mid]<nums[n] && nums[mid]<target && nums[n]>target){
            res = bst(mid+1, n, nums, target);
        }
        
        if(res==-1 && nums[i]>nums[mid] && (nums[mid]>target || nums[i]<target)){
            res = bst(i, mid, nums, target); 
        }
        
        if(res==-1 && nums[mid]>nums[n] && (nums[mid]<target || nums[n]>target)){
            res = bst(mid+1, n, nums, target);
        }
        
        return res;
    }
    
    int search(vector<int>& nums, int target) {
        
        return bst(0, nums.size()-1, nums, target);
           
    }
};