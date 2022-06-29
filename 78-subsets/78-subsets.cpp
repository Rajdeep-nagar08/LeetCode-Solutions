class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
    //    sort(nums.begin(),nums.end());
        ans.clear();
        temp.clear();
        subset(nums,0);
        return ans;
    }
    
     void subset(vector<int>& nums,int i){
         ans.push_back(temp);
           for(int j=i;j<nums.size();j++){
                   temp.push_back(nums[j]);
                   subset(nums,j+1);
                   temp.pop_back();
                   
           }
     
    }
};