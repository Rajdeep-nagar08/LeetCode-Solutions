int dp[1001][1001];

int n,m;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        
         n=text1.size();
		   
		  m=text2.size();
		   
		   memset(dp,-1,sizeof(dp));
		   
		   return lcs(0,0,text1,text2);
		   
        
    }
    
     int lcs(int i,int j,string &text1, string& text2) {
		     
		     if(i>=n || j>=m)
		     {
		         return 0;
		     }
		     
		     if(dp[i][j]!=-1)
		     return dp[i][j];
		     
		     int cnt=0;
		     
		    if(text1[i]==text2[j])
		    return dp[i][j]=1+lcs(i+1,j+1,text1,text2);
		    
		    else
		    return dp[i][j]=max(lcs(i+1,j,text1,text2),lcs(i,j+1,text1,text2));
		    
		    
		  //  return dp[i][j]=cnt;
         
    }
};