int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

class Solution {
public:
    int n,m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& ht) {
        
        n=ht.size();
        
        m=ht[0].size();
        
        vector<vector<int>>ans;
       
        vector<vector<int>>v(n,vector<int>(m,0));
        
        vector<vector<bool>>vis1(n,vector<bool>(m,false));

        // pacific
        
        for(int i=0;i<n;i++){
           
            for(int j=0;j<m;j++){
                
               if((i==0 || j==0) && (vis1[i][j]==false)){
                
                    dfs(i,j,ht,vis1,v);
     
            }
        }
    }
        
        
        
        vector<vector<bool>>vis2(n,vector<bool>(m,false));

        
        // atlantic
        
         for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if((i==n-1 || j==m-1)  && (vis2[i][j]==false)){
                   
                    dfs(i,j,ht,vis2,v);
                    
                }
            }
        }
        
       
        /*
        
          for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                cout<<v[i][j]<<" ";
                
            }
             
             cout<<endl;
             
         }
        
        
        */
        
        
            for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
              
                if(v[i][j]==2)
                    ans.push_back({i,j});
            }
        }
        
        return ans;
        
    }
    
    
    
     void dfs(int i,int j,vector<vector<int>>&ht,vector<vector<bool>>&vis,vector<vector<int>>&v){
        
        vis[i][j]=true;
         
        v[i][j]++;
        
        
        for(int x=0;x<4;x++){
            
            int x1=i+dx[x];
            int y1=j+dy[x];
          
        if(x1<0 || y1<0 || x1>=n || y1>=m || ht[x1][y1]<ht[i][j] || (vis[x1][y1]==true))
                continue;
            
           
            dfs(x1,y1,ht,vis,v);
                
                
        }
    }
    
    
 
};