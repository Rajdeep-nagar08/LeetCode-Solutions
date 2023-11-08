#define lln long long int

unordered_map<char,unordered_map<int,int>>mp; // target[ind2] => {ind1, count}

class Solution {
public:
    
long long mod=1e9+7;
    
lln dp[1001][1001];
    
    lln func(int ind1,int ind2,vector<string>& words, string &target){
        
        if(ind2==target.size()) 
            return 1;
        
        if(ind1>=words[0].size()) 
            return 0;
        
        if(dp[ind1][ind2]!=-1) 
            return dp[ind1][ind2];
        
        lln res=0;
        
        lln count=mp[target[ind2]][ind1];
      
         if(count>0){
         count%=mod;
         res+=count*func(ind1+1,ind2+1,words,target)%mod;

         }
        
        res+=func(ind1+1,ind2,words,target)%mod;
        
        return dp[ind1][ind2]=res%mod;
        
    }
    
    int numWays(vector<string>& words, string target) {
        
        memset(dp,-1,sizeof(dp));
        
        mp.clear();
        
        for(int ind2=0;ind2<target.size();ind2++){    // O(26)
            if(mp.count(target[ind2])==1)
                continue;
            
            for(int ind1=0;ind1<words[0].size();ind1++){  // O(1000)
                for(int i=0;i<words.size();i++){  // O(1000)
                    if(words[i][ind1]==target[ind2])
                    mp[target[ind2]][ind1]++;
                }
            }
        }
        
        
        
        return func(0,0,words,target);   // T.C = O(26*1000*1000)
    }
};