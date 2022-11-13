class Solution {
public:
   
   void combination(vector<vector<int>>& answer,vector<int>& subset,vector<int>& arr,int target,int i)
   {   
       
      int n=arr.size();
       
   if(i==n || target==0)
   {
       if(target==0){
           answer.push_back(subset);
           return;
       }

       return;

   }
      for(int j=i;j<arr.size();j++){
          if(j>i && arr[j]==arr[j-1]){
              continue;
          }

          if(target<arr[j])
          {
              break;
          }
          subset.push_back(arr[j]);
          combination(answer,subset,arr,target-arr[j],j+1);
          subset.pop_back();
      }

   }



    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
     {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> subset;
        combination(ans,subset,candidates,target,0); 
        return ans;
    }
};