#define lln long long int
class Solution {
public:
    vector<int> successfulPairs(vector<int>& sp, vector<int>& po, long long succ) {
        
        int n=sp.size();
        
        int m=po.size();
        
        vector<int>ans(n);
        
        sort(po.begin(),po.end());
        
        for(int i=0;i<n;i++){
        
            lln need=succ/sp[i];
            
            int idx=lower_bound(po.begin(),po.end(),need)-po.begin();
            
            if(idx<m){
                
                lln val=po[idx];
                
                if(1ll*val*sp[i]>=succ){
                    int count=m-idx;
                    ans[i]=count;
                }
                else{
                     int idx1=upper_bound(po.begin(),po.end(),val)-po.begin();
                     if(idx1 <m){
                         int count2=m-idx1;
                         ans[i]=count2;
                     }
                    else{
                        ans[i]=0;
                    }
                }
            }
            
            else{
                
                ans[i]=0;
                
            }
            
            
        }
        
        return ans;
    }
};