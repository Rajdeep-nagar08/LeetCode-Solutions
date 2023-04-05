class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        
        int n=arr.size();
        
        vector<int>dp1(n,0),dp2(n,0);
        
        for(int i=0;i<n;i++){
            dp1[i]=1;
            dp2[i]=1;
        }
        
        int ans=1;
        
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                if(i%2==0){  // even
                    dp1[i]=dp1[i+1]+1;
                }
                else{  // odd
                    dp2[i]=dp2[i+1]+1;
                }
                
            }
            else if(arr[i]>arr[i+1]){
                if(i%2==0){
                    dp2[i]=dp2[i+1]+1;
                }
                else{
                    
                    dp1[i]=dp1[i+1]+1;
                }
            }
        }
        
        
        for(int i=0;i<n;i++){
            ans=max({ans,dp1[i],dp2[i]});
        }
        
        return ans;
    }
};