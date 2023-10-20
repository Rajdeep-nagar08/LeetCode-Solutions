 
    /* as values can be negative, 
       either we select a stone or not select it,
       prefix[]={a,a+b,a+b+c,a+b+c+d}
if includingg first i stones , diff= value of first i stones- recursion for next
       or diff=prefix[i]-solve(i+1)
       if not including first i stones , then diff=recursion for next=solve(i)
       (when passing recursion to next step, its mentioned that we have 
       to add up the value of all previous stones to next one, this
       thing is already handle by prefix array )
       and ans=max of both cases
       dp[i]= ans if we work on first i stones
       
       Also if 
       */
class Solution {
public:
vector<int>dp;

    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        dp.resize(n+1,INT_MIN);
        vector<int>prefix(n,0);
        prefix[0]=stones[0];
        for(int i=1;i<n;i++)
            prefix[i]+=prefix[i-1]+stones[i];
        return solve(1,prefix);
    }
 
    int solve(int i,vector<int>&prefix){
        if(i==prefix.size()-1)
            return prefix[i];
        if(dp[i]!=INT_MIN)
            return dp[i];
         int op1=prefix[i]-solve(i+1,prefix);
         int op2=solve(i+1,prefix);
          return dp[i]=max(op1,op2);
    }
};
