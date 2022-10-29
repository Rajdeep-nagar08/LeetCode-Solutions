class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n=nums.size();
    
        vector<int>v(nums);
                
        vector<int>lis1=find1(nums);
        
        reverse(v.begin(),v.end());
        
        vector<int>lis2=find1(v);
        
        int ans=n;
        
        reverse(lis2.begin(),lis2.end());
        
        for(int i=1;i<n-1;i++){
            
           if(lis1[i]>1 && lis2[i]>1)
          ans=min(ans,n-(lis1[i]+lis2[i])+1);
            
        }
        
        if(ans==n)
            return 0;
        
        return ans;
        
    }
    
        
       vector<int> find1(vector<int>& nums) {
        
          int n=nums.size();

           vector<int>ans1(n);
           
            vector<int>ans;
        
        
        for(int i=0;i<n;i++){
            
            if(ans.size()==0 || nums[i]>ans[ans.size()-1])
                ans.push_back(nums[i]);
            
            auto it=lower_bound(ans.begin(),ans.end(),nums[i]);
            
            *it=nums[i];
            
            ans1[i]=(int)ans.size();
        }
        
    
         return ans1;
        
       }
    
 
};