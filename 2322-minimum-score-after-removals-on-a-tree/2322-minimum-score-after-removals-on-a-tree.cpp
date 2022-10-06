/*

Let two edges that we removing are : a------b, c------d

Now there can be two possible cases regarding these two edges

 1.

     If Both the edges are adjacent or shared any common vertex
        
                <
                <
                <
   ^^^^^^^a----(b==c)---d^^^^^^
                <
                <
                <
                
NOTE: ^^^^^^ represents any component of graph
      ------ represent an edge
      b==c means its a common vertex between two edges
                
                
   so if we break a---b and c---d, 3 components formed are:-
   
               <
               <
               <
^^^^^^^a     (b==c)      d^^^^^^
               <
               <
               <
               
  
  if total xor = x4 (xor of all vertices)
  
  xor of 1st component=x1=x4^(xor comes from b's side towards a)
  x1=x4^mp[a][b];
  
  xor of third component=x3=x4^(xor comes from c's side towards d)
  x3=x4^mp[d][c];
  
  xor of second component=x2=x4^x1^x3
  
  So
  
  ans= min(ans,max({x1,x2,x3})-min({x1,x2,x3}))
  
  
  2.
  
   if two edges are not adjacent , try to find two vertices (c1,c2), one from each edge, that will be part of single component after breaking down the graph into 3 components
                
    ^^^^^a----b^^^^^^^^^^^c-d^^^^^ than , c1=b , c2=c
    
    HOW to find c1=b and c2=c ?
    
    NOTE: distance of b from c < distance of a from c
          distance of b from c < distance of b from d
          
So in O(n*n) we precalculate the distance of each node from all other nodes
                
 Now if we remove the edges a----b and c----d 
 than 3 components formed are 
 ^^^^^a     b^^^^^^^^c    d^^^^^^^
 
 if xor of all nodes = x4
 
 xor of 1st component= x1 = x4^(xor comes from b's side towards a)
 x1= x4^(mp[a][b])
 
 xor of 3rd component = x3 = x4^(xor comes from c's side towards d)
 x3=x4^(mp[d][c])
 
 xor of 2nd component = x2=x4^x1^x3
 
  */
  

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& e) {
        
        
        int n=nums.size();
        
        vector<int>g[n];
        
        vector<int>indg(n,0);
        
        for(auto it:e){
            
            g[it[0]].push_back(it[1]);
            
            g[it[1]].push_back(it[0]);
            
            indg[it[0]]++;
            
            indg[it[1]]++;

        }
        
        
        // xor of all numbers
        
        int x4=nums[0];
        
        for(int i=1;i<n;i++){
            x4=nums[i]^x4;
        }
        
        
// (u) => (v) directed connected to v, Xor of all values from v's side
        
        unordered_map<int,unordered_map<int,int>>mp1;
        
        
        
        for(int i=0;i<n;i++){
                        
            unordered_map<int,int>mp2;
            
            for(int x:g[i]){
                
                int xr=nums[x];
                
                vector<bool>vis(n,false);
                
                vis[i]=true;
                
                vis[x]=true;
                
                dfs(x,xr,vis,g,nums);
                
                mp2[x]=xr;
                
            }
            
            mp1[i]=mp2;
             
        }
        
// finding distance of each node from all other nodes
        
        vector<vector<int>>dist(n,vector<int>(n));

     for(int i=0;i<n;i++){
         vector<int>d(n);
        bfs(i,d,g);
         dist[i]=d;
     }
        

// For each pair of edges
        
        int ans=INT_MAX;
        
        for(int i=0;i<n-1;i++){
            
            for(int j=i+1;j<n-1;j++){
                
                int a=e[i][0];
                int b=e[i][1];
                
                
                int c=e[j][0];
                int d=e[j][1];
                
       
                
                int x1,x2,x3;
                
                if(a==c){
                  x1= x4^mp1[b][a];
                  x2=x4^mp1[d][a];
                  x3=x4^x1^x2;
                }
                else if(a==d){
                 x1= x4^mp1[b][a];
                  x2=x4^mp1[c][a];
                  x3=x4^x1^x2;
                }
                else if(b==c){
                  x1= x4^mp1[a][b];
                  x2=x4^mp1[d][b];
                  x3=x4^x1^x2;
                }
                else if(b==d){
                    
                  x1= x4^mp1[a][b];
                  x2=x4^mp1[c][b];
                  x3=x4^x1^x2;
                }
                
                else{
                    
                    int c1,c2;
                    
                    int d1=dist[a][c];
                    int d2=dist[a][d];
                    
                    int d3=dist[b][c];
                    int d4=dist[b][d];
               
                    if(d1<d3){
                        c1=a;
                        if(d1<d2)
                            c2=c;
                        else
                            c2=d;
                    }
                    else{
                        c1=b;
                        if(d3<d4)
                            c2=c;
                        else
                            c2=d;
                    }
                    
                    
                     if(c1==a){
                        
                        if(c2==c){  
                            x1=x4^mp1[b][a];
                            x2=x4^mp1[d][c];
                            x3=x4^x1^x2;
                        }
                        else if(c2==d){
                            x1=x4^mp1[b][a];
                            x2=x4^mp1[c][d];
                            x3=x4^x1^x2; 
                        }
                    }
                    else if(c1==b){
                        
                        if(c2==c){
                            x1=x4^mp1[a][b];
                            x2=x4^mp1[d][c];
                            x3=x4^x1^x2;
                        }
                        else if(c2==d){
                            x1=x4^mp1[a][b];
                            x2=x4^mp1[c][d];
                            x3=x4^x1^x2;
                        }
                     }
                    
                  }
                
                
                int mx=max({x1,x2,x3});
                
                int mn=min({x1,x2,x3});
                
                ans=min(ans,mx-mn);
                
            }
        }
        
    
        return ans;
        
        
        
    }
    

void dfs(int u,int& xr,vector<bool>&vis,vector<int>g[],vector<int>&nums){
                  
         for(int v:g[u]){
             if(vis[v]==false){
                 vis[v]=true;
                 xr=xr^nums[v];
                 dfs(v,xr,vis,g,nums);
             }
         }
     }
    

void bfs(int node,vector<int>&d,vector<int>g[]){
    
    int n=d.size();
    
    queue<int>q;
    
    vector<int>vis(n,false);
    
    q.push(node);
    
    int d1=0;
    
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            int u=q.front();
            q.pop();
            d[u]=d1;
            for(int v:g[u]){
                if(vis[v]==false){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        d1++;
    }
    
}
    
};


// T.C = O(n*n)
// S.C = O(n*n)