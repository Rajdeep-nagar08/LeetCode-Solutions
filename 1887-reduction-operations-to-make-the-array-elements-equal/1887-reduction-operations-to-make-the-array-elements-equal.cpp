class Solution {
public:
    int reductionOperations(vector<int>& nums) {
    int count=0;
    int n=nums.size();
    sort(nums.begin(),nums.end());
   /* (1,3,5,7) i->7,j->5 (change 5->7) count=4-3=1
       (1,3,5,5) i->5,j->3 (change both 5's to 3) count=1+(4-2)=3
       (1,3,3,3) i->3,j->1 (change all 3's to 1) count=3+(4-1)=6
        (1,1,1,1) */
     for(int i=n-1;i>0;i--){
         int j=i-1;
         if(nums[i]>nums[j])
             count=count+(n-i);

     } 
    return count;
    }
};