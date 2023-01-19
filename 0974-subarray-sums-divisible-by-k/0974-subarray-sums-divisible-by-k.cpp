class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
    
        int n=nums.size();
    
        /*
        
        
        [....s1[........s2]]
        
        divisible by k if (s2-s1)%k==0
        
        s2%k==s1%k
        
        
        
        
        */
        
        
        unordered_map<int,int>mp;
                
        mp[0]++;
        
        int cnt=0;
        
        int sum=0;
       
        for(int i=0;i<n;i++){
          
            sum+=nums[i];
            
           int mod=(sum%k+k)%k;
       
           cnt+=mp[mod];
            
            mp[mod]++;
            
         //   cout<<cnt<<endl;
            
        }
        
        return cnt;
     }
};