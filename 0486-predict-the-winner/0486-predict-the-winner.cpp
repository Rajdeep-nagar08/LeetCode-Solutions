int dp[21][21];
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int sum=0;
        if(nums.size()==1)
            return true;
        for(int x:nums)
            sum=sum+x;
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
      int score=find(0,n-1,nums);
        return (score>=sum-score);
    }
     
    int find(int i,int j,vector<int>& nums){
             if(i>j)
                 return 0;
                 if(i==j)
                     dp[i][j]=nums[i];
        if(dp[i][j]!=-1)
            return dp[i][j];
         
dp[i][j]=max(nums[i]+min(find(i+2,j,nums),find(i+1,j-1,nums)),nums[j]+min(find(i+1,j-1,nums),find(i,j-2,nums)));
        return dp[i][j];
             }

        
};