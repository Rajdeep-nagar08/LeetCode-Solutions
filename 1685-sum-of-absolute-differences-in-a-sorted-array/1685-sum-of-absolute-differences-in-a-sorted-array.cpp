
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        
        
        int n=nums.size();
        
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        vector<int>ans(n);
        
        int prev=0;
        
        for(int i=0;i<n;i++){
            sum-=nums[i];
            if(i==0){
                ans[i]=sum-(n-1)*nums[i];
            }
            else if(i==n-1){
                 ans[i]=(n-1)*nums[i]-prev;  
            }
            else{
                ans[i]=sum-(n-1-i)*nums[i] + i*nums[i]-prev;
            }
            prev+=nums[i];
        }
        return ans;
    }
};