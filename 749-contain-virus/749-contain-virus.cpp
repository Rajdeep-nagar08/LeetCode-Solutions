class Solution {
public:
    int n,m;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    
    int containVirus(vector<vector<int>>& grid) {
        
        n=grid.size();
        m=grid[0].size();
        
        int ans=0;
       
        while(true){
            
    // checking a component that cose max cell to damage
            
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int c=0;
        int w=0;
        int i1,j1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false && grid[i][j]==1){
                    q.push({i,j});
                    int cell=0;
                    int wall=0;
                    vector<vector<bool>>vis1(n,vector<bool>(m,false));
                    dfs1(i,j,grid,vis,vis1,cell,wall);
                    if(cell>c){
                        c=cell,w=wall,i1=i,j1=j;
                    }
                  //  cout<<wall<<" "<<i<<" "<<j<<endl;
                   // return 13;
                }
            }
        }
       
    
      // blocking maxium damage component
        if(c==0)
            break;
        ans+=w;
            
        vector<vector<bool>>vis2(n,vector<bool>(m,false));
        block(i1,j1,grid,vis2);
            
     // expanding other components by one unit outward
        vector<vector<bool>>vis3(n,vector<bool>(m,false));
         while(q.size()>0){
             int i=q.front().first;
             int j=q.front().second;
             q.pop();
             if(i==i1 && j==j1)
                 continue;
               if(vis3[i][j]==false && grid[i][j]==1){
                    dfs2(i,j,grid,vis3);
               } 
            }
             
    }
        
        return ans;
        
        
    }
    
    
    void dfs1(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&vis,vector<vector<bool>>&vis1,int &cell,int &wall){
        
        vis[i][j]=true;
        
        for(int x=0;x<4;x++){
            int i1=i+dx[x];
            int j1=j+dy[x];
            if(i1<n && j1<m && i1>=0 && j1>=0 && grid[i1][j1]==0){
                wall++;
                if(vis1[i1][j1]==false){
                vis1[i1][j1]=true;
                cell++;
                }
            }
            
            if(i1<n && j1<m && i1>=0 && j1>=0 && vis[i1][j1]==false && grid[i1][j1]==1){
               dfs1(i1,j1,grid,vis,vis1,cell,wall); 
            }
            
        }
    }
    
    
      void block(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&vis){
        
        vis[i][j]=true;
        grid[i][j]=-1;
        
        for(int x=0;x<4;x++){
            int i1=i+dx[x];
            int j1=j+dy[x];
    
            if(i1<n && j1<m && i1>=0 && j1>=0 && vis[i1][j1]==false && grid[i1][j1]==1){
               block(i1,j1,grid,vis); 
            }
            
        }
    }
    
    
     void dfs2(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&vis){
        
        vis[i][j]=true;
        
        for(int x=0;x<4;x++){
            int i1=i+dx[x];
            int j1=j+dy[x];
            if(i1<n && j1<m && i1>=0 && j1>=0 && vis[i1][j1]==false && grid[i1][j1]==0){
                vis[i1][j1]=true;
                grid[i1][j1]=1;
            }
            
            if(i1<n && j1<m && i1>=0 && j1>=0 && vis[i1][j1]==false && grid[i1][j1]==1){
               dfs2(i1,j1,grid,vis); 
            }
            
        }
    }
    
    
    
    
};