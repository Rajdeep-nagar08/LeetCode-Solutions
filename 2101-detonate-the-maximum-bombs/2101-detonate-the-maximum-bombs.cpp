#define lln long long int
class Solution {
  int mx=INT_MIN;
  queue<int>q;

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        
      int n=bombs.size();
      
      for(int i=0;i<n;i++){
         bfs(i,bombs);
      }
      
      return mx;
    }
  
      void bfs(int i, vector<vector<int>>& bombs){
          int n=bombs.size();
        vector<bool>vis(n,false);
        
         lln x1,y1,r1,x2,y2,r2;
          q.push(i);
          vis[i]=true;
        
         int count=1;
        
        while(!q.empty()){
    
          int j=q.front();
          vis[j]=true;
          q.pop();
          
          for(int k=0;k<n;k++){
            if(vis[k]==true)
              continue;
            
      x1=bombs[j][0],y1=bombs[j][1],r1=bombs[j][2];
      x2=bombs[k][0],y2=bombs[k][1],r2=bombs[k][2];
          
            if(r1 >= sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)) ) {
              vis[k]=true;
               q.push(k);
              count++;
          }
        }
          
      }
               
       mx=max(mx,count);
    }
};