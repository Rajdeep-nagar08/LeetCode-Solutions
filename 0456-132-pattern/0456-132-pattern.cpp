class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    
        int n=nums.size();
        
        map<int,int>mp;
        
        for(int i=1;i<n;i++){
            mp[nums[i]]++;
        }
        
        
        int mn=nums[0];
        
        for(int i=1;i<n-1;i++){
            
            if(mp[nums[i]]==1)
                mp.erase(nums[i]);
            else
                mp[nums[i]]--;
            
            auto it=mp.lower_bound(nums[i]);
            
            if(it==mp.begin()){
                mn=min(mn,nums[i]);
                continue;
            }
            
            --it;
            
            int x= it->first;
            
            if(x>mn)
                return true;
            
             // cout<<i<<" "<<x<<" "<<mn<<endl;
        
            mn=min(mn,nums[i]);
        }
        
        return false;
        
    }
};