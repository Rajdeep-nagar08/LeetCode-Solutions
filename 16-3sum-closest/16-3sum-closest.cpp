class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        int mn=INT_MAX;
        int clos;
        for(int i=0;i<=n-3;i++){
            
          //  if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                
                int l=i+1;
                int r=n-1;
                while(l<r){
                    int a=nums[l];
                    int b=nums[r];
                  
                  if(abs(a+b+nums[i]-target)<mn){
                     mn=abs(a+b+nums[i]-target);
                     clos=a+b+nums[i];
                  }
                  
                  if(a+b+nums[i] <target)
                      l++;
                  else if(a+b+nums[i] >target)
                      r--;
                  
                  else if(a+b+nums[i]==target)
                    return a+b+nums[i];
                    
                  
                }
            }
        
           return clos;
    }
};