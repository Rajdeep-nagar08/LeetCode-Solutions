/*


kadan's algo


 int mx=INT_MIN;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            temp=max(temp+nums[i],nums[i]);
            mx=max(mx,temp);
        }
        return mx;
        
        
*/


class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        
        int n=nums.size();
        
        
        int mx=INT_MIN;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            temp=max(temp+nums[i],nums[i]);
            mx=max(mx,temp);
        }
        
       
         int mn=INT_MAX;
        temp=0;
        for(int i=0;i<nums.size();i++){
            temp=min(temp+nums[i],nums[i]);
            mn=min(mn,temp);
        }
        mn=abs(mn);
        mx=abs(mx);
        
        return max(mn,mx);
        
    }
};