int dp[100000];

/*

dp[i]=is there is any valid way to partition [i...n-1]


*/

class Solution {
public:
    int n;
    bool validPartition(vector<int>& nums) {
        
        
        memset(dp,-1,sizeof(dp));
        
        n=nums.size();
        
        if(find(0,n,nums))
            return true;
        
        
        return false;
    }
    
      int find(int i,int n,vector<int>&nums){
          
          if(i>=n)
              return true;
          
          if(dp[i]!=-1)
              return dp[i];
          
          bool a=false,b=false,c=false;
          
               //     bool a=true,b=true,c=true;

          
          if(i+1<n && (nums[i]==nums[i+1]))
              a=a|find(i+2,n,nums);
              
          if(i+2<n && (nums[i]==nums[i+1]) && (nums[i]==nums[i+2]))
              b=b|find(i+3,n,nums);
              
              
          if(i+2<n && (nums[i+1]-nums[i]==1) && (nums[i+2]-nums[i+1]==1))
              c=c|find(i+3,n,nums);

           return dp[i]=a|b|c;   

      }
};