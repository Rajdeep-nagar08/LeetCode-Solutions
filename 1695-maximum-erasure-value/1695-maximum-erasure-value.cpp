class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        
        int n=nums.size();
        
        int i=0;
        
        int j=0;
        
        unordered_map<int,int>mp;
        
        int ans=0,sum=0;
        
        while(i<n){
            if(mp[nums[i]]==1){
                break;
            }
            mp[nums[i]]++;
            sum+=nums[i];
          
            i++;
        }
        
        ans=max(ans,sum);
        
        
        while(i<n){
            
            if(mp[nums[i]]==1){
                while(j<i && (mp[nums[i]]==1)){
                    sum=sum-nums[j];
                    mp[nums[j]]--;
                    j++;
                }
            }
            
            sum+=nums[i];
            mp[nums[i]]++;
            

            ans=max(ans,sum);
            i++;
        }
        
        return ans;
    }
};

//  5 7 8 3 8 10 10 12 17 