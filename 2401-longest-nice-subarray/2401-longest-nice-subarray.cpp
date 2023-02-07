#define lln long long int

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
       
        
        int n=nums.size();
                
        lln mor=nums[0];
        
        int i=1;
        
        int ans=1;
        
        while(i<n){
            
            if((mor & nums[i])==0){
                mor=mor|nums[i];
                i++;
            }
            
            else
                
                break;
            
        }
        
        ans=i;
        
        int j=0;
        
        while(i<n){
            
            if((mor & nums[i])!=0){
                
                while(j<i && ((mor & nums[i])!=0)){
                    mor=mor^nums[j];
                    j++;
                }
            }
            
            mor=mor|nums[i];
            
            ans=max(ans,i-j+1);
            
            i++;
            
            
        }
        
        return ans;
        
    }
    
   
};