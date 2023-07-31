/*
for each character we have a choice either to delete it or not
we can think of dp

dp[i][j]=lowest sum deleted characters from s1[i...n1-1] , s2[j....n2-1] to make them equal

if(s1[i]==s2[j]) ne needs to delete it => i++ , j++

if(s1[i]!=s2[j]) than we needs to think whether to delete s1[i] or s2[j]

dp[i][j]= min(s1[i]+dp[i+1][j] , s2[j] + dp[i][j+1])


*/

int dp[1001][1001];
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        memset(dp,-1,sizeof(dp));
        
        return check(0,0,s1,s2);
    }
    
    int check(int i,int j,string &s1,string &s2){
       
        if(i>=s1.length()){
            int count=0;
            for(;j<s2.length();j++)
               count+=int(s2[j]);
            return count;
        }
        
         if(j>=s2.length()){
            int count=0;
            for(;i<s1.length();i++)
                count+=int(s1[i]);
            return count;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
       if(s1[i]==s2[j])
            dp[i][j]=check(i+1,j+1,s1,s2);
        else
            dp[i][j]=min(int(s1[i])+check(i+1,j,s1,s2),int(s2[j])+check(i,j+1,s1,s2));
        
        return dp[i][j];
     
    }
};