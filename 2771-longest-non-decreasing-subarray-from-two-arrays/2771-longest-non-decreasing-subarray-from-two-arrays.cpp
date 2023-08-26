



    int dp[100001][3];


int finalans=0;

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        
        finalans=0;
        
         int n=nums1.size();
        
        memset(dp, -1, sizeof(dp));
        
        helper(0, 0, nums1, nums2);
        
        
        return finalans;

        
    }
    
    
    int helper(int i, int prev, vector<int> &nums1, vector<int> &nums2){
        
        if(i==nums1.size()) return 0;
        
        if(dp[i][prev] != -1) 
            return dp[i][prev];
        
        int ans = 0;
        
        if(prev==0){
            helper(i+1, 0, nums1, nums2);
            int f = 1+helper(i+1, 1, nums1, nums2);
            int s = 1+helper(i+1, 2, nums1, nums2);
            ans = max({ans, f, s});
        }
        else if(prev==1){
            helper(i+1, 0, nums1, nums2);
            int f=0, s=0;
            if(nums1[i]>=nums1[i-1]) f = 1+helper(i+1, 1, nums1, nums2);
            if(nums2[i]>=nums1[i-1]) s = 1+helper(i+1, 2, nums1, nums2);
            
            ans=max({ans, f, s});
        }
        else{
            helper(i+1, 0, nums1, nums2);
            int f=0, s=0;
            if(nums1[i]>=nums2[i-1]) f = 1+helper(i+1, 1, nums1, nums2);
            if(nums2[i]>=nums2[i-1]) s = 1+helper(i+1, 2, nums1, nums2);
            
            ans=max({ans, f, s});
        }
        
        finalans=max(finalans,ans);
        
        return dp[i][prev]  = ans;
        
        
    }

    
    
};