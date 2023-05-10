class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      if(n==1)
        return {{1}};
        vector<vector<int>>ans(n,vector<int>(n));
        
      int l=0,r=n-1,u=0,d=n-1;
      int no=1;
      while(l<=r && u<=d){
        for(int i=l;i<=r;i++){
          ans[u][i]=no;
          no++;
        }
        
         u++;
        if(u>d)
          break;
        
        for(int i=u;i<=d;i++){
          ans[i][r]=no;
          no++;
        }
           r--;
        if(r<l)
          break;
        
         for(int i=r;i>=l;i--){
           ans[d][i]=no;
           no++;
         }
             d--;
          if(d<u)
            break;
        
        for(int i=d;i>=u;i--){
          ans[i][l]=no;
          no++;
        }
          
         l++;
        if(l>r)
          break;
      }
        return ans;
    }
};