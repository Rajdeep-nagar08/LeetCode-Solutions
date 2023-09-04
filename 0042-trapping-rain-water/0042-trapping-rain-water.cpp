class Solution {
public:
    int trap(vector<int>& ht) {
        
        
        int n=ht.size();
        
        
        int ans=0;
        
        int mxL=ht[0],i=1;
        
        int mxR=ht[n-1],j=n-2;
        
        while(i<=j){
            
            
            if(mxL<mxR){
                
                if(ht[i]<mxL){
                    ans+=mxL-ht[i];
                }
                else{
                    mxL=ht[i];
                }
                
                i++;
                
            }
            
            else if(mxL>=mxR){
                
                if(ht[j]<mxR){
                    ans+=mxR-ht[j];
                }
                else{
                    mxR=ht[j];
                }
                
                j--;
                
            }
            
        }
        
        return ans;
    }
};