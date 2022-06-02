  /*
        
         after t moves , frog will should be at position target
         
         if frog reached at target node before t moves than there should be no node under target node otherwise frog will jum downward in extra moves and never return back to target node
         
        after t moves, if frog not reaches the target Than ans=0
        
        after t moves , if frog reaches at target node
        than probability = p1*p2*p3*...pt
        
 where p1=probability of 1st move = 1/(no of unvisited vertices connected to this node = outdegree of this node)
 
        p2=probablility of second move
        
        p3=probability of third move
        
        .
        .
        .
        

so first we needs to find the path till target node

all vertices are unique

        */
        
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    
        vector<int>g[n+1];
        
        
        for(auto it:edges){
            
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);


        }
        
       vector<double>out(n+1,0.00000);  // store outdegree of each vrtx

        queue<pair<int,vector<int>>>q;
        
        vector<bool>vis(n+1,false);
        
        q.push({1,{1}});
        
        vis[1]=true;
        
        int x;
        vector<int>v;
        
        vector<int>path;
        
        while(!q.empty()){
            int sz=q.size();
            bool f=false;
            while(sz--){
                pair<int,vector<int>>p=q.front();
                q.pop();
                x=p.first;
                v=p.second;
                if(x==target){
                    f=true;
                    path=v;
                }
                for(int y:g[x]){
                    if(vis[y]==false){
                        out[x]++;
                        vis[y]=true;
                    vector<int>v1=v;
                    v1.push_back(y);
                    q.push({y,v1});
                        
                    }
                }
                
            }
        }
      
        int c=path.size();

        if(c==0 || c-1>t)
            return 0.00000;
        
        
 //if needs to perform extra jumps as compared to required jumps than there shoukd not be any nodes under target node , or outdegree of tarfet node should be 0
        if(c-1 < t){  
            if(out[target]>0.00000)
                return 0.00000;
        }
        
        if(path[c-1]!=target)  // target node not present
            return 0.00000;
        
        double ans=1.00000;
        
        for(int i=0;i<=c-2;i++){
            
            double move=(double)(out[path[i]]*1.00000);
                    
            double probMove=((double)1.00000/(double)move);
                    
            ans=(double)ans*probMove;
                        
        }
        
         return ans;
    }
};