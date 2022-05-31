/*

for each  nums[i] we have choices among n slots

to store the condition of slots, we use bit mask

two adjacent bits represent the situation of any slot

00 00 00 11 01 => it means 1st slot have 1 integer , 2nd slot have 2 integers 
                  and other slots are empty

as max no of slots =9
so size of bitmask=18

dp[i][mask] = max And sum using [i...n-1] array, if condition of slots till now is stored in mask

*/


int dp[18][1<<18];
class Solution {
public:
    int maximumANDSum(vector<int>& nums, int slots) {
        
        int n=nums.size();
        
        memset(dp,-1,sizeof(dp));
        
        return find(0,0,nums,slots);
    
    }
    
    int find(int i,int mask,vector<int>&nums,int slots){
        
        if(i>=nums.size()){
            return 0;
        }
        
        if(dp[i][mask]!=-1)
            return dp[i][mask];
        
        int mx=INT_MIN;
        
        for(int j=0;j<2*slots;j++){
            if((mask & (1<<j))!=0)
                continue;
            int temp=(nums[i]&((j/2)+1));
     mx=max(mx,(temp+find(i+1,mask | (1<<j),nums,slots)));
        }
            
           return dp[i][mask]=mx;
    }
    
};