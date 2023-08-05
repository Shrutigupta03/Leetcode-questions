class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
   int n = heights.size();
   int right_small[n], left_small[n];
  for(int i=0; i<n; i++){
   while(!st.empty() && heights[st.top()]>=heights[i]){
     st.pop();
   }
   if(st.empty())
     left_small[i]=0;
   else
     left_small[i]=st.top()+1;
    st.push(i);
  }
    while(!st.empty())
      st.pop();

  for(int i=n-1; i>=0; i--){
    while(!st.empty() && heights[st.top()]>=heights[i]){
     st.pop();
    }
    if(st.empty())
     right_small[i]=n-1;
    else
     right_small[i]=st.top()-1;
    st.push(i);
  }

  int maxA=0;
  for(int i=0; i<n; i++){
    maxA = max(maxA, heights[i] * (right_small[i] - left_small[i] + 1));
  }

  return maxA;
    }
};