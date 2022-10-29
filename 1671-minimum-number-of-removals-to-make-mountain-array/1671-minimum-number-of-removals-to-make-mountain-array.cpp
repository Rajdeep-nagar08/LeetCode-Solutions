class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        
        int n=arr.size();
        
        /*
        
        [increasing.......(peak)....decreasing]
        
        Ans:
        [LIS(length=l1)....(peak).....LDS(length=l2)]=mountain array of length l1+1+l2
        
        minimum removals = n-(l1+l2+1);
        
        Lis[i]=length of longest incresing subsequence ends at index i
        
        Lds[i]=length of longest decreasing subsequence ends at index i
        
        so for each index i=1,n-1 Calculate LIS on left of i
        
        and for each i=n-2,0 Calculated LDS on rigth of i
        
        than for each index i
        ans=max(ans,n-(LIS[i]+LDS[i]+1))    
        
        */
        
        vector<int>LIS(n,1);
        
        vector<int>LDS(n,1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i])
                   LIS[i]=max(LIS[i],1+LIS[j]);
                }
            }
            
             for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(arr[j]<arr[i])
                   LDS[i]=max(LDS[i],1+LDS[j]);
                }
            }
        
        
        int ans=1;
        
        for(int i=1;i<n-1;i++){
            int l=LIS[i];
            int r=LDS[i];
            if(l>1 && r>1)
            ans=max(ans,l+r-1);
        }
        
        return n-ans;
    }
};