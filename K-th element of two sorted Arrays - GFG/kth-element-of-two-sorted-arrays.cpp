//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int nums1[], int nums2[], int p, int q, int k)
    {
        int z=0, ans;       
        int n = p+q;
        int i=0, j=0;
        while(i<p && j<q){
            if(z==k){
                return ans;
            }
            else if(nums1[i]<nums2[j]){
                ans = nums1[i];
                z++;
                i++;
            }
            else {
                ans = nums2[j];
                z++;
                j++;
            }
        }
        if(i<p){
            while(i<p){
                if(z==k){
                    return ans;
                }
                ans = nums1[i];
                z++;
                i++;
            }
        }
        else if(j<q){
            while(j<q){
                if(z==k){
                    return ans;
                }
                ans = nums2[j];
                z++;
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends