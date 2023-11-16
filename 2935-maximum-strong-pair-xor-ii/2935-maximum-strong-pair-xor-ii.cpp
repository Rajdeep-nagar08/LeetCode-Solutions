class Solution {
public:
    
    
    int maximumStrongPairXor(vector<int>& v) {
        
        
        sort(v.begin(),v.end());
        
        int ans=0;

        
        int n=v.size();
        
        
        for(int i=0;i<n;i++){
            
            int x=v[i];
            
            int idx=upper_bound(v.begin(),v.end(),2*x)-v.begin();
            
            idx--;
            
            int c=0;
            
            int i1=i+1, i2=idx;
            
            while(i1<=i2){
                ans=max(ans,v[i]^v[i1]);
                ans=max(ans,v[i]^v[i2]);
                i1++;
                i2--;
                c++;
                if(c>800)
                    break;
            }
            
        }
        
        return ans;
        
    }
};