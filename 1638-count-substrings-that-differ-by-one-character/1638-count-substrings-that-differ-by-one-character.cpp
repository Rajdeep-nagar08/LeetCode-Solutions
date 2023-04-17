class Solution {
public:
    int countSubstrings(string s, string t) {
     
        int n=s.size();
        
        int m=t.size();
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                int k=0;
                
                int diff=0;
                
                while(i+k<n && j+k<m){
                    if(s[i+k]!=t[j+k]){
                        diff++;
                    }
                    
                    
                    if(diff==1)
                    ans++;
                    
                    
                    if(diff>1)
                        break;
                    
                    
                    k++;
                }
            }
        }
        
        return ans;
    }
};