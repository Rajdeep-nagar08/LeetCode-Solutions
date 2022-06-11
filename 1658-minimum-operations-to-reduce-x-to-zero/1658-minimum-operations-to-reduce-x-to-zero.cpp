/*
        let sum from front = sum , than to make total sum=x , sum need=x-sum
        using binary search find need from back
    
    */
        

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      
        int n=nums.size();
        
        int ans=INT_MAX;
        
        
        vector<int>pref(n,0);
        pref[0]=nums[n-1];
        for(int i=n-2;i>=0;i--){  // prefix sum from back
            pref[(n-1)-i]=pref[(n-1)-i-1]+nums[i];
        }
        
        if(pref[n-1] < x)
            return -1;
        
        int sum=0;
        int idx;
        int i=lower_bound(pref.begin(),pref.end(),x)-pref.begin();
          if(i!=-1 && i<n && pref[i]==x)
            ans=min(ans,i+1);
                

        for(int idx=0;idx<n;idx++){
                sum+=nums[idx];
                if(sum==x)
                    ans=min(ans,idx+1);
            
               else if(sum>x)
                   break;
            
                else{
                  int need=x-sum;
                  i=lower_bound(pref.begin(),pref.end(),need)-pref.begin();
                    if(i!=-1 && i<n && pref[i]==need)
                        ans=min(ans,idx+1+i+1);
                }
            }
        
        return ans==INT_MAX?-1:ans;
      
    }
   
};