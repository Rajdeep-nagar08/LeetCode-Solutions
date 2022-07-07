class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
               
       vector<vector<int>>v(n,vector<int>(n,1));
        
        
        for(auto it:mines){
            v[it[0]][it[1]]=0;
        }
        
      
        int mx=0;
                
        for(int i=n/2;i<n;i++){
            for(int j=0;j<n;j++){
                
                int k=0;
                
                int mnl=min({i,j,n-1-i,n-1-j});
                
                if(mnl+1<=mx)
                    continue;
                
                while(i+k<n && i-k>=0 && j+k<n && j-k>=0){
                    
    if(v[i][j+k]!=1 || v[i][j-k]!=1 || v[i+k][j]!=1 || v[i-k][j]!=1)
                        break;
                    
                    k++;
                }
                
            
                mx=max(mx,k);
                
                
            }
        }
        
        
        
        
         for(int i=0;i<=n/2;i++){
            for(int j=0;j<n;j++){
                
                int k=0;
                
                int mnl=min({i,j,n-1-i,n-1-j});
                
                if(mnl+1<=mx)
                    continue;
                
                while(i+k<n && i-k>=0 && j+k<n && j-k>=0){
                    
    if(v[i][j+k]!=1 || v[i][j-k]!=1 || v[i+k][j]!=1 || v[i-k][j]!=1)
                        break;
                    
                    k++;
                }
                
            
                mx=max(mx,k);
                
                
            }
        }
        
        
        return mx;
        
    }
};