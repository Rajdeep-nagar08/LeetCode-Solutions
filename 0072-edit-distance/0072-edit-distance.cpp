/*

s1[i=a1,.......] , s2[j=a1,.....] as s1[i]==s2[j] move ahead (i++,j++)
 
s1[(i=a1,a2,....)]  , s2[(j=b1,b2,...)] 


Now s1[i]!=s2[j]

If inserttion done: s1[b1,(i=a1,a2,...)] , s2[b1,(j+1=b2,...)] 
if replacing done:  s1[b1,(i+1=a2,...)]  , s2[b1,(j+1=b2,....)]
if deletion done : s1[(i+1=a2,.....)]  , s2[(j=b1,b2,....)]
choosing the way which give us min no of ways:

dp[i][j]= min edit distance for s1[i....n] && s2[j...m]

Ans=dp[1][1]

Base Case: dp[n+1][m+1]=0 , dp[0][0]=0
            dp[0][j]=  n-j or dp[i][0]= n-i   (delete all characters of non empty        string or insert equal no of characters in empy string)
             
            

if(s[i]==s[j])
dp[i][j]=dp[i+1][j+1]
else

dp[i][j]= min( 1+ dp[i][j+1] , 1 + dp[i+1][j+1] , 1+ dp[i+1][j] )


*/




int dp[501][501];
class Solution {
public:
    int minDistance(string s1, string s2) {
        
      int n=s1.length();
      int m=s2.length();
      memset(dp,-1,sizeof(dp));
      
     return find(0,0,s1,s2);
      
    }
  
    int find(int i,int j,string &s1,string &s2){
      if(i==s1.length() || j==s2.length())
        return dp[i][j]= max(s1.length()-i,s2.length()-j);
      
      if(dp[i][j]!=-1)
        return dp[i][j];
      
      
      if(s1[i]==s2[j])
        return dp[i][j]= find(i+1,j+1,s1,s2);
      
     // else{
        int op1= 1+ find(i,j+1,s1,s2);
        int op2=1+find(i+1,j+1,s1,s2);
        int op3=1+find(i+1,j,s1,s2);
          return dp[i][j]= min(op1,min(op2,op3));
    //  }
      
      return dp[i][j];
    }

};


