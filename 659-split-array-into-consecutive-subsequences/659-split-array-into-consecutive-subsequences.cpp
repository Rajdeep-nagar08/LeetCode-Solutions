class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        int n=nums.size();
        
        unordered_map<int,int>mp;
        
        for(int x:nums){
            mp[x]++;
        }
        
        
        // finish[no] = no of subsequences that finishes at no
        
        unordered_map<int,int>finish;
        
        for(int i=0;i<n;i++){
            
            int curr=nums[i];
            
          if(mp[curr]<=0)
              continue;
            
            mp[curr]--;
            
            int prev=curr-1;
            
            if(finish[prev]>0){
                finish[prev]--;
                finish[curr]++;
            }
            else{
                if(mp[curr+1]>0 && mp[curr+2]>0){
                   mp[curr+1]--;
                   mp[curr+2]--;
                   finish[curr+2]++;
                }
                else
                    return false;
            }
        }
        
        return true;
        
    }
};