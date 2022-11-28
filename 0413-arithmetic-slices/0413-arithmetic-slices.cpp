class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n=nums.size();
      
      int sum=0;
        
      int curr=0;
      
      for(int i=2;i<n;i++){
        if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
          curr++;
          sum=sum+curr;
        }
          else
            curr=0;
      }
  
      return sum;
    }
};

/*
love the "curr += 1; sum += curr;" very much, that is amazing!!
For those guys who are confused about these two line:
"curr" the number of different "Arithmetic Slices" ends at index = i
a small example :
we have :[1, 2, 3, 4]
index = 2, we have curr = 1, sum = 1, which is [1,2,3];
index = 3, curr = 2, sum = 2 + 1 = 3; because we look back from index = 3 which is 4 , we will have two "Arithmetic Slices", which is [2,3,4] and [1,2,3,4]...

*/