     // For each column, finding the number of consecutive ones ending at each position.

    // sorting each row in decreasing order , grid[i][j]= max height of ones in column j that ends at [i,j]

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
    
        int m=grid[0].size();
        
        int mx=0;
        
     // For each column, finding the number of consecutive ones ending at each position.
                
        for(int j=0;j<m;j++){
            
           int i=0;
            
            while(i<n){
                
           if(grid[i][j]==0 || i==0){
               i++;
               continue;
           }
            
          while(i<n && (grid[i][j]==1)){
              grid[i][j]+=grid[i-1][j];
              i++;
             }
        
            }
           
        }
        
        
       vector<int>v(m);
        for(int i=0;i<n;i++){
            
            
            for(int j=0;j<m;j++){
                v[j]=grid[i][j];
            }
            
            // sorting each row
            sort(v.rbegin(),v.rend());
            
            int area=0;
            
            for(int j=0;j<m;j++){
                int ht=v[j];
                int wt=(j+1);
                area=max(area,ht*wt);
            }
            
            mx=max(mx,area);
            
        }
        
     
        return mx;
    }
};