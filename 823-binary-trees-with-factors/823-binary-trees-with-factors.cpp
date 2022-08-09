/*

for each no. we have a choice, either take it or not take it

dp[i] = no of binary trees with arr[i] as a root

dp[i]+ = dp[j1]*dp[j2] , where arr[j1]*arr[j2]=arr[i]
                                 and arr[j1] , arr[j2] exist in the array

Ans= sum(dp[0],dp[1]....dp[n-1])


*/

#define lln long long int

int mod=1e9+7;

int dp[1001];

class Solution {
public:
    
    int n;
    
    unordered_map<int,int>mp;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        n=arr.size();
        
        memset(dp,-1,sizeof(dp));
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=find(i,arr)%mod;
            sum=sum%mod;
        }
        
        return sum%mod;
    }
    
    int find(int i,vector<int>&arr){
        
           if(i>=n)
            return 0;
            
            if(dp[i]!=-1)
                return dp[i];
        
        lln ans=1;  // single node
        
        for(int j=0;j<n;j++){
            
               int x=arr[j];
                if(arr[i]%x!=0)
                    continue;
                
               int y=arr[i]/arr[j];
                
                if(mp.count(y)!=1)
                    continue;
                
                int idx=mp[y];
                
              ans=ans+1ll*find(j,arr)*find(idx,arr)%mod;
            
             ans=ans%mod;
        }
        
        return dp[i]=ans%mod;
    }
};