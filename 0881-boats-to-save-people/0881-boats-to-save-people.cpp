class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int count=0;
        while(i<=j){
            if(nums[i]+nums[j]==limit){
                i++;
                j--;
                count++;    // put both i,j in boat
            }
            else if(nums[i]+nums[j]<limit){
                i++;
                j--;
                count++;  // put i,j in boat(note, no of persons in boat cannot >2)
            }
            else if(nums[i]+nums[j]>limit){
                j--;
                count++;   // put j in a boat alone
            }
            
        } 
            
        return count;
    }
};