/*
        
        for each string we have two choices
        either include its substring or not include 
        
        if including its string ,than take care that count of total zeros <= m and count of total 1's <= n
        
        dp[i][m][n]= size of largest subset of strs taken from [i.....n-1] if we needs to include atmost m 0's and n 1's
        
        */
        
int dp[601][101][101];
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
       
        
        memset(dp,-1,sizeof(dp));
        
        return find(0,m,n,strs);
      
    }
    
      int find(int i,int m,int n,vector<string>&strs){
          if(i>=strs.size() || (m==0 && n==0))
              return 0;
          
           if(dp[i][m][n]!=-1)
               return dp[i][m][n];
          
          int ch1=INT_MIN,ch2=INT_MIN;
          
          ch1=max(ch1,find(i+1,m,n,strs));
          
          int zero=0,one=0;
          string s=strs[i];
          for(int j=0;j<s.size();j++){
            if(s[j]=='0')
                zero++;
              else
                  one++;
           }
          
            if(zero<=m && one<=n){
                ch2=max(ch2,1+find(i+1,m-zero,n-one,strs));
            }
           
          return dp[i][m][n]=max(ch1,ch2);
      }
};