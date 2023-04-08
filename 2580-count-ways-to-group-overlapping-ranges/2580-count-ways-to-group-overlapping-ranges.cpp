
#define ll long long int

int mod=1e9+7;

class Solution {
public:
    int countWays(vector<vector<int>>& arr) {
     
        
        
        vector<vector<int>>v;
        
        int n=arr.size();
        
        
         sort(arr.begin(),arr.end());
        
        
        
        v.push_back(arr[0]);
        
        int i=1;
        
        
        
        while(i<n){
            
            
            int sz=v.size();
            
            
                       int r=v[sz-1][1];

            
           int l=v[sz-1][0];
            
            
      if((arr[i][0]<=l && arr[i][1]>=l)|| (arr[i][0]>=l && arr[i][1]<=r ) || (arr[i][0]<=r && arr[i][1]>=r)){
          
          
          
           v[sz-1][1]=max(r,arr[i][1]);

          
          
 v[sz-1][0]=min(l,arr[i][0]);
          
          
          
      }
            
            else
                v.push_back(arr[i]);
            
            
            i++;
        }
          
        
        int m1=v.size();
                
        
      ll v1=power1(2,m1,mod) %mod;
        
        
        return v1%mod;
        
           
    }
    
    
    
 ll power1(ll b, ll n,ll m){ 
        if (n == 0) 
            return 1;
     
     
        ll u = power1(b,n/2,m);
        u = (1ll*u*u)%m;
     
     
        if(n%2 == 1)
            
            
         u = (1ll*u*b)%m;
        return u;
    }

};