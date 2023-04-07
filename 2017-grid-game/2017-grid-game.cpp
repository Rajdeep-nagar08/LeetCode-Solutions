#define lln long long int


class Solution {
public:
    int n,m;
    
    long long gridGame(vector<vector<int>>& grid1) {
      
        m=grid1.size();
        
        n=grid1[0].size();
        
        lln mx=0;
                
        vector<vector<lln>>grid(2,vector<lln>(n));
        

        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                grid[i][j]=grid1[i][j];
                
                
            }
        }
        
        for(int i=1;i<n;i++){
            grid[0][i]+=grid[0][i-1];
            grid[1][i]+=grid[1][i-1];
        }
        
      
        
        lln mx1=0,mx2=0;
        
        vector<lln>v;
        
        for(int i=0;i<n;i++){
            
            lln a,b;
            
            if(i==0){
                
                a=grid[0][n-1]-grid[0][0];
                
                b=0;
            }
            
            else if(i==n-1){
                
                a=0;
                
                b=grid[1][n-1]-grid1[1][n-1];
            }
            
            else{
                
               a=grid[0][n-1]-grid[0][i];
                
               b=grid[1][i-1];
                
            }
            
            
             lln mx=max(a,b);
            
             v.push_back(mx);
             
            
        }        
        
        
        sort(v.begin(),v.end());
        
        return v[0];
        
        // return mx2;
    }
};