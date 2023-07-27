class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n= nums.size();
         if(nums.size() < 3){   
            return {};
        }
        if(nums[0] > 0){   
            return {};
        }
        for(int i=0; i<n; ++i){
            if(nums[i] > 0){     
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]){   
                continue;
            }
            int start = i+1;
            int end=n-1;
            int sum =0;
            while(start<end){
                sum = nums[start]+nums[end]+nums[i];
                if(sum==0){
                    ans.push_back({nums[i] , nums[start] , nums[end]}); 
                    int last_start_occurence = nums[start] , last_end_occurence = nums[end];  
                    while(start < end && nums[start] == last_start_occurence){   
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