class Solution {
  set<vector<int>>st;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>temp;
      find(0,nums,temp);
      return vector<vector<int>>(st.begin(),st.end());
      
    }
  
    void find(int start,vector<int>nums,vector<int>temp){
      
      if(temp.size()>=2){
        st.insert(temp);
      }
      
      if(start==nums.size()){
        return;
      }
      
      for(int i=start;i<nums.size();i++){
        if(temp.size()==0 || nums[i]>=temp[temp.size()-1]){
          temp.push_back(nums[i]);
          find(i+1,nums,temp);
          temp.pop_back();
        }
    }
 }
};