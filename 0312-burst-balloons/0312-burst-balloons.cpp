
int dp[305][305];

class Solution {
public:
    
    int n;
    
    int maxCoins(vector<int>& nums) {
        
        n=nums.size();
        
        vector<int>v(n+2);
        
        v[0]=1;
        
        v[n+1]=1;
        
        for(int i=1;i<=n;i++){
            v[i]=nums[i-1];
        }
        
        /*
        
        among n ballons, we have choces which ballon we burst
        
        dp[i][j]= max cost we can get after bursting ballons [i...j]
        
        ans= dp[0][n-1]
        
        
        */
        
        memset(dp,-1,sizeof(dp));
        
        return find(1,n,v);
        
    }
    
    int find(int i, int j, vector<int>&v){
      
      
       if(i>j)
       return 0;
      
       if(dp[i][j]!=-1)
       return dp[i][j];
       
       
       int ans=0;
       
       for(int k=i;k<=j;k++){  //if bursting kth ballon in last
         
         ans=max(ans, v[i-1]*v[k]*v[j+1]+find(i,k-1,v)+find(k+1,j,v));
         
       }
       
       
       return dp[i][j]=ans;
       
    }
};