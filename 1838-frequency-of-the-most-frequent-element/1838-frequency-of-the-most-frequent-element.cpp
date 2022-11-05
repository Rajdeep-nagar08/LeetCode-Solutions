/*




*/


#define lln long long int

class Solution {
public:
    
//    unordered_map<int,int>mp;
    
    vector<lln>pref;
    
    
    int n;
    
    int maxFrequency(vector<int>& nums, int k) {
        
        n=nums.size();
        
        sort(nums.begin(),nums.end());
  
        pref.resize(n,0);
        
        pref[0]=nums[0];
        
        for(int i=1;i<n;i++){
            pref[i]+=pref[i-1]+nums[i];
        }
        
//          for(int x:nums){
//              mp[x]++;       
//          }
        
        int l=1,h=n;
        
        int ans=1;
        
        while(l<=h){
            
            int mid=(l+h)/2;
            
            if(check(mid,nums,k)){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        
        return ans;
      
    }
    
    bool check(int mid,vector<int>&nums,int k){
                
        int i=1;
        
        int no,need,prev;
        lln sum,diff;
        
        while(i<n){
            
            no=nums[i];
        
            need=mid-1;
            
            prev=i-need;
            
            if(prev<0)
            {
                i++;
                continue;
            }     
            
            sum;
            
            if(prev==0)
                sum=pref[i-1];
            else
                sum=pref[i-1]-pref[prev-1];
            
            diff=1ll*need*no-(sum);
            
            if(diff<=k)
                return true;
            
            i++;
            
        }
        
        return false;
    }
};