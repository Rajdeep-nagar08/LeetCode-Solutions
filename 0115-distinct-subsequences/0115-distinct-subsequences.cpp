/*

we needs to find subseq. of s that are equal to t

so for ith char of s we have choices as

  => if its not equal to jth char of t, not include it
  
  => if its equal to jth char of t, then we can either include it or not include it
  
 dp[i][j] = no of distinct sub. of s[i....n-1] that are equal to t[j...m-1]
 

*/

#define un unsigned int

un dp[1001][1001];

class Solution {
public:
    int n,m;
    
    int numDistinct(string s, string t) {
      
        n=s.size();
        
        m=t.size();
        
        memset(dp,-1,sizeof(dp));
        
        return find(0,0,s,t);
    }
    
    
    un find(int i,int j,string &s,string &t){
        
        if(j>=m)
            return 1;
        
        if(i>=n){
            return 0;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        un ch1=0,ch2=0;
        
        // skipping
        ch1+=find(i+1,j,s,t);
        
        if(s[i]==t[j]){
          ch2+=find(i+1,j+1,s,t);  
        }
        
        return dp[i][j]=ch1+ch2;
        
    }
    
};