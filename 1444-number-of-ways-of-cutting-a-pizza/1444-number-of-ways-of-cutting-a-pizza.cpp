
#define lln long long int 

int mod=1e9+7;

/*

each piece should have atleast one apple after cut down pizza into k

parts or make k-1 cuts in the pizza


So for each cut(horizontal or vertical) we have multiple choices 


 dp[i][j][k]= no of ways to cut pizza having upper left coordinate (i,j) and bottom right coordinate (n-1,m-1) into k parts such that each part has atleast one apple
 
 Ans= dp[0][0][k]
 
 
 Also making prefix sum array to store info about apples , to answer query in O(1)
 
*/

#define lln long long int


lln dp[51][51][10];

class Solution {
public:

  vector<vector<int>>pref;
  int n,m;
    
    int ways(vector<string>& pizza, int k) {
        
        n=pizza.size();
        m=pizza[0].size();
        memset(dp,-1,sizeof(dp));
        
        formPref(pizza);
        
        
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<pref[i][j]<<" ";
            }
            cout<<endl;
        }
        
        */
            
            
        return find(0,0,k-1,pizza)%mod;
        
    }
    
    
      lln find(int r,int c,int k,vector<string>&pizza){
          
          if(k==0){
              
              if(sumRegion(r,c,n-1,m-1)>=1)
                 return 1;
              
              return 0;
              
          }
          
          if(dp[r][c][k]!=-1)
              return dp[r][c][k];
          
          lln ans=0;
          
          for(int r1=1;r+r1<=n-1;r1++){
             
              // upper part from (r,c) to (r+r1,m-1)
            int a=sumRegion(r,c,r+r1-1,m-1);  
            
             // passing recursiion to bottom part
            
            if(a>=1)
                ans+=find(r+r1,c,k-1,pizza);
              
          }
          
          for(int c1=1;c+c1<=m-1;c1++){
              
              // left part from (r,c) to (n-1,c+c1)
             
             int a=sumRegion(r,c,n-1,c+c1-1);
                  
             // passing recursion to right part
              
              if(a>=1)
                  ans+=find(r,c+c1,k-1,pizza);
              
             
          }
          
          return dp[r][c][k]=ans%mod;
      }
    
    
    void formPref(vector<string>&matrix) {
    
      pref=vector<vector<int>>(n,vector<int>(m,0));
      
      pref[0][0]=matrix[0][0]=='A'?1:0;
        
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
          
          if(i==0 && j>0)
              pref[i][j]=(matrix[i][j]=='A'?1:0)+pref[i][j-1];
            else if(j==0 && i>0)
                pref[i][j]=(matrix[i][j]=='A'?1:0)+pref[i-1][j];
              
             else if(i>0 && j>0)  
    pref[i][j]=(matrix[i][j]=='A'?1:0)+ pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1];
            }
          }
      
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        if(r1==0 && c1==0)
                return pref[r2][c2];
            else if(r1==0)
                return pref[r2][c2]-pref[r2][c1-1];
            else if(c1==0)
                 return pref[r2][c2]-pref[r1-1][c2];
              else
              
               return pref[r2][c2]-pref[r1-1][c2]-pref[r2][c1-1] + pref[r1-1][c1-1];
              
    }

};
