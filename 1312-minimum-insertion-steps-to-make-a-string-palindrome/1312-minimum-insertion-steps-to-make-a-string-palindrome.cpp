/*

dp[i][j] = length of lcs btw s[i....n-1] and s1[j....n-1]

ans=dp[0][0]

*/

int dp[501][501];

class Solution {
public:
    
    int n;
    
    int minInsertions(string s) {
        
        n=s.size();
        
        // ans= n-lcs(s,reverse(s));
        
        
        string s1=s;
        
        reverse(s1.begin(),s1.end());
        
        
        memset(dp,-1,sizeof(dp));
        
        return n-find(s,s1,0,0);
        
    }
    
    int find(string &s, string &s1,int i, int j){
        if(i>=n || j>=n)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        int ans=0;
        
        if(s[i]!=s1[j]){
            ans=max(find(s,s1,i,j+1),find(s,s1,i+1,j));
        }
        
        else{
            ans=1+find(s,s1,i+1,j+1);
        }
        
        
        return dp[i][j]=ans;
        
    }
};