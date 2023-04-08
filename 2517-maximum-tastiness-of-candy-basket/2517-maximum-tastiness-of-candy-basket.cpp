class Solution {
public:
    int maximumTastiness(vector<int>& v, int k) {
        
        int n=v.size();
        
        
        if(v.size()==1 || v.size()<k)
            return 0;
        
        sort(v.begin(),v.end());
        
        int l=0,h=1e9;
        
        int ans;
        
        while(l<=h){
            
            int mid=l+(h-l)/2;
            
            if(isValid(mid,v,k)){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
    
    
    // checking if we can slect atleast k numbers from the array so that 
    
    // minimum absolute difference is greater than or equal to mid
    
    // If its possible then we can increase our mid to get maximum tastiness
    
    bool isValid(int mid,vector<int>&v,int k){
        
        
        int n=v.size();
        
        int x=v[0];
        
        int cnt=1;
        
        for(int i=1;i<n;i++){
            if(v[i]-x>=mid){
                x=v[i];
                cnt++;
            }
        }
        
        
        if(cnt>=k)
            return true;
        
        return false;
        
    }
};