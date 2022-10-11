class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
      if(n<3)
        return false;
      
  /*
   start from n1=INT_MAX,n2=INT_MAX
  return true if n1<n2< (ANY NO ahead of n1 and n2) otherwise update n1,n2 accordingly
  */
      
      int n1=INT_MAX;
      int n2=INT_MAX;
      for(int no:nums){
        if(n1< n2 && n2 <no)
          return true;
        
        if(n1>=no)
          n1=no;
        else if(n2>=no)
          n2=no;
      }
        return false;
    }
        
};