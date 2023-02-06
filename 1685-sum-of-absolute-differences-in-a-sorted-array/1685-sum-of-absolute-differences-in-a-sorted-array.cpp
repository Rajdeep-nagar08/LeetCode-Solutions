class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n=nums.size();
        
        
        vector<int>pref(n);
        
        pref[0]=nums[0];
        
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        
        for(int i=0;i<n;i++){
            
            if(i==0)
                nums[i]=(pref[n-1]-pref[0]-nums[i]*(n-1));
            
            else if(i==n-1){
                nums[i]=abs(nums[i]*i-pref[i-1]);
            }
            
            else{
                
            int f=pref[n-1]-pref[i];
            
            int b=pref[i-1];
            
            nums[i]=abs(nums[i]*i-b)+abs(f-nums[i]*(n-i-1));
                
            }
                
        }
        
        
        return nums;
    }
};