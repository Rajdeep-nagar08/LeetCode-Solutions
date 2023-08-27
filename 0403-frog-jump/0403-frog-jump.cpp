/*

dp[i][k]= Is frong can reach to last stone from ith stone if last jump was k units
dp[i][k]= dp[stones[i]+k-1][k-1] || dp[stones[i]+k][k] || dp[stones[i]+k+1][k+1]

Ans= dp[1][1]

*/

class Solution {
  unordered_map<int,int>mp;
  map<pair<int,int>,bool>dp;
public:
    bool canCross(vector<int>& stones) {
    
       int n=stones.size();
      
      if(stones[1]-stones[0]>1)
        return false;
      
       for(int i=1;i<n;i++)
         mp[stones[i]]=i;
      
       return find(stones[1],1,1,n);
    }
  
    bool find(int no,int i,int k,int n){
       
        if(i==n-1)
        return true;
       
      if(i>=n || i<0)
        return false;
      
      if(dp.count({i,k})==1)
        return dp[{i,k}];
      
        bool op1=false,op2=false,op3=false;
     
       if(k!=1 && mp.count(no+k-1)==1)
         op1=find(no+k-1,mp[no+k-1],k-1,n);
        
       if(mp.count(no+k)==1)
         op2=find(no+k,mp[no+k],k,n);
      
       if(mp.count(no+k+1)==1)
         op3=find(no+k+1,mp[no+k+1],k+1,n);
      
      return dp[{i,k}]=op1||op2||op3;
       
    }
  
};


