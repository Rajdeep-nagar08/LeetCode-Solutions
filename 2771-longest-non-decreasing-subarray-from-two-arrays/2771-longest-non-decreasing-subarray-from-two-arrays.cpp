

int dp[100001][3];  

// dp[i][x] = longest increasing subarray if we need to chosse ith no from either of the array and (i-1)th no. was chosen from xth array 


// concept similar to longest common subarray

// ans= max(dp)

int ans=0;

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        
        ans=0;
        
        int n=nums1.size();
        
        
        memset(dp,-1,sizeof(dp));
        
        
        find(1,0,nums1,nums2);
        
        find(1,1,nums1,nums2);
        
    
        return ans+1;
        
    }
    
    int find(int i,int x,vector<int>&nums1,vector<int>&nums2){
        if(i>=nums1.size())
            return 0;
        
        if(dp[i][x]!=-1)
            return dp[i][x];
        
        
        int ans1=0;
        
        int ans2=0;
        
        
        
        if(x==0){  // (i-1)th no was chosen from nums1
            
            if(nums1[i]>=nums1[i-1]){
                ans1=1+find(i+1,0,nums1,nums2);
            }
           
            
            if(nums2[i]>=nums1[i-1]){
                ans2=1+find(i+1,1,nums1,nums2);
            }
           
            
        }
        else{  //  // (i-1)th no was chosen from nums2
            
            
            if(nums1[i]>=nums2[i-1]){
                ans1=1+find(i+1,0,nums1,nums2);
            }
            
            
            if(nums2[i]>=nums2[i-1]){
                ans2=1+find(i+1,1,nums1,nums2);
            }
           
            
        }
        
        dp[i][x]=max(ans1,ans2);
        
        find(i+1,0,nums1,nums2);
        
        find(i+1,1,nums1,nums2);
       
        ans=max(ans,dp[i][x]);
        
        return dp[i][x];
    }
};