
int mod=1e9+7;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        int n=arr.size();
        
        vector<int>pref(n),suff(n);
    
        pref[0]=arr[0];
        int mx1=pref[0];
        
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+arr[i];
            mx1=max(mx1,pref[i]);
        }
        
        suff[n-1]=arr[n-1];
        
        int mx2=suff[n-1];
        
        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]+arr[i];
            mx2=max(mx2,suff[i]);
        }
        
        int sum=pref[n-1];
        
        int total1=kadans(arr);  // considering only one array
        
        if(k==1)
            return total1;
        
        int total2=mx1+mx2; // considering only 2 array
        
       
        int total3=mx1+mx2+1ll*sum*(k-2)%mod; // taking all arrays

        
        return max({total1,total2,total3})%mod;
        
    }
    
    int kadans(vector<int>&arr){
        
        int temp=0;
        
        int mxsum=INT_MIN;
        
        for(int x:arr){
            temp=max(x,temp+x);
            mxsum=max(mxsum,temp);
            if(mxsum<0)
                mxsum=0;
        }
        
        return mxsum;
        
    }
};