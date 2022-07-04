
class Solution {
public:
    int candy(vector<int>& nums) {
      int n=nums.size();
      if(n==1)
        return 1;
      if(n==2){
        if(nums[0]==nums[1])
          return 2;
        else
          return 3;
      }

      // move greedly, cover all possible cases, once in forward direction than in backword direction
      
    
      vector<int>v(n,0);
        
      if(nums[0]<=nums[1])
        v[0]=1;
      if(nums[n-1]<=nums[n-2])
        v[n-1]=1;
      
      int i=1;
      
      while(i<n-1){
        if(nums[i]<nums[i-1] && nums[i]<=nums[i+1])
          v[i]=1;
        else if(nums[i]<=nums[i-1] && nums[i]<nums[i+1])
          v[i]=1;
        else if(v[i-1]!=0 && nums[i]>nums[i-1] && nums[i]<=nums[i+1])
          v[i]=v[i-1]+1;
        else if(v[i-1]!=0 && nums[i-1]==nums[i] && nums[i]<nums[i+1])
          v[i]=v[i-1];
        
          i++;
      }
      
        /*
        
        NOTE: if nums[0] > nums[1] 
        
        IT means v[0]=0 till now
        
        
        So handling such cases
        
        */
        
        
       i=n-2;
      
      while(i>0){
        
 if(v[i]==0 && v[i+1]!=0 && nums[i]>nums[i+1] && nums[i]<=nums[i-1])
          v[i]=v[i+1]+1;
else if(v[i]==0 && v[i+1]!=0 && nums[i]==nums[i+1] && nums[i]<nums[i-1])
          v[i]=v[i+1];
        
else if(v[i]==0 && v[i-1]!=0 && v[i+1]!=0 && nums[i]>nums[i+1] && nums[i]>nums[i-1])
          v[i]=max(v[i-1],v[i+1])+1;
        
    else if(v[i]==0 && nums[i]==nums[i+1] && nums[i]==nums[i-1])
         v[i]=1;
        
        i--;
      }
      
      if(v[0]==0)
        v[0]=v[1]+1;
      if(v[n-1]==0)
        v[n-1]=v[n-2]+1;
        
      int ans=0;
      for(int x:v){
        ans+=x;
      }
    
        return ans;
      
    }
};