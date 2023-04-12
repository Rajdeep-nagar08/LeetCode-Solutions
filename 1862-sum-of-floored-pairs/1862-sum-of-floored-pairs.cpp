  
        /*
        
        [x,y]
        
        x/y = 0  (if y<x)
        
        x/y = 1 (if x < 2*y and x >=y)  ,count of such x = v[2y-1]-v[y-1],       ans+= count of x
        
        x/y = 2 (if x < 3*y and x >=2*y) ,count of such x = v[3y-1]-v[2y-1]
        
  ans+= 2*count of x
  
        x/y = 3 (if x < 4*y and x >=3*y), count of such x = v[4y-1]-v[3y-1]
        
  ans+= 3*count of x
  
        */

#define lln long long int

class Solution {
public:
    
    int n;
    
    int mod=1e9+7;
    
    
    int sumOfFlooredPairs(vector<int>& nums) {
     
        
        
       n=nums.size();
        
            
        int mx=*max_element(nums.begin(),nums.end());
        
        vector<int>v(mx+1,0);
        
        // int maxFreq=0;
        
        unordered_map<int,int>mp;
        
        
        for(int i=0;i<n;i++){
            v[nums[i]]++;
            // maxFreq=max(maxFreq,v[nums[i]]);
            mp[nums[i]]++;
        }
        
        for(int i=2;i<=mx;i++){
            v[i]+=v[i-1];
        }
        
      
        
        
        lln ans=0;
        
        for(auto it:mp){
            
            int no=it.first;
            
            int y=no;
            
            int k=1;
            
            // cout<<no<<"=>";
            
            while(y<=mx){
                
                int y1=max(y-1,0);
                
                int y2=min(y+no-1,mx);
                
                lln temp=1ll*k*(v[y2]-v[y1])*mp[no]%mod;                
                
                ans=(ans%mod+temp%mod)%mod;
                
                // cout<<temp<<" "<<y2<<" "<<y1<<endl;
                
                y+=no;
                
                k++;
                
            }
            
            
            
        }
        
        
        
        return ans;
    }
};