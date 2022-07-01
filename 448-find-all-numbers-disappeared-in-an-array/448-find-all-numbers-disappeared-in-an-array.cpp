class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        
        int n=nums.size();
                
        int i=0;
        
        // applying swap sort
        
        while(i<n){
            
            if(nums[i]==i+1)
            {
                i++;
                continue;
            }
            
            int val=nums[i];
            
            while(nums[val-1]!= val){
                int val1=nums[val-1];
                nums[val-1]=val;
                val=val1;
                
            }
            i++;
        }
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            
            if(nums[i]!=i+1)
                ans.push_back(i+1);
        }
        
        return ans;
    }
};