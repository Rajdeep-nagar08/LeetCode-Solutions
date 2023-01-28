
class Solution {

    public:
       
    unordered_map<int,unordered_map<int,int>>rnc,cnc;
    
        vector<int>rowMax;
        
        vector<int>colMax;
    
        vector<vector<int>>v;
    
    unordered_map<int,unordered_map<int,pair<int,int>>>mp;

    int n,m;
    
   // vector<bool>row,col;
    
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& mat) {
        
        rnc.clear();
        
        cnc.clear();
        
        mp.clear();
        
        n=mat.size();
        
        m=mat[0].size();
       
        rowMax.resize(n,0);
        
        colMax.resize(m,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v.push_back({mat[i][j],i,j});
                rnc[i][mat[i][j]]++;
                cnc[j][mat[i][j]]++;
            }
        }
        
        sort(v.begin(),v.end());
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<v.size();i++){
            int no=v[i][0];
            int x=v[i][1];
            int y=v[i][2];
            
            if(mp[x].count(y)==1){
                
                int val=vis[mp[x][y].first][mp[x][y].second];
                
                vis[x][y]=val;
                
                rowMax[x]=max(rowMax[x],val);
                
                colMax[y]=max(colMax[y],val);
                
                continue;
                
            }
            
           int val=1;
            
           rnc[x][no]--;
            
           cnc[y][no]--;
            
            if(rnc[x][no]>0 || cnc[y][no]>0){
            
                
        vector<bool>row(n,false);
                
        
        vector<bool>col(m,false);
                
//                 row.resize(n,false);
                
//                 col.resize(m,false);
            
       //      cout<<no<<endl;
                
                dfs(no,x,y,x,y,val,mat,row,col);
              
            }
            
            
            else
                 val=max(val,max(rowMax[x],colMax[y])+1);
                        
            vis[x][y]=val;
             
                rowMax[x]=max(rowMax[x],val);
                
                colMax[y]=max(colMax[y],val);
          
            
        }
        
        return vis;
    }
    
    
    void dfs(int no,int x,int y,int X,int Y,int &val,vector<vector<int>>&mat,vector<bool>&row,vector<bool>&col){
        
        if((row[x]==false)){
            
            row[x]=true;
                    
           // cout<<x<<endl;
            
            for(int j=0;j<m;j++){
               if(mat[x][j]==no){
                    rnc[x][no]--;
                    cnc[j][no]--;
                   mp[x][j]={X,Y};
                   val=max(val,max(rowMax[x],colMax[j])+1);
                   if(cnc[j][no]>0 && (col[j]==false))
                   dfs(no,x,j,X,Y,val,mat,row,col);
                   
               } 
            }
       }
        
        if((col[y]==false)){
            
            col[y]=true;
                        
            for(int i=0;i<n;i++){
              if(mat[i][y]==no){
                  cnc[y][no]--;
                  rnc[i][no]--;
                  mp[i][y]={X,Y};
                  val=max(val,max(rowMax[i],colMax[y])+1);
                  if(rnc[i][no]>0 && (row[i]==false))
                 dfs(no,i,y,X,Y,val,mat,row,col); 
            
             }    
          }
       }
    }
  
};