class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n=nums.size();
    
        vector<int>v(nums);
        
        // reverse(n.begin(),v.end());
        
        vector<int>lis1=find1(nums);
        
        reverse(v.begin(),v.end());
        
        vector<int>lis2=find1(v);
        
        // reverse(lis2.begin(),lis2.end());

        int ans=n;
        
        for(int i=1;i<n-1;i++){
           if(lis1[i]>1 && lis2[n-1-i]>1)
            ans=min(ans,n-(lis1[i]+lis2[n-1-i])+1);
        }
        
      //  ans=min({ans,lis1[n-1],lis2[0]});
        
        for(int x:lis1){
            cout<<x<<" ";
        }
        
        cout<<endl;
        
        
         for(int x:lis2){
            cout<<x<<" ";
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