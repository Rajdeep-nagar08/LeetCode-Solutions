/*

size of array at time t = sizet >= nums[t]

space wasted at time t= sizet-nums[t]

We can resize the array atmost k times

minimum total space wasted = ?


At each index , if size==nums[i] , no problem , space wasted = 0

otherwise we have two choices: 1) make size ==nums[i] and do k-- ,space wasted=0
                               2) Not do anything , space wasted= size-nums[i]
                               
  
So we have choices whether to use k or not

what should be the initial size of the array = ?
  
 nums.size() = 200
 
 k = 200
 
 dp[i][k] = min space wasted for [i..n-1] if we can change size k times
 
 But Is it optimal to change sz to nums[i] ?

 NO.
 
 Becouse it may happens that if you changes sz to nums[i] than sz may not be      optimal for next numbers
 
 So while we changing sz , we should try all possible ways
 
 sz= max(i,i+1,i+2...n-1)
 
 than wast corresponding to [i....j] = max[i..j]*(j-i+1) - sum[i...j]

  
*/

int dp[201][201];

class Solution {
public:
    
    int n;
    
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        
        n=nums.size();
        
        memset(dp,-1,sizeof(dp));
        
        return find(0,k,nums);
    }
    
    int find(int i,int k,vector<int>&nums){
        
        if(i>=n){
            return 0;
        }
        
        if(k<0)
            return 1e8;
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        int sum=0, mx=0;
        
        int c=1e8;
        
        for(int j=i;j<n;j++){
            
            sum+=nums[j];
                        
            mx=max(mx,nums[j]);
            
            int waste=mx*(j-i+1)-sum;
            
            c=min(c,waste+find(j+1,k-1,nums));
            
            
        }
        
        return dp[i][k]=c;
        
    }
        
};