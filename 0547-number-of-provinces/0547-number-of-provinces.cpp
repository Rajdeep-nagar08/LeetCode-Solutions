class Solution {
public:
    int findCircleNum(vector<vector<int>>& is) {
     
        int n = is.size();
        int count = 0;
        vector<bool>visi(n+1,false);
        for(int row=0;row<n;row++){
            if(!visi[row]){
              dfs(is,row,visi);
              count++;
            }
        }
      return count;
    }
  
  void dfs(vector<vector<int>> &is,int row,vector<bool> &visi){
      for(int col=0;col < is[0].size();col++){
        if(is[row][col]==0)
          continue;
        else if(is[row][col]==1 && visi[col]==false){
          visi[col]=true;
          dfs(is,col,visi);
        }
      }
    }
};