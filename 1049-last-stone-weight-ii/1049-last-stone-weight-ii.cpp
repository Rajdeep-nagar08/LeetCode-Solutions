 /*
        
        if(x==y)
        both finishes
        
        else if(x<y)
        x finishes andweight of y becomes => y-x
    
        
        
        for each stone i , we check it with all the stones and we move with optimal one
    
       
        
        
        
// Backtracking solution (TLEEEEEEEEEEEEE)


class Solution {
public:
    
    int ans=INT_MAX;
    
    int lastStoneWeightII(vector<int>& st) {
        
        int n=st.size();
         
        
      find(0,0,st);
        
        if(ans==INT_MAX)
            return 0;
        
        return ans;
     
    }
    
    void find(int i,int count,vector<int>nums){
        
        if(count==nums.size()-1){        // n-1 stones finished, only one left
            for(int x:nums){
                if(x!=0){
                    ans=min(ans,x);
                    return;
            }
        }
    }
        
        if(i>=nums.size() || nums[i]==0 )
            return;
        
        
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]==0)
                continue;
            
            int x=nums[i];
            int y=nums[j];
            
            if(x==y)
                nums[i]=0,nums[j]=0,count+=2;
            else if(x>y)
                nums[i]=x-y,nums[j]=0,count++;
            else
                nums[i]=0,nums[j]=y-x,count++;
            
            find(i+1,count,nums);
            
            if(x==y)
                nums[i]=x,nums[j]=y,count-=2;
            else if(x>y)
                nums[i]=x,nums[j]=y,count--;
            else
                nums[i]=x,nums[j]=y,count--;
                
        
        }
        
    }
};


*/


/*

let array is [a,b,c,d] => [a-b,c-d,0,0] => [a-b-(c-d),0,0,0]

Ans= a+d-(c+b)  = minimum sum difference

let two sums are s1,s2

s1+s2= sum

Ans= s1-s2

Clearly for ans to be min , s1==s2== sum/2
or subset sum==sum2

so

for(int s=sum/2;s>=0;s++){
if(subsetSum(s)==true){
s1=s,s2=sum-s1;
ans=abs(s1-s2);
break;
}
}


subsetSum(s) = Is there any subset of array whose sum = s

dp[i][s]= Is there any subset in array [i...n-1] whose sum=s

Ans= dp[0][s]

for each element i , we have two choices either choose it for subset or not choose it

*/



int dp[31][3001];

class Solution {
public:
    
    int lastStoneWeightII(vector<int>& nums) {
       
        int sum=0;
        
        int n=nums.size();
        
        memset(dp,-1,sizeof(dp));
        
        for(int x:nums){
            sum+=x;
        }
        
      int ans=INT_MAX;
        
      //  subsetSu
        
        for(int s=sum/2;s>=0;s++){
            if(subsetSum(s,nums,0)==true){
                int s1=s;
                int s2=sum-s;
                ans=abs(s1-s2);
                break;
            }
        }
        
        return ans;
        
    }
    
  bool subsetSum(int sum,vector<int>&nums,int i){
      
      if(sum==0)
          return true;
      
      if(sum<0)
          return false;
      
      if(i>=nums.size())
          return false;
      
      if(dp[i][sum]!=-1)
          return dp[i][sum];
      
      bool c1=subsetSum(sum,nums,i+1);
      
      bool c2=subsetSum(sum-nums[i],nums,i+1);
      
      return dp[i][sum]=c1||c2;
      
  }
    
};