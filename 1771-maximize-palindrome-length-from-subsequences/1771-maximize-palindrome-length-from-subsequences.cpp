int dp[2001][2001];

    int ans;

    int n1,n2;

class Solution {
public:
    
    int longestPalindrome(string w1, string w2) {
        
        ans=0;
        
        n1=w1.size();
         
        n2=w2.size();
        
        memset(dp,-1,sizeof(dp));
        
        string s=w1+w2;
        
        find(0,n1+n2-1,s);
    
     return ans; 
        
    }
    
    int find(int i,int j,string &s){
        
        if(i>=j){
            
            if(i==j)
                return 1;
            
            return 0;
        }
        
        
        if(dp[i][j]!=-1)
            return dp[i][j];
                
        if(s[i]==s[j]){
            
            dp[i][j]=2+find(i+1,j-1,s);
        
            if(i<n1 && j>=n1)
                ans=max(ans,dp[i][j]);
            
        }
        
        else
            dp[i][j]=max(find(i+1,j,s),find(i,j-1,s));

        
        return dp[i][j];
        
    }
};