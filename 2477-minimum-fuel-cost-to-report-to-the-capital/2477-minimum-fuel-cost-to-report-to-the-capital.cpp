#define lln long long int

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int n=roads.size();
        
        vector<int>g[n+1];
        
        vector<int>deg(n+1,0);
        
        for(auto it:roads){
            
            g[it[0]].push_back(it[1]);
                        
            deg[it[0]]++;
            
            deg[it[1]]++;
            
            g[it[1]].push_back(it[0]);
            
        }
     
    vector<int>dist=find(g,n+1);

    unordered_map<int,int>mp;

        for(int i=0;i<=n;i++){
            mp[i]++;
        }
        
       lln ans=0;
        
        queue<int>q;
                        
        for(int i=0;i<=n;i++){
            
            if((deg[i]==1) && (i!=0)){
                
                q.push(i);
                
                deg[i]--;
                
        }}
        
        
        while(!q.empty()){
            
            int node=q.front();
                        
            q.pop();
            
            for(int i:g[node]){
                                
                if(deg[i]==0)
                    continue;

                    ans+=1ll*(mp[node]/seats)*dist[node];
                    mp[node]=mp[node]%seats;
                    if(mp[node]>0){
                        ans++;
                    mp[i]+=mp[node];
                    }
                
                
                deg[i]--;
                                
                if(deg[i]==1 && (i!=0)){

                    deg[i]--;
                    
                    q.push(i);
                    
                }
            }
            
        }
    
        return ans;    
    }
    
    
    vector<int> find(vector<int>g[],int n){
                
        vector<int>dist(n,0);
        
        vector<int>vis(n,false);
        
        dist[0]=0;
        
        vis[0]=true;
        
        queue<int>q;
        
        q.push(0);
        
        int d=0;
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                int node=q.front();
                
                q.pop();
                
                dist[node]=d;
                
                for(int y:g[node]){
                    
                    if(vis[y])
                        continue;
                    
                    vis[y]=true;
                    
                    q.push(y);
                }
                
            }
            
            d++;
            
        }
        
        return dist;
    }
};