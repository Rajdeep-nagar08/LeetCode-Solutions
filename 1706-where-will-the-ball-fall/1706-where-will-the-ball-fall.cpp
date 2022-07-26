class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        
        int n=grid.size();
        
        int m=grid[0].size();
        
        
        // ans[i] = column in which ball at column i lands down
        
        vector<int>ans(m);
        
        for(int j=0;j<m;j++){
                        
            
            if(j==0 && (grid[0][j]==-1)){
                ans[j]=-1;
                continue;
            }
            
            if(j==m-1 && (grid[0][j]==1)){
                ans[j]=-1;
                continue;
            }
            
            bool flag=true;
            
            int r=0;

            int c=j;
            
            while(r>=0 && r<n && c>=0 && c<m){
                if(grid[r][c]==1 && (c+1<m)){
                    if(grid[r][c+1]==1){
                        r++,c++;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
                else{
                    if((c-1>=0) && grid[r][c-1]==-1){
                        r++,c--;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
                
               
            }
            
            if(flag==false)
                ans[j]=-1;
            else
                ans[j]=c;
            
        }
        
        
        return ans;
        
    }
};