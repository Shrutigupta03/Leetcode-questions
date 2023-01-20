class Solution {
public:
  set<vector<int>>st;
    void generate(vector<int>&arr,int start,vector<int>&temp){
         if(arr.size()==start){
            if(temp.size()>1)st.insert(temp);
            return;  
         }
         int curr=arr[start];
         int prev=temp.size()==0?-105:temp[temp.size()-1];

         if(curr>=prev){
             // take 
            temp.push_back(curr);
            generate(arr,start+1,temp);
            // not take
            temp.pop_back();
            generate(arr,start+1,temp);
         }
         else{ 
            // backtrack from here
             generate(arr,start+1,temp);
         }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
         vector<int>temp;
         generate(nums,0,temp);
         return vector(st.begin(),st.end());
    }
};