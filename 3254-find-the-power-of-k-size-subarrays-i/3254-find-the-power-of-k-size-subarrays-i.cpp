class Solution {
public:
    vector<int> resultsArray(vector<int>& arr, int k) {
        vector<int> res;
        
        for(int i=0; i<arr.size()-k+1; i++){
            bool invalid = 0;
            for(int j=i; j<i+k-1; j++){
                if(arr[j]+1!=arr[j+1]){
                    invalid = 1;
                    res.push_back(-1);
                    break;
                }
            }
            if(!invalid) res.push_back(arr[i+k-1]);
        }
        return res;
    }
};