int mod=1e9+7;

#define lln long long int

lln dp[102][102][102];  

class Solution {
public:
    int profitableSchemes(int n, int minP, vector<int>& group, vector<int>& prof) {
        
        /*
        
        sum of groups <= n
        
        sum of profits of each group >= minProfit
        
        
        Count of such types of groups =?
        
        For each groups we have two choices => either include it in current groups or not include it in current group
        
        
        dp[i][size][prof]= no of ways to choose from arr[i.....n-1] if
          
          if size of prev group= size <= n(100 max)
          
          and profit of prev group = prof >= minP (100 max)
 
    
    */
        
      memset(dp,-1,sizeof(dp));
        
        return find(0,0,0,n,minP,group,prof)%mod;
        
    }
    
      int find(int i,int sz,int prevP, int n, int minP, vector<int>&group, vector<int>&prof){
          
          if(i>=(int)group.size()){
              if(prevP>=minP)
              return 1;
              
              return 0;
          }
          
          if(dp[i][sz][prevP]!=-1)
              return dp[i][sz][prevP];
          
          lln count=0;
 
          
          count+= find(i+1,sz,prevP,n,minP,group,prof);
          
          
          if(group[i]+sz<=n)
      count+= find(i+1,group[i]+sz,min(prevP+prof[i],101),n,minP,group,prof);
          
          
          return dp[i][sz][prevP]=count%mod;
          
      }
};