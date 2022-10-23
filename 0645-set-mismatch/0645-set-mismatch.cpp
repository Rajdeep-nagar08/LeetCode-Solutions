class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int s=1;
        
        int x=-1,y=-1;
        
        for(int i=0;i<n;i++){
            if(x==-1 && nums[i]==nums[i+1]){
                x=nums[i];
            }
            
            else if(y==-1 && nums[i]!=s){
                y=s;
                s++;
            }
            else
                s++;
        
        }
        
        if(y==-1)
            y=n;
        
        return {x,y};
    }
    
    
};