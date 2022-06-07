class Solution {
public:
    void merge(vector<int>& nums, int m, vector<int>& v2, int n) {
        
      vector<int>v1(m);
      for(int i=0;i<m;i++)
        v1[i]=nums[i];
      
      int i=0,j=0,k=0;
      
      while(i<m && j<n){
        if(v1[i]<v2[j])
          nums[k++]=v1[i++];
          
        else
          nums[k++]=v2[j++];   
      }
      
      while(i<m)
        nums[k++]=v1[i++];
        
      while(j<n)
        nums[k++]=v2[j++];
      
    }
};