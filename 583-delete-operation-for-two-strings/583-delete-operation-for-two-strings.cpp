int dp[501][501];

/*

dp[i][j]=  lcs from [i...n-1] and [j....m-1]

*/


class Solution {
public:
    int minDistance(string w1, string w2) {
        
        
        /*
        
        ans=n+m-2*lcs
        
        */
        
        memset(dp,-1,sizeof(dp));
        
        int n=w1.size();
        int m=w2.size();
        
        int lcs= find(0,0,w1,w2);
        
        return n+m-2*lcs;
    
    }
    
      int find(int i,int j,string &w1,string &w2){
          if(i>=w1.size() || j>=w2.size())
              return 0;
          
          if(dp[i][j]!=-1)
              return dp[i][j];
          
          int mx=INT_MIN;
          
          if(w1[i]==w2[j])
              mx=max(mx,1+find(i+1,j+1,w1,w2));
          else
              mx=max(mx,max(find(i+1,j,w1,w2),find(i,j+1,w1,w2)));
          
          
          return dp[i][j]=mx;
      }
};