class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        
        
        int n=code.size();
        
        for(int i=1;i<n;i++){
            code[i]+=code[i-1];
        }
        
        vector<int>ans(n,0);
        
        if(k>0){
            for(int i=0;i<n;i++){
                
                int j=i+k;
                
                if(j<=n-1){
                    ans[i]=code[j]-code[i];
                }
                else{
                    int j1=j-n;
                    ans[i]=code[n-1]-code[i]+(code[j1]);
                }
            }
        }
        
        
        else if(k<0){
            
            for(int i=0;i<n;i++){
                int j=i+k;
                
                if(j>=0){
                   if(j==0)
                       ans[i]=code[i-1];
                    else
                        ans[i]=code[i-1]-code[j-1];
                }
                else{
                    
                    int j1=n+j;
    
                    if(i==0)
                    ans[i]=code[n-1]-code[j1-1];

                    else
                    ans[i]=code[i-1]+code[n-1]-code[j1-1];
                    
                }
            }
        }
        
        return ans;
    }
};