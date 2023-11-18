/*

maximumfreq of any no = [1,n] == mid of binary search

Logic for isValid => sort the array and start checking from last


*/


#define lln long long int

class Solution {
public:
            
    int maxFrequency(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        vector<lln>pref(n);
        
        pref[0]=nums[0];
        
        for(int i=1;i<n;i++){
            pref[i]=nums[i]+pref[i-1];
        }
        
        int l=1, h=n;
        
        int ans=1;
        
        while(l<=h){
            int mid=(l+h)/2;
            
            if(isValid(mid,nums,k,pref)){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        
        return ans;
        
    }
    
    bool isValid(int mid, vector<int>&nums,int k,vector<lln>&pref){
            
        int n=nums.size();
        
        for(int i=n-1;i>=0;i--){
            
            lln SumNeed=1ll*nums[i]*mid;
            
            lln SumPresent;
            
            if(i-mid>=0)
            SumPresent=pref[i]-pref[i-mid];
            else if(i-mid==-1)
            SumPresent=pref[i];
            else
                break;
            
            int extra=SumNeed-SumPresent;
            
            
            if(extra<=k)
                return true;
            
        }
        
        
        return false;
        
    }
    
};