class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n=nums.size();
        
        int i=0;
        
        while(i<n){
            int j=i;
            
            if(nums[j]==j){
                i++;
                continue;
            }
            
            int x=nums[j];
            
            while(x<n && nums[x]!=x){
                int y=nums[x];
                nums[x]=x;
                x=y;
            }
            i++;
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]!=i)
                return i;
        }
        
        return n;
    }
};