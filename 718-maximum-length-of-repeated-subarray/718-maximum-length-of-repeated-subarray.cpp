/*

for each index i in nums1, we have some choices over nums2 to start

dp[i][j]= common length we can get from [i...n1-1] and [j....n2-1]

ans=max(dp[i][j])

*/

int dp[1001][1001];

int n1,n2;

int ans;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        
        ans=0;
        
        n1=nums1.size();
        
        n2=nums2.size();
        
        memset(dp,-1,sizeof(dp));
                
        find(0,0,nums1,nums2);
    
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                ans=max(ans,dp[i][j]);
            }
        }
        
        return ans;
        
    }
    
    int find(int i,int j,vector<int>&nums1,vector<int>&nums2){
        
        if(i>=n1 || j>=n2)
            return 0;
        
       
        if(dp[i][j]!=-1)
            return dp[i][j];
        
              
        int ch1=0;
        
        if(nums1[i]==nums2[j]){
            
         int ch1=1+find(i+1,j+1,nums1,nums2);
        
            dp[i][j]=ch1;
            
        }
        
        else
            dp[i][j]=0;
        
            
        find(i+1,j,nums1,nums2);
        
        find(i,j+1,nums1,nums2);

        return dp[i][j];
            
        
        
    }
};