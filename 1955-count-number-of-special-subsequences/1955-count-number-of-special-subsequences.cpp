 /*
 
 0 0 0..... 1 1 1..... 2 2 2 2.....

count of such types of subsequencies

       
       for each nums[i] , we have two choices , either include it in the
       
       sequence or not include , not include it in the sequency if it
       
dissatified the mentioned properties, otherwise include it in the sequence
       
      dp[i][z][o][t][count] = number of valid sequences formed by [i...n-1]
      
      if previous included number is either zero or one or two and 
      
      count = 0 if atleast single '0' is included till now
      
      count = 1 if atleast single '1' is included till now
      
      count = 2 if atleast single '2' is included till now
      
      ,
      
      if previous number was zero, than next number should be either zero or one, 
      
      if previous number was 1one, then next number should be either one or two,
      
      if previous number was two, then next number should be two only
       
       */
      

#define lln long long int

lln dp[100001][2][2][2][3];       

int mod=1e9+7;

class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        
        
        int n=nums.size();
        
       memset(dp,-1,sizeof(dp));
        
        return find(0,0,0,0,0,nums)%mod;
      
    }
    
    lln find(int i,int z,int o,int t,int count,vector<int>&nums){
        
        if(i>=nums.size()){
            if(count==2)
                return 1;
            
            return 0;
        }
        
        if(dp[i][z][o][t][count]!=-1)
            return dp[i][z][o][t][count];
        
        lln c1=0,c2=0,c3=0;
            
            c1=c1+find(i+1,z,o,t,count,nums);  // not taking anything
        
        if(z==0 &&  o==0 && t==0){        // no zero till now
            if(nums[i]==0)                // taking first zero
                c2=c2+find(i+1,1,0,0,0,nums);
        }
        else if(z==1){            // have atleast one zero
            
            if(nums[i]==0)        // taking another zero
                c2=c2+find(i+1,1,0,0,0,nums);
              
            if(nums[i]==1)        // taking one
                c3=c3+find(i+1,0,1,0,1,nums);
            
        }
        else if(o==1){      // have atleast single '1'
            
            if(nums[i]==1)   // taking another 1
                c2=c2+find(i+1,0,1,0,1,nums);
            
            if(nums[i]==2)   // taking 2
                c3=c3+find(i+1,0,0,1,2,nums);
            
        }
        else if(t==1){
            
            if(nums[i]==2)  // taking another 2
                c2=c2+find(i+1,0,0,1,2,nums);
            
        }
        
        return dp[i][z][o][t][count]=(c1+c2+c3)%mod;
    }
};