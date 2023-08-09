   
        class Solution {
public:
    int minimizeMax(vector<int>& v, int k1) {
     
         k1=k1*2;
        
        sort(v.begin(),v.end());
        
        int l=0,h=1e9;
        
        
     int n=v.size();
        
        
       
        int ans;
        
        while(l<=h){
            
            int mid=l+(h-l)/2;
            
            if(Valid(mid,v,k1)){
                
                                h=mid-1;

                
                
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    
    bool Valid(int mid,vector<int>&v,int k){
        
        
      bool f=false;
        
        int i=0;
        
        
        int count=0;
        
        int n=v.size();
     
        
        while(i<n-1){
            
            if(v[i+1]-v[i]<=mid){
                
                
                count+=2;
                
                
                i+=2;
            }
            else
                i++;
            
        }
        
        
        if(count>=k)
            return true;
        
        
        return false;
        
    }

        };