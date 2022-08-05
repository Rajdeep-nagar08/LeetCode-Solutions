/*

dp[i] =  Is it possible to  break [i....n-1] into dict

Ans= dp[0]

dp[i] = Is str[i....j] present in dict && Is it possible to break [j+1...n-1]


dp[i] = Is str[i....j] present in dict && dp[j+1]

for all j=i to n-1

*/


int dp[301];

class Solution {
public:
    unordered_map<string,int>mp;
    int n;
    bool wordBreak(string s, vector<string>& wordDict) {
        
        
        memset(dp,-1,sizeof(dp));
        
        for(string str:wordDict){
            mp[str]++;
        }
        
        n=s.size();
        
        return find(0,s);
          
    }
    
    bool find(int i,string &str){
        if(i>=n)
            return true;
        
        if(dp[i]!=-1)
            return dp[i];
        
        bool ans=false;
        
        for(int j=i;j<n;j++){
            
            int l=j-i+1;
            
            string s1=str.substr(i,l);
            
            
            if(mp[s1]>0){
                ans|=find(j+1,str);
            }
            
        }
        
        return dp[i]=ans;
        
    }
};