class Solution {
public:
    
    
    bool compare(string &x, string& y)
    {
        if(x.size()!=y.size()+1)
        {
            return false;
        }
        
        int r1=0;
        int r2=0;
        
        while(r1<x.size())
        {
            if(x[r1]==y[r2])
            {
                r1++;
                r2++;
            }
            
            else
            {
                r1++;
            }
            
            if(r1==x.size() && r2==y.size())
            {
                return true;
            }
        }
        
        return false;
        
    }
    static bool comp(string &a, string &b)
    {
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words)
    {
        
        sort(words.begin(),words.end(),comp);
        vector<int>dp(words.size(),1);
        
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(compare(words[i],words[prev]) &&  dp[prev]+1>dp[i])
                {
                    dp[i]=dp[prev]+1;
                }
            }
            
            ans=max(ans,dp[i]);
        }
        
        return ans;
        
    }
};