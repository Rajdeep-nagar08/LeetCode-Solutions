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
        
        
// (u) => (v) directly connected to u, Xor of all values from v's side
        
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
                
        // if both the edges are adjacent, shared any common vertex
                
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
                
     // if edges are not adjacent , try to find two vertices (c1,c2) one from each edge that will be part of single component after breaking down the graph into 3 parts
                
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
                    
    
         //   cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<c1<<" "<<c2<<" "<<x1<<" "<<x2<<" "<<x3<<endl;
              
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