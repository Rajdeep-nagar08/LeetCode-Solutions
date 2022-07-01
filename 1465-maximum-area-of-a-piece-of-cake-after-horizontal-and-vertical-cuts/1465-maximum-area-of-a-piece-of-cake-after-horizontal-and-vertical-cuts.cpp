#define lln long long int

int mod=1e9+7;

class Solution {
public:
    int maxArea(int h, int w, vector<int>&hC, vector<int>& vC) {
        
       sort(hC.begin(),hC.end());
        
        sort(vC.begin(),vC.end());
        
        int n=hC.size();
        
        int mxH=max(hC[0],h-hC[n-1]);
      
        
        for(int i=1;i<n;i++){
            mxH=max(mxH,hC[i]-hC[i-1]);
        }
        
        int m=vC.size();
        
        int mxW=max(vC[0],w-vC[m-1]);
        
        for(int i=1;i<m;i++){
            mxW=max(mxW,vC[i]-vC[i-1]);
        }
        
        lln ans=(1ll*mxH*mxW)%mod;
        
        return ans;
        
    }
};