class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high, int& cnt){
        int j = mid+1;
        for(int i=low; i<=mid; i++){
            while(j<=high && nums[i]> 2*(long long)nums[j])
                j++;
            
            cnt += j-(mid+1);
        }
        
        int size = high-low+1;
        vector<int> temp(size, 0);
        int left = low, right = mid+1, k=0;
        
        while(left<=mid && right<=high){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=mid){
            temp[k++] = nums[left++]; 
        }
        while(right<=high){
            temp[k++] = nums[right++]; 
        }
        
        int m=0;
        for(int i=low; i<=high; i++){
            nums[i] = temp[m++];
        }
    }
    
    void mergeSort(vector<int>& nums, int i, int j, int& cnt){
        if(i>=j) return;
        int mid = (i+j)/2;
        
        mergeSort(nums, i, mid, cnt);
        mergeSort(nums, mid+1, j, cnt);
        merge(nums, i, mid, j, cnt);
    }
    
    int reversePairs(vector<int>& nums) {
        int reversePairsCount = 0;
        mergeSort(nums, 0, nums.size()-1, reversePairsCount);
        return reversePairsCount;
    }
};