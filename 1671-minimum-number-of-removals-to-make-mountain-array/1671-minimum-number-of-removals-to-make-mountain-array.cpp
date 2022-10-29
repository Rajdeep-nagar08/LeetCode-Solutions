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
    
    vector<int> find1(vector<int>&v){
        
        vector<int>ans(v.size(),0);
        
        
        for(int i=0;i<v.size();i++){
        
             int mx=1;
            
             for(int j=0;j<i;j++){
                 
                 if(v[j]<v[i])
                     mx=max(mx,1+ans[j]);
             }
            ans[i]=mx;
        }
        
        return ans;
        
    }
    
 
};