/*

for those guys who are not quite familiar with this type of problem, please also check No.549. 
Binary Tree Longest Consecutive Sequence II to have a better understanding..

for each element in the array or on in the tree, they all carry three fields :
1) the maximum increasing / decreasing length ends at the current element,
2) its own value ,
3) the total number of maximum length,

and each time when we visit a element, we will use its own value to update the maximum increasing/decreasing lengths at the current element and use it to count the total no. of max lengths , the only difference is for array we use iteration while for tree we use recursion......

Also, for substring problem, we usually use only one for loop because for each index, we only care about the relationship between its two neighbors, while for subsequence problem, we use two for loops , because for each index, any other indexes can do something...


lis[i]=length of LIS that ends at index i
WE knows: if(nums[i]>nums[j]) 
      lis[i]=max(lis[i],1+lis[j]) for each (i=0 to i<n) and (j=0 to j<i)
      or 
      lis[i] remains lis[i] if(lis[i]==1+lis[j])
      lis[i]=1+lis[j] if(lis[i]<1+lis[j])
  
count[i]= no of LIS that ends at index i
if(nums[i]>nums[j])
  if(lis[i]==1+lis[j]) then it means length of lis ends at index i =length of lis ends at index j + incluing current element
  so no of lis that ends upto index i=count[i]=count[i]+count[j]
  
  if(lis[i]<1+lis[j])
  then count[i]=count[j]
  
  
  
  ANS= SUM of all count[i] if lis[i]=max lis
  
*/


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
      int n=nums.size();  
     
      vector<int>lis(n);
      vector<int>count(n);
      
      for(int i=0;i<n;i++){
        lis[i]=count[i]=1;
        for(int j=0;j<i;j++){
          if(nums[i]>nums[j]){
  
            if(lis[i]==1+lis[j])
              count[i]=count[i]+count[j];
            else if(lis[i]<1+lis[j]){
              lis[i]=1+lis[j];
              count[i]=count[j];
            }
          }
        }
        
      }
      
      
      int mxlis=INT_MIN;
      
      
      for(int i=0;i<n;i++)
        mxlis=max(mxlis,lis[i]);
      
      int c=0;
      for(int i=0;i<n;i++){
        if(lis[i]==mxlis)
          c+=count[i];
      }

      return c;
    }
  
};
  
  
  
  
  
  
  
  
  