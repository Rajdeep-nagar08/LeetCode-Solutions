
int dp[501][501];

class Solution {
public:
    int n,m;
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
                
        n=nums1.size();
        
        m=nums2.size();
        
        /*
        
        for each i of nums1, we have choices in nums2
        
        dp[i][j] = max product subsequnce for [i.....n-1] and [j....m-1]
        
        
        */
        
        
        
        
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=m+1;j++){
                dp[i][j]=-1e9;
            }
        }
        
    
        return find(0,0,nums1,nums2);
        
        
    }
    
    int find(int i, int j, vector<int>&nums1, vector<int>&nums2){
        
        if(i>=n || j>=m)
            return -1e9;
        
        
        if(dp[i][j]!=-1e9)
            return dp[i][j];
        
        return dp[i][j] = max({nums1[i]*nums2[j], nums1[i]*nums2[j]+find(i+1,j+1,nums1,nums2),
                      find(i,j+1,nums1,nums2),
                      find(i+1,j,nums1,nums2)});
        
    }
};