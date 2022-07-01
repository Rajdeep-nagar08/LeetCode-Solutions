class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        
        int n=nums.size();
        
        vector<int>ans(n,0);
        
        for(int i=0;i<n;i++){
            ans[nums[i]-1]++;
        }
                
        for(int i=0;i<n;i++){
            if(ans[i]==0)
                nums[i]=-1;
        }
        
        ans.clear();
        
        for(int i=0;i<n;i++){
        //    cout<<nums[i]<<" ";
            if(nums[i]==-1)
                ans.push_back(i+1);
        }
        
        return ans;
    }
};