class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        
        int i=0;
        int sz=nums.size();
        
        while(i<sz){
            if(nums[i]==1)
                i=i+2;
            else if(nums[i]==0){
                if(i==sz-1 || (i+1<=sz-1 && nums[i+1]==0)){
                    n--;
                    i=i+2;
                }
                  else
               i++;
            }
        }
                   
             return n<=0;      
                
                   }
};
        
/*
... 1
.... 1
.....2
......2
.......3

[0,0,1,0,0]
1 , true 
*/