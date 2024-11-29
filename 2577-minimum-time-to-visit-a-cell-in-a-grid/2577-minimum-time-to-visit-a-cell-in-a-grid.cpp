class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n =grid.size();
    int m =grid[0].size();
    vector<pair<int,int>>direc={{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<long long>>mov(n,vector<long long>(m,1e10));
    set<pair<long long,pair<int,int>>>st;
    mov[0][0]=0;
    st.insert({0,{0,0}});
    if(grid[0][1]>1&&grid[1][0]>1){
        return -1;
    }
      while(!st.empty()){
          auto it =*st.begin();
          long long  dis =it.first;
          int row = it.second.first;
          int col = it.second.second;
          st.erase(st.begin());
          if(dis>mov[row][col])continue;
          for(auto p:direc){
              int nr =row+p.first;
              int nc= col+p.second;
              if(nr>=0&&nr<n&&nc>=0&&nc<m){
                  long long add=1;
                  if(dis+1>=grid[nr][nc]){
                    add=1;
                  }
                  else{
                      if((grid[nr][nc]-dis)%2==0){
                        add=grid[nr][nc]-dis+1;
                      }
                      else{
                        add=grid[nr][nc]-dis;
                      }
                  }
                  if(mov[row][col]+add<mov[nr][nc]){
                      mov[nr][nc]=dis+add;
                      st.insert({mov[nr][nc],{nr,nc}});
                  }
                  
              }
          }
      }
    return mov[n-1][m-1];
    }
};