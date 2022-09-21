class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& quer) {
                
        int odd=0,even=0;
        
        for(int x:nums){
            if(x%2)
                odd+=x;
            else
                even+=x;
        }
        
        vector<int>ans;
        
        for(auto &it:quer){
            
            int val=it[0];
            
            int idx=it[1];
            
            if(nums[idx]%2==0){
              
                if(val%2==0){
                    even+=val;
                    nums[idx]+=val;
                }
                else{
                    even-=nums[idx];
                    odd+=nums[idx]+val;
                    nums[idx]+=val;
                }
            }
            
            else{
                
                if(val%2){
                    even+=val+nums[idx];
                    odd-=nums[idx];
                    nums[idx]+=val;
                }
                
                
                else{
                    odd+=val;
                    nums[idx]+=val;
                }
                
                
            }
            
            /*
            for(int x:nums){
                cout<<x<<" ";
            }
            
            cout<<endl;
            */
            
            ans.push_back(even);
        }
        
        return ans;
    }
};