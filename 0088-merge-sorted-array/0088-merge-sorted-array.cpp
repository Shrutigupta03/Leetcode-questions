class Solution {
public:
   void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1_copy;
        for(auto &it : nums1){
            nums1_copy.push_back(it);
        }
        nums1.clear();
        int i=0, j=0;
        while(i<m && j<n){
            if(nums1_copy[i]<nums2[j]){
                nums1.push_back(nums1_copy[i]);
                i++;
            }
            else{
                nums1.push_back(nums2[j]);
                j++;
            }
        }
        if(i<m){
            while(i<m){
                nums1.push_back(nums1_copy[i]);
                i++;
            }
        }
        if(j<n){
            while(j<n){
                nums1.push_back(nums2[j]);
                j++;
            }
        }
    }
};