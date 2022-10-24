/*

whenever the question asks you to find the objects chosen instead of the final value you get when you choose these objects (like the indices selected in this question)

we can do the DP for finding the value (like the maximum sum in this case) and do a DFS for retracing the steps.

*/
   
int dp[1001][1001];

class Solution {
public:
    
    string ans;
    
    string shortestCommonSupersequence(string str1, string str2) {
        
        memset(dp,-1,sizeof(dp));
        
         find(0,0,str1,str2);
        
         dfs(0,0,str1,str2);
        
       // reverse(ans.begin(),ans.end());
        
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
    
    
    void dfs(int i,int j,string &str1, string &str2){
        
        if(i>=str1.size() || j>=str2.size()){
            
            while(i<str1.size()){
                ans.push_back(str1[i]);
                i++;
            }
            
            
            while(j<str2.size()){
                ans.push_back(str2[j]);
                j++;
            }
            
            return ;
            
        }
               
        int ch1=0,ch2=0;

        if(str1[i]==str2[j]){
            
            ans.push_back(str1[i]);
            
            dfs(i+1,j+1,str1,str2);
        }
        
        
        else{
            
             ch1=find(i+1,j,str1,str2);
            
             ch2=find(i,j+1,str1,str2);
            
            if(ch1>=ch2){
                ans.push_back(str1[i]);
                
                dfs(i+1,j,str1,str2);
            }

            else{
                ans.push_back(str2[j]);
                
                dfs(i,j+1,str1,str2);
            }
            
        }
        
        
        
    }
};