
int dp[101][101];

class Solution {
public:
    int sz;
    int minCost(int len, vector<int>& cuts) {
     
    
          sz=cuts.size();
        
        sort(cuts.begin(),cuts.end());
        
        /*
        
        At each step we have a choices among all cuts that have not done        
        yet, these choices are large enough SO => MCM pattern
        
        dp[i][j]= min cost we can get after cuts from range [i...j]
        
        Ans=dp[0][sz-1]
        
        
        */
        
        memset(dp,-1,sizeof(dp));
        
        
        return find(0,sz-1,len,cuts);
          
    }
    
      int find(int i,int j,int len,vector<int>&v){
          if(i>j)
              return 0;
          
           if(dp[i][j]!=-1)
               return dp[i][j];
          
          int ans=INT_MAX;
          
           for(int k=i;k<=j;k++){
               int l;
               
               if(j==sz-1 && i==0)
                   l=len;
               
               else if(j==sz-1)
                   l=len-v[i-1];
               
               else if(i==0)
                   l=v[j+1];
               
               else
                   
                   l=v[j+1]-v[i-1];
                   
               ans=min(ans,l+find(i,k-1,len,v)+find(k+1,j,len,v));
           }
          
          return dp[i][j]=ans;
      }
};