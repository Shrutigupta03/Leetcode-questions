class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        vector<int> v;
        int n = nums1.size()+nums2.size();
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(v.size()==(n/2)+1){
                return n%2?v[n/2]:(v[n/2-1]+v[n/2])/2.0;
            }
            else if(nums1[i]<nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else {
                v.push_back(nums2[j]);
                j++;
            }
        }
        if(i<nums1.size()){
            while(i<nums1.size()){
                if(v.size()==(n/2)+1){
                    return n%2?v[n/2]:(v[n/2-1]+v[n/2])/2.0;
                }
                v.push_back(nums1[i]);
                i++;
            }
        }
        else if(j<nums2.size()){
            while(j<nums2.size()){
                if(v.size()==(n/2)+1){
                    return n%2?v[n/2]:(v[n/2-1]+v[n/2])/2.0;
                }
                v.push_back(nums2[j]);
                j++;
            }
        }
        return n%2?v[n/2]:(v[n/2-1]+v[n/2])/2.0;
    }
};