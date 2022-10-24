  
/*
        
        length of each subarray = k
        
        sum should be maximum
        
        three such subarrays
        
        
we have multiple choices to get starting points of such 3 subarrays

as we have choices we can think about dp



dp[i][3]= 3 max sum subarrays we needs to select from [i...n-1] whose total sum is max

dp[0][3]= max sum we can get

but how we can get the indexise ?

we can do this using dfs

whenever the question asks you to find the objects chosen instead of the final value you get when you choose these objects (like the indices selected in this question) 
we can do the DP for finding the value (like the maximum sum in this case) and do a DFS for retracing the steps.

*/


 int dp[20001][4];


class Solution {
public:
    
    
   // unordered_map<int,vector<vector<int>>>mp;
    
        vector<int>ans;
    
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        
        int n=nums.size();
      
        memset(dp,-1,sizeof(dp));
        
        vector<int>pref(n,0);
        
        pref[0]=nums[0];
        
        for(int i=1;i<n;i++){
            pref[i]+=pref[i-1]+nums[i];
        }
       
        
          int cnt=3;
        
         find(0,pref,cnt,k);
        
    
           dfs(0,pref,cnt,k);
        
        return ans;
    }
    
    
    
    int find(int i,vector<int>&pref,int cnt,int k){
        
        if(i>=pref.size() || cnt==0){
            
         if(cnt==0){
            
              return 0;
         }
            
            return -1e6;
        }
        
        
        if(dp[i][cnt]!=-1)
            return dp[i][cnt];
        
        int mx1=0;

        mx1=find(i+1,pref,cnt,k);
        
        
        int mx2=0;
        
        if(i+k-1<pref.size()){
                    
            if(i==0)
            mx2=pref[i+k-1]+find(i+k,pref,cnt-1,k);
            
            else
            mx2=pref[i+k-1]-pref[i-1]+find(i+k,pref,cnt-1,k);
      
        }
        
       return dp[i][cnt]=max(mx1,mx2);
       
    }
    
    
    void dfs(int i,vector<int>&pref,int cnt,int k){
        
        if(i>=pref.size() || cnt==0){
            
          
            return;
        }
        

        int mx1=0;

        mx1=find(i+1,pref,cnt,k);
        
        
        int mx2=0;
        
        if(i+k-1<pref.size()){
                    
            if(i==0)
            mx2=pref[i+k-1]+find(i+k,pref,cnt-1,k);
            
            else
            mx2=pref[i+k-1]-pref[i-1]+find(i+k,pref,cnt-1,k);
      
        }
        
        if(mx2>=mx1)
        {
            ans.push_back(i);
            dfs(i+k,pref,cnt-1,k);
            
        }
        
        else
            dfs(i+1,pref,cnt,k);
        
       
    }
    
};