class Solution {
    private:
    
     void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int>output,int i)
     {
         if(i>=nums.size())
         {
             ans.push_back(output);
             return;
         }
         //exclude
         
         solve(nums,ans,output,i+1);
         
         //include
         
             int element=nums[i];
         output.push_back(element);
         solve(nums,ans,output,i+1);
             
     }
    
    
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        vector<int> output;
        
        solve(nums,ans,output,0);
        return ans;
    }
};