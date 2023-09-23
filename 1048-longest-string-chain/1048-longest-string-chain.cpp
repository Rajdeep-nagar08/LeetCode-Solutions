int dp[1002][1002];

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        
        int n=words.size();
        
        memset(dp,-1,sizeof(dp));
        
        /*
        
        longest possible word chain
        
        
        dp[i] = longest possible word chain in [i....n-1]  starting from index i
        
        */
        
        sort(words.begin(),words.end(),[](string &s1, string &s2){
            return s1.size()<s2.size();
            
        });
        
                
        // making 1 based indexing to avoid passing prev=-1 in starting
        
        return find(1,0,words);
        
        
    }
    
    int find(int i, int prev, vector<string>&words){
        if(i>=words.size()+1)
            return 0;
        
        
        if(dp[i][prev]!=-1)
            return dp[i][prev];
        
       int ans1=0,ans2=0;
        
        ans1=find(i+1,prev,words);

       if(prev==0){
           
           ans2=1+find(i+1,i,words);
       }
        
        else if(words[prev-1].size()+1 ==words[i-1].size() && (isValid(words[i-1],words[prev-1])))
                ans2=1+find(i+1,i,words);
                
        
        
        return dp[i][prev]=max(ans1,ans2);
        
        
    }
    
    bool isValid(string x, string y){
        
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
};