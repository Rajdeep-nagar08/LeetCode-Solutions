int dx[4]={1,-1,0,0};

int dy[4]={0,0,1,-1};

class Solution {
public:
    int n,m;
    int largestIsland(vector<vector<int>>& grid) {
        
        
        n=grid.size();
        
        
        m=grid[0].size();
        
        int mx=INT_MIN;
        
        
        vector<vector<pair<int,int>>>grid1(n,vector<pair<int,int>>(m));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid1[i][j]={grid[i][j],0};
            }
        }
        
        
        int p=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
             int count=0;
            
             if(grid1[i][j].first==1){
                dfs1(i,j,count,grid1);
                p++;
                dfs2(i,j,count,grid1,p);
                 
                 mx=max(mx,count);
              }
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid1[i][j].first==0){
                    
                    int a=0,p1=-1;
                    int b=0,p2=-1;
                    int c=0,p3=-1;
                    int d=0,p4=-1;
                    
                    for(int i1=0;i1<4;i1++){
                        int x1=i+dx[i1];
                        int y1=j+dy[i1];
                        
            if(x1>=0 && x1<n && y1>=0 && y1<m && (grid1[x1][y1].first!=0)){
                 
                int cnt=grid1[x1][y1].first;
                int val=grid1[x1][y1].second;
                
               // cout<<val<<endl;
                
                        if(a==0){
                            a=cnt;
                            p1=val;
                        }
                       
                else if(p1!=val && (b==0)){
                         b=cnt;
                         p2=val;
                     }
                
          else if((p1!=val) && (p2!=val) && (c==0)){
              
                c=cnt;
                p3=val;
                    
                }
                
         else if((p1!=val) && (p2!=val) && (p3!=val) && (d==0)){
             
             d=cnt;
             p4=val;
         }
                  
                  }
                    
                }
                    
           //  cout<<i<<" "<<j<<" "<<a<<" "<<b<<" "<<" "<<c<<" "<<d<<endl;
              mx=max(mx,a+b+c+d+1);
                    
                }
               
                
            }
        }
        
        return mx;
        
        
    }
    
    
    void dfs1(int i,int j,int &count,vector<vector<pair<int,int>>>&grid1){
        count++;
        grid1[i][j].first=-1;
        for(int x=0;x<4;x++){
            int x1=i+dx[x];
            int y1=j+dy[x];
            if(x1>=0 && x1<n && y1>=0 && y1<m && (grid1[x1][y1].first==1)){
                dfs1(x1,y1,count,grid1);
            }
        }
    }
    
    
void dfs2(int i,int j,int &count,vector<vector<pair<int,int>>>&grid1,int &p){
        grid1[i][j].first=count;
        grid1[i][j].second=p;
        for(int x=0;x<4;x++){
            int x1=i+dx[x];
            int y1=j+dy[x];
            if(x1>=0 && x1<n && y1>=0 && y1<m && (grid1[x1][y1].first==-1)){
                dfs2(x1,y1,count,grid1,p);
            }
        }
    }
};