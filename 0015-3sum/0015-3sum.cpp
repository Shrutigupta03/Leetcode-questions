class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n= nums.size();
         if(nums.size() < 3){    //Base case 1
            return {};
        }
        if(nums[0] > 0){        //Base case 2
            return {};
        }
        for(int i=0; i<n; ++i){
            if(nums[i] > 0){     //If number fixed is +ve, stop there because we can't make it zero by searching after it.
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]){    //If number is getting repeated, ignore the lower loop and continue.
                continue;
            }
            int start = i+1;
            int end=n-1;
            int sum =0;
            while(start<end){
                sum = nums[start]+nums[end]+nums[i];
                if(sum==0){
                    ans.push_back({nums[i] , nums[start] , nums[end]});  //we have found the required triplet, push it in answer vector
                    int last_start_occurence = nums[start] , last_end_occurence = nums[end];  //Now again, to avoid duplicate triplets, we have to navigate to last occurences of num[low] and num[high] respectively
                    while(start < end && nums[start] == last_start_occurence){   // Update the low and high with last occurences of low and high.
                        start++;
                    }
                    while(start < end && nums[end] == last_end_occurence){
                        end--;
                    }
                }
                else if(sum>0){
                    end--;
                }
                else{
                    start++;
                }
            }
        }
        return ans;
    }
};