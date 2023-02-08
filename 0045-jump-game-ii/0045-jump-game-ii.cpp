int dp[10001];

class Solution {
public:
    
    int n;
    
    int jump(vector<int>& nums) {
        
        n=nums.size();
        
        /*
        
        
        nums[i] to nums[i+(0....nums[i])]



dp[i] = min steps to move from [i....n-1]

        */
        
        
        memset(dp,-1,sizeof(dp));
        
        return find(0,nums);
        
        
    }
    
    int find(int i,vector<int>&nums){
        
        if(i==n-1){
            return 0;
        }
        
        if(i>n-1){
            return n+10;
        }
        
        if(dp[i]!=-1)
            return dp[i];
        
        int c=n;
        
        for(int j=1;j<=nums[i];j++){
            if(i+j>=n)
                break;
            
            c=min(c,1+find(i+j,nums));
        }
        
        return dp[i]=c;
        
    }
};