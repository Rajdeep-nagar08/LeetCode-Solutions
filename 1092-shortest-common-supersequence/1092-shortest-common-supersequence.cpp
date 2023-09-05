/*

  LCS:
      dp[i][j]=length of lcs btw two strings of length i , j
      if(x[i]==y[j])
      dp[i][j]= 1+dp[i-1][j-1]
      else
      dp[i][j]= max(dp[i-1][j],dp[i][j-1])
      length of shortest common subseq= (l1 + l2 - lcs(l1,l2))
      
      

whenever the question asks you to find the objects chosen instead of the final value you get when you choose these objects (like the indices selected in this question)

we can do the DP for finding the value (like the maximum sum in this case) and do a DFS for retracing the steps.
     
      

*/
   
int dp[1001][1001];

class Solution {
public:
    
    string ans;
    
    string shortestCommonSupersequence(string str1, string str2) {
        
        memset(dp,-1,sizeof(dp));
        
        // finding length of LCS
        find(0,0,str1,str2);
        
        int n=str1.size();
        
        int m=str2.size();
        
        int i=0,j=0;
        
        string ans="";
        
        while(i<n && j<m){
            
            
        if(str1[i]==str2[j]){
            
            ans.push_back(str1[i]);
            
            i++,j++;
        }
            
    else if(dp[i+1][j]>dp[i][j+1]){
         ans.push_back(str1[i]);
        i++;
        }
            else{
                
                ans.push_back(str2[j]);
                j++;
            }
            
        }
        
           while(i<str1.size()){
                ans.push_back(str1[i]);
                i++;
            }
            
            
            while(j<str2.size()){
                ans.push_back(str2[j]);
                j++;
            }
        
        return ans;
        
    }
    
    int find(int i,int j,string &str1, string &str2){
        if(i>=str1.size() || j>=str2.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ch=0;
        if(str1[i]==str2[j])
            ch=1+find(i+1,j+1,str1,str2);
        else
            ch=max(find(i+1,j,str1,str2),find(i,j+1,str1,str2));
        
        return dp[i][j]=ch;
    }
    
    
   
};