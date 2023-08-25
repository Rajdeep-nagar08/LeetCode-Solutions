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
    
//         for(int i=0;i<=n1;i++){
//             for(int j=0;j<=n2;j++){
//                 ans=max(ans,dp[i][j]);
//             }
//         }
                
//         vector<int>v;
        
//         int i=0,j=0;
        
//         while(i<n1 && j<n2){
//             if(nums1[i]==nums2[j]){
//                 v.push_back(nums1[i]);
//                 i++,j++;
//             }
            
//             else if(dp[i+1][j]>dp[i][j+1]){
//                 i++;
//             }
//             else{
//                 j++;
//             }
//         }
        
//         for(int x:v){
//             cout<<x<<" ";
//         }
        
        // return ans;
        
        
        int start1=-1,start2=-1;
        
        for(int i = 0; i <= n1; i++) {
            for(int j = 0; j <= n2; j++) {
                if (dp[i][j] > ans) {
                    ans = dp[i][j];
                    start1 = i;
                    start2 = j;
                }
            }
        }
        
//         cout<<start1<<" "<<start2<<endl;
        
//         // Print the longest common subarray
//         if (start1 != -1 && start2 != -1) {
//             // cout << "Longest common subarray: ";
//             for (int k = 0; k < ans; k++) {
//                 cout << nums1[start1 + k] << " ";
//             }
//             // cout << endl;
//         }

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
            
            find(i+1,j,nums1,nums2);
        
           find(i,j+1,nums1,nums2);
            
        }
        
        else{
            
            dp[i][j]=0;
            
            find(i+1,j,nums1,nums2);
        
            find(i,j+1,nums1,nums2);
            
        }
        
        return dp[i][j];
            
       
    }
};