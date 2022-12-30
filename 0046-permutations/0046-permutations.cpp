class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
      vector<vector<int>>ans;
      
      find(0,nums,ans);
      return ans;
    }
  
     void find(int start,vector<int>&nums,vector<vector<int>>&ans){
       if(start==nums.size()){
         
         ans.push_back(nums);
           
         return;
       }
       
          for(int i=start;i<nums.size();i++){
           swap(nums[start],nums[i]);
            find(start+1,nums,ans);
            swap(nums[start],nums[i]);
         }
     }
    
 };
