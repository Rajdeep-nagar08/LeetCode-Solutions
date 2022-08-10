int dx[4]={1,-1,0,0};

int dy[4]={0,0,1,-1};

class Solution {
public:
    
    int n,m;
    
    int startX,startY;

    int shortestPathAllKeys(vector<string>& grid) {
        
        n=grid.size();
        
        m=grid[0].size();
        
        // storing indexes of all keys
        
        vector<vector<int>>keys;
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]=='@'){
                    startX=i;
                    startY=j;
                    continue;
                    
                }
                
                
                if(grid[i][j]=='.' || grid[i][j]=='#')
                    continue;
                
                if(islower(grid[i][j])){
                    keys.push_back({i,j});
                }
            }
        }
        
        
        
        int sz=keys.size();
                
        vector<int>order;;
        
        for(int i=0;i<sz;i++){
            order.push_back(i);
        }
        
        // storing all possible orders to search keys
        
        vector<vector<int>>allorder;
        
        do{
            allorder.push_back(order);
        
        }while(next_permutation(order.begin(),order.end()));
    
                
        int ans=INT_MAX;
        
        for(auto v1:allorder){
            
            int step=0; 
            // steps taken to follow this order of finding keys
            
            unordered_map<char,int>mp;  // to store already searched keys so that we can open the lock if we have its key
            
            int sx=startX,sy=startY;

            for(int i=0;i<v1.size();i++){
                
                int idx=v1[i];
                int nx=keys[idx][0];
                int ny=keys[idx][1];
                
                
                bool flag=false; 
                
                int st=0;
                
                if(mp.count(grid[nx][ny])==1)
                    continue;
                
                bfs(sx,sy,nx,ny,st,mp,flag,grid);
                
           //     cout<<sx<<" "<<sy<<" "<<nx<<" "<<ny<<" "<<st<<endl;

                if(flag){
                    step+=st;
                    sx=nx;
                    sy=ny;
                    mp[grid[nx][ny]]++;
                }
                else
                    break;
                }
            
            if(mp.size()==sz) // searched all the keys
                ans=min(ans,step);
            
        }

         if(ans==INT_MAX)
             return -1;
        
        return ans;
        
    }
    
    //                 bfs(sz,sy,nx,ny,step,mp);
   
      void bfs(int &sx,int &sy,int nx,int ny,int &step,unordered_map<char,int>&mp,bool &flag,vector<string>&grid){
          
          queue<pair<int,int>>q;
          
          vector<vector<bool>>vis(n,vector<bool>(m,false));
          
          vis[sx][sy]=true;
          
          q.push({sx,sy});
          
          while(!q.empty()){
              
              int sz=q.size();
              
              bool flag2=false;   // key found in this level or not
              
              while(sz--){
                  
                  pair<int,int>p=q.front();
                  
                  q.pop();
                  
                  int x=p.first;
                  
                  int y=p.second;
                  
                  if(x==nx && y==ny){
                     // cout<<step<<endl;
                     flag2=true;
                     flag=true;
                      break;
                  }
                  
                  for(int i=0;i<4;i++){
                      int x1=x+dx[i];
                      int y1=y+dy[i];
                      
    if(x1>=0 && y1>=0 && x1<n && y1<m && vis[x1][y1]==false && grid[x1][y1]!='#'){
                    
                        if(grid[x1][y1]=='.'){  // empty cell
                            
                            q.push({x1,y1});
                            vis[x1][y1]=true;
                            
                        }
                    else if(isupper(grid[x1][y1])){  // lock
                      char ch=tolower(grid[x1][y1]);
                        
                        if(mp.count(ch)==1){  
                            q.push({x1,y1});
                            vis[x1][y1]=true;
                        }
                    }
        
                    else if(grid[x1][y1]=='@'){
                            q.push({x1,y1});
                            vis[x1][y1]=true;  
                    }
                    
                    else{                        // key
                        q.push({x1,y1});
                         vis[x1][y1]=true;
                    }
                    
                    
                    }
                  }
              }
              
              
              if(flag2)   // key founds
                  break;
              
              step++;
              
          }
      }
};